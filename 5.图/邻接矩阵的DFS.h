typedef int Boolean;
Boolean visited[MAX];			/* 访问标志数组 */
/* 邻接矩阵的深度优先递归算法 */
/* 时间复杂度 O(n^2) */
void DFS(MGraph G, int i)
{
	int j;
	visited[i] = TRUE;
	printf("%c ", G.vexs[i]);	/* 打印顶点，也可以进行其他操作 */
	for(j = 0; j < G.numVertexes; j++)
	{
		if(G.arc[i][j] == 1 && !visited[j])
			DFS(G, j);			/* 对未访问的邻接顶点递归调用 */
	}
}
/* 邻接矩阵的深度遍历操作 */
void DFSTraverse(MGrapg G)
{
	int i;
	for(i = 0; i < G.numVertexes; i++)
	{
		visited[i] = FALSE;		/* 初始所有顶点状态都是未访问过状态 */
	}
	for(i = 0; i < G.numVertexes; i++)
	{
		if(!visited[i])			/* 对未访问过的顶点调用DFS，若是连通图，只会执行一次 */
			DFS(G, i);
	}
}