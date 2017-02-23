/* 建立无向网图的邻接矩阵表示 */
void CreateMGrapg(MGraph *G)
{
	int i,j,k,w;
	printf("输入顶点数和边数：\n");
	scanf("%d,%d"&G->numVertexes,&numEdges);/* 输入顶点数和边数 */
	for (i=0; i<G->numVertexes; i++)		/* 读入顶点信息，建立顶点表 */
	{
		scanf(&G->vesx[i]);
	}
	for(i=0; i<G->numVertexes; i++)
	{
		for(j=0; j<G->numVertexes; j++)
		{
			G->arc[i][j]=INFINITY;			/* 邻接矩阵初始化 */
		}
	}
	for(k=0; k<G->numEdges; k++)			/* 读入numEdges条边，建立邻接矩阵 */
	{
		printf("输入边（vi，vj）上的下标i，下标j和权w：\n");
		scanf("%d,%d,%d",&i,&j,&w);			/* 输入边 (vi,vj) 上的权 w */
		G->arc[i][j]=w;
		G->arc[j][i]=G->arc[i][j];			/* 因为是无向图，矩阵对称 */
	}
}