/* 图的邻接矩阵存储结构 */
typedef char VertexType;			/* 定点类型应由用户定义 */
typedef int EdgeType;				/* 边上的权值类型应由用户定义 */
#define MAXVEX 100					/* 最大顶点数，应由用户定义 */
#define INFINITY 65535				/* 用 65535 代表 ∞ */
typedef struct
{
	VertexType vexs[MAXVEX];		/* 顶点表 */
	EdgeType arc[MAXVEX][MAXVEX];	/* 邻接矩阵，可以看做边表 */
	int numVertexes, numEdges;		/*图中当前的顶点数和边数 */
}MGraph;