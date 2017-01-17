/* 树的孩子表示法结构定义 */
#define MAX_TREE_SIZE 100
typedef int TElemType;						/* 树结点的数据类型，目前暂定为整型 */
typedef struct CTNode							/* 孩子链表的孩子结点 */
{
	int child;											/* 数据域，用来存储某个结点在表头数组中的下标 */
	struct CTNode *next;						/* 指针域，用 来存储指向某结点的下一个孩子结点的指针 */
}*ChildPtr;
typedef struct										/* 表头数组的表头结点 */
{
	TElemType data;									/* 数据域，存储某结点的数据信息 */
	ChildPtr firstchild;						/* 头指针域，存储该结点的孩子链表的头指针 */
}CTBox;
typedef struct										/* 树结构 */
{
	CTBox nodes[MAX_TREE_SIZE];			/* 结点数组 */
	int r,n;												/* 根的位置和结点数 */
}CTree;