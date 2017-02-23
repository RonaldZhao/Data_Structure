// 邻接矩阵的广度优先遍历算法
void BFSTraverse(MGraph G)
{
	int i, j;
	Queue Q;
	for(i = 0; i < G.numVertexes; i++)
		visited[i] = FALSE;
	InitQueue(&Q);	// 初始化一辅助用的队列
	for(i = 0; i < G.numVertexes; i++)
	{
		if(!visited[i])
		{
			visited[i] = TRUE;
			printf("%c ", G.vexs[i]);
			EnQueue(&Q, i);
			while(!QueueEmpty(Q))	// 若当前队列不为空
			{
				DeQueue(&Q, &i);
				for(j = 0; j < G.numVertexes; j++)
				{
					// 判断其它顶点若与当前顶点存在边且未访问过
					if(G.arc[i][j] == 1 && !visited[j])
					{
						visited[j] = TRUE;
						printf("%c ", G.vexs[j]);
						EnQueue(&Q, j);
					}
				}
			}
		}
	}
}