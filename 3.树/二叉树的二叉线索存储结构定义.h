/* 二叉树的二叉线索存储结构定义 */
typedef enum {Link,Thread} PointerTag;	/* Link == 0 表示指向左右孩子指针, Thread == 1 表示指向前驱或后继的线索*/
typedef struct BiThrNode				/* 二叉线索存储的结点结构 */
{
	TElemType data;						/* 数据域 */
	struct BiThrNode *lchild,*rchild;	/*左右孩子指针 */
	PointerTag LTag, RTag;				/* 左右标志 */
}BiThrNode,*BiThrTree;