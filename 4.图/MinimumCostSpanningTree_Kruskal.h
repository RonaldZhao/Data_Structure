/* Kruskal 算法生成最小生成树 */
void MiniSpanTree_Kruskal(MGraph G)	/* 生成最小生成树 */
{
	int i, m, n;
	Edge edges[MAXEDGE];					/* 定义边集数组 */
	int parent[MAXVEX];						/* 定义一维数组用来判断边与边是否形成环路 */
	/* 此处省略将邻接矩阵 G 转化为边集数组 edges 并按权由小到大排序的代码 */
	for(i = 0; i < G.numVertexes; i++)
	{
		parent[i] = 0;						/* 初始化数组值为 0 */
	}
	for(i = 0; i < G.numEdges; i++)			/* 循环每一条边 */
	{
		n = Find(parent, edges[i], begin);
		m = Find(parent, edges[i], end);
		if(n != m)							/* 假如 n 与 m 不相等，说明此边没有与现有生成树形成环路 */
		{
			parent[n] = m;					/* 将此边的结尾顶点放入下标为起点的 parent 中，表示此顶点已经在生成树集合中 */
			printf("(%d,%d) %d", edges[i].begin, edges[i].end, edges[i].weight);
		}
	}
}
int Find(int *parent, int f)				/* 查找连线顶点的尾部下标 */
{
	while (parent[f] > 0) {
		f = parent[f]; 
	}
	return f;
}
/* P278-P281 */