// 邻接表的广度遍历算法
void BFSTraverse(GraphAdjList GL)
{
	int i;
	EdgeNode *p;
	Queue Q;
	for(i = 0; i < GL->numVertexes; i++)
		visited[i] = FALSE;
	InitQueue(&Q);
	for(i = 0; i < GL->numVertexes; i++)
	{
		if(!visited[i])
		{
			visited[i] = TRUE;
			printf("%c ",GL->adjList[i].data);
			EnQueue(&Q, i);
			while(!QueueEmpty(Q))
			{
				DeQueue(&Q, &i);
				p = GL->adjList[i].firstedge;
				while(p)
				{
					if(!visited[p->adjvex])
					{
						visited[p->adjvex] = TRUE;
						printf("%c ", GL->adjList[p->adjvex].data);
						EnQueue(&Q, p->adjvex);
					}
					p = p->next;
				}
			}
		}
	}
}