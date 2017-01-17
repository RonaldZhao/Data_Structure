typedef int Boolean;
Boolean visited[MAX];					/* 访问标志数组 */
/* 邻接表的深度优先递归算法 */
/* 时间复杂度 O(n+e) */
void DFS(GraphAdjList GL, int i)
{
	EdgeNode *p;
	visited[i] = TRUE;
	printf("%c ", GL->adjList[i].data);	/* 打印顶点，或进行其他操作 */
	p = GL->adjList[i].firstedge;
	while(p)
	{
		if(!visited[p->adjvex])
			DFS(GL, p->adjvex);			/* 对未访问的邻接顶点递归调用 */
		p = p->next;
	}
}
/* 邻接表的深度遍历操作 */
void DFSTraverse(GraphAdjList GL)
{
	int i;
	for(i = 0; i < GL->numVertexes; i++)
	{
		visited[i] = FALSE;				/* 初始所有顶点状态都是未访问过状态 */
	}
	for(i = 0; i < GL->numVertexes; i++)
	{
		if(!visited[i])					/* 对未访问过的顶点调用DFS，若是连通图，只会执行一次 */
			DFS(GL, i);
	}
}