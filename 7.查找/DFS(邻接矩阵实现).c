typedef int Boolean;
Boolean visited[MAX];

// 邻接矩阵的深度优先递归算法
void DFS(MGraph G, int i)
{
	int j;
	visited[i] = TRUE;
	printf("%c ", G.vexs[i]);
	for(j = 0; j < G.numVertexes; j++)
		if(G.arc[i][j] == 1 && !visited[j])
			DFS(G, j);
}

// 邻接矩阵的深度优先遍历操作
void DFSTraverse(MGraph G)
{
	int i;
	for(i = 0; i < G.numVertexes; i++)
		if(!visited[i])
			DFS(G, i);
}