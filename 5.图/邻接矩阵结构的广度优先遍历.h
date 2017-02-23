typedef int Boolean;
Boolean visited[MAX];								/* 访问标志数组 */
/* 邻接矩阵的广度优先遍历算法*/
void BFSTraverse(MGraph G)
{
	int i, j;
	Queue Q;										/* 辅助队列 */
	for(i = 0; i < G.numVertexes; i++)
	{
		visited[i] = FALSE;
	}
	InitQueue(&Q);									/* 初始化辅助队列 */
	for(i = 0; i < G.numVertexes; i++)				/* 对每一个顶点做循环 */
	{
		if (!visited[i]) 							/* 若是未访问过就处理 */
		{
			visited[i] = TRUE;						/* 设置当前顶点访问过 */
			printf("%c ", G.vexs[i]);				/* 打印顶点数据，或进行其他操作 */
			EnQueue(&Q, i);							/* 将此顶点入队 */
			while (!QueueEmpty(Q)) {				/* 若当前队列不为空 */
				DeQueue(&Q, &i);					/* 将队列中元素出队，赋值给 i */
				for(j = 0; j < G.numVertexes; j++)
				{
					/* 判断其他顶点若与当前顶点存在边且未访问过 */
					if (G.arc[i][j] == 1 && !visited[j]) 
					{
						visited[j] = TRUE;			/* 将找到的此顶点标记为已访问过 */
						printf("%c ", G.vexs[j]);	/* 打印顶点数据，或进行其他操作 */
						EnQueue(&Q, j);				/* 将找到的此顶点入队 */
					}
				} 
			}
		}
	}
}