typedef int Boolean;
Boolean visited[MAX];								/* 访问标志数组 */
/* 邻接表的广度遍历算法 */
void BFSTraverse(GraphAdjList GL)
{
	int i;
	EdgeNode *p;
	Queue Q;										/* 辅助队列 */
	for(i = 0; i < GL->numVertexes; i++)
	{
		visited[i] = FALSE;
	}
	InitQueue(&Q);									/* 初始化辅助队列 */
	for(i = 0; i < GL->numVertexes; i++)			/* 对每一个顶点做循环 */
	{
		if (!visited[i]) 							/* 若是未访问过就处理 */
		{
			visited[i] = TRUE;						/* 设置当前顶点访问过 */
			printf("%c ", GL->adjList[i].data);		/* 打印顶点数据，或进行其他操作 */
			EnQueue(&Q, i);							/* 将此顶点入队 */
			while (!QueueEmpty(Q)) {				/* 若当前队列不为空 */
				DeQueue(&Q, &i);					/* 将队列中元素出队，赋值给 i */
				p = GL->adjList[i].firstedge;		/* 找到当前顶点边表链表头指针 */
				while (p) {
					 if (!visited[p->adjvex]) 		/* 若此顶点未被访问 */
					 {
					 	visited[p->adjvex] = TRUE;
					 	printf("%c ", GL->adjList[p->adjvex].data);
					 	EnQueue(&Q, p->adjvex);		/* 将此顶点入队列 */
					 }
					 p = p->next;					/* 指针指向下一个邻接点 */
				}
			}
		}
	}
}