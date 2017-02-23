/*
	Prim算法是以某顶点为起点，逐步寻找各顶点上权值最小的边来构建最小生成树的。
*/
// 对边集数组Edge的定义
typedef struct
{
	int begin;
	int end;
	int weight;
}Edge;
// Kruskal算法生成最小生成树
void MinSpanTree_Kruskal(MGraph G)
{
	int i, n, m;
	Edge edges[MAXEDGE];	// 定义边集数组
	int parent[MAXVEX];	// 定义一数组用来判断与边是否形成回路
	// 此处省略将邻接矩阵G转换为边集数组edges并按权由小到大排序的代码
	for(i = 0; i < G.numVertexes; i++)
		parent[i] = 0;	// 初始化数组为0
	for(i = 0; i < G.numEdges; i++)	// 循环每一条边
	{
		n = Find(parent, edges[i].begin);
		m = Find(parent, edges[i].end);
		if(n != m)	// n != m，说明此边没有与现有生成树形成回路
		{
			parent[n] = m;	// 将此边的结尾顶点放入下标为起点的parent中，表示此顶点已经在生成树集合中
			printf("(%d %d) %d ", edges[i].begin, edges[i].end, edges[i].weight);
		}
	}
}// 时间复杂度：O(eloge)，e为边数

int Find(int *parent, int f)	// 查找连线顶点的尾部下标
{
	while(parent[f] > 0)
		f = parent[f];
	return f;
}