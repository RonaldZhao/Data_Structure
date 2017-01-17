/* 无向图的邻接表结构创建 */
/* 时间复杂度 O(n+e) */
void CreateALGraph(GraphAdjList *G)
{
	int i, j, k;
	EdgeNode *e;
	printf("输入顶点数和边数：\n");
	scanf("%d,%d", &G->numVertexes, &G->numEdges);	/* 输入顶点数和边数 */
	for(i = 0;i < G->numVertexes; i++)				/* 读入顶点信息，建立顶点表 */
	{
		scanf(&G->adjList[i].data);					/* 输入顶点信息 */
		G->adjList[i].firstedge = NULL;				/* 将边表初始为空表 */
	}
	for(k = 0; k < G->numEdges; k++)				/* 建立边表 */
	{
		printf("输入边 (vi, vj) 上的顶点序号：\n");
		scanf("%d,%d", &i, &j);						/* 输入边 (vi, vj) 上的顶点序号 */
		e = (EdgeNode*)malloc(sizeof(EdgeNode));	/* 向内存申请空间，生成边表结点 */
		e->adjvex = j;								/* 邻接序号为 j */
		e->next = G->adjList[i].firstedge;			/* 将 e 指针指向当前顶点指向的结点 */
		G->adjList[i].firstedge = e;				/* 将当前顶点的指针指向 e */
		e = (EdgeNode*)malloc(sizeof(EdgeNode));	/* 向内存申请空间，生成边表结点 */
		e->adjvex = i;								/* 邻接序号为 i */
		e->next = G->adjList[j].firstedge;			/* 将 e 指针指向当前顶点指向的结点 */
		G->adjList[j].firstedge = e;				/* 将当前顶点的指针指向 e */
	}
}
