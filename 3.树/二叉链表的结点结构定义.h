/* 二叉链袤的结点结构定义 */
typedef struct BiTNode						/* 结点结构 */
{
	TElemType data;									/* 数据域 */
	struct BiTNode *lchild,*rchild;	/* 指针域，分别指向左右孩子 */
}BiTNode, *BiTree;