typedef char VertexType;	/* 顶点类型，应由用户定义 */
typedef int EdgeType;		/* 边上的权值类型，应由用户定义 */

typedef struct EdgeNode		/* 边表结构 */
{
	int adjvex;				/* 邻接点域，存储该顶点对应的下标 */
	EdgeType weight;		/* 用于存储权值，对于非网图可以没有 */
	struct EdgeNode *next;	/* 链域，指向下一个邻接点 */
}EdgeNode;

typedef struct VertexNode	/* 顶点表结构 */
{
	VertexType data;		/* 顶点域，存储顶点信息 */
	EdgeNode *firstedge;	/* 边表头指针 */
}VertexNode,AdjList[MAXVEX];

typedef struct
{
	AdjList adjList;
	int numVertexes,numEdges;/* 图中当前顶点数和边数 */
}