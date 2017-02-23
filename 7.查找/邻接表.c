typedef cahr VertexType;
typedef int EdgeType;

typedef struct EdgeNode	// 边表结点
{
	int adjvex;	// 邻接点域，存储该顶点对应的下标
	EdgeType weight;
	struct EdgeNode *next;
}EdgeNode;

typedef struct VertexNode	// 顶点表结点
{
	VertexType data;
	EdgeNode *firstedge;
}VertexNode, AdjList[MAXVEX];

typedef struct
{
	AdjList adjList;
	int numVertexes, numEdges;	// 图中当前顶点数和边数
}GraphAdjList;

// 建立图的邻接表结构
void CreateALGraph(GraphAdjList *G)
{
	int i, j, k;
	EdgeNode *e;
	printf("输入顶点数和边数：\n");
	scanf("%d %d", &G->numVertexes, &G->numEdges);
	for(i = 0; i < G->numVertexes; i++)
	{
		scanf(&G->adjList[i].data);	// 输入顶点信息
		G->adjList[i].firstedge = NULL;	// 将边表置为空表
	}
	for(k = 0; k < G->numEdges; k++)	// 建立边表
	{
		printf("输入边(vi, vj)上的顶点序号：\n");
		scanf("%d %d", &i, &j);	// 输入边(vi, vj)上的顶点序号
		// 向内存申请空间，生成边表结点
		e = (EdgeNode *)malloc(sizeof(EdgeNode));
		e->adjvex = j;	// 邻接序号为j
		// 将e指针指向当前顶点指向的结点
		e->next = G->adjList[i].firstedge;
		G->adjList[i].firstedge = e;	// 将当前顶点的指针指向e
		// 向内存申请空间，生成边表结点
		e = (EdgeNode *)malloc(sizeof(EdgeNode));
		e->adjvex = i;	// 邻接序号为i
		// 将e指针指向当前顶点指向的结点
		e->next = G->adjList[j].firstedge;
		G->adjList[j].firstedge = e;	// 将当前顶点的指针指向e
	}
}
/*
  以上实现方式应用了在单链表创建中的头插法，由于对于无向图，一条边对应的
  都是两个顶点，所以在循环中，一次就针对i和j分别进行了插入。
  此算法的时间复杂度，对于n个顶点e条边来说是O(n+e)
*/