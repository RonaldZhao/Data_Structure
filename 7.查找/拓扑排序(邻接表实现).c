// 所谓拓扑排序，就是对有向图构造拓扑序列的过程
typedef struct EdgeNode	// 边表结构
{
	int adjvex;	// 邻接点域，用于存储该顶点对应的下标
	int weight;	// 用于存储权值，对于非网图可以不要
	struct EdgeNode *next;	// 链域，指向下一个邻接点
}EdgeNode;

typedef struct VertexNode	// 顶点表结构
{
	int in;	// 顶点入度
	int data;	// 顶点域，存储顶点信息
	EdgeNode *firstedge;	// 边表头指针
}VertexNode, AdjList[MAXVEX];

typedef struct
{
	AdjList adjList;
	int numVertexes, numEdges;	// 当前顶点数和边数
}graphAdjList, *GraphAdjList;
/*
  在算法中还需要一辅助数据结构————栈，用来存储处理过程中入度为0的顶点，目的是为了避免每个查找时都要去遍历顶点表
  找有没有入度为0的顶点。
*/
// 拓扑排序，若GL无回路，则输出拓扑排序序列并返回OK；若有回路则返回ERROR。
Status TopologicalSort(GraphAdjList GL)
{
	EdgeNode *e;
	int i, k, gettop;
	int top = 0;	// 用于栈指针下标
	int count = 0;	// 用于统计输出顶点的个数
	int *stack;	// 建栈存储入度为0的顶点
	stack = (int *)malloc(sizeof(int)*GL->numVertexes);
	for(i = 0; i < GL->numVertexes; i++)
		if(GL->adjList[i].in == 0)
			stack[++top] = i;	// 将入度为0的顶点入栈
	while(top != 0)
	{
		gettop = stack[top--];	// 出栈
		printf("%d -> ", GL->adjList[gettop].data);
		count++;	// 统计输出个数
		for(e = GL->adjList[gettop].firstedge; e; e = e->next)
		{// 对此顶点弧表遍历
			k = e->adjvex;
			if(!(--GL->adjList[k].in))	// 将k号顶点邻接点的入度减1
				stack[++top] = k;	// 若为则入栈，以便下次循环输出
		}
	}
	if(count < GL->numVertexes)	// 如果count小于顶点数，说明存在环
		return ERROR;
	else
		return OK;
}