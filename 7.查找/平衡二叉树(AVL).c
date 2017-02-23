// 平衡二叉树是一种二叉排序树，其中每一个结点的左子树和右子树的高度差至多为1
// 二叉树上结点的左子树深度减去右子树深度的值为平衡因子BF（Balance Factor）
// 所以平衡二叉树上所有结点的BF都只能为-1、0和1
// 距离插入结点最近的，且平衡因子的绝对值大于1的结点为根的子树，称为最小不平衡子树

// 二叉树的二叉链表结点结构定义
typedef struct BiTNode
{
	int data;	// 结点数据
	int bf;	// 平衡因子
	struct BiTNode *lchild, *rchild;	// 左右孩子指针
}BiTNode, *BiTree;

// 对以p为根的二叉排序树做右旋处理
// 处理之后p指向新的树根结点，即旋转之前的左子树的根结点
void R_Rotate(BiTree *p)
{
	BiTree L;
	L = (*p)->lchild;	// L指向p的左子树根结点
	(*p)->lchild = L->rchild;	// L的右子树挂接为p的左子树
	L->rchild = (*p);
	*p = L;	// p指向新的根结点
}

// 对以p为根的二叉排序树做左旋处理
// 处理之后p指向新的树根结点，即旋转之前的右子树的根结点
void L_Rotate(BiTree *p)
{
	BiTree R;
	R = (*p)->rchild;	// R指向p的右子树根结点
	(*p)->rchild = R->lchild;	// R的左子树挂接为p的右子树
	R->lchild = (*p);
	*p = R;	// p指向新的根结点
}

//下面是左右平衡旋转处理的代码
#define LH +1	// 左高
#define EH 0	// 等高
#define RH -1	// 右高
// 对以指针T所指结点为根的二叉树作平衡旋转处理
// 算法结束时，指针T指向新的根结点
void LeftBalance(BiTree *T)	// P363/338
{
	BiTree L, Lr;
	L = (*T)->lchild;
	switch(L->bf)
	{
		case LH:
			(*T)->bf = L->bf = EH;
			R_Rotate(T);
			break;
		case RH:
			Lr = L->rchild;
			switch(Lr->bf)
			{
				case LH:(*T)->bf = RH;
					L->bf = EH;
					break;
				case EH:(*T)->bf = L->bf = EH;
					break;
				case RH:(*T)->bf = EH;
					L->bf = LH;
					break;
			}
			Lr->bf = EH;
			L_Rotate(&(*T)->lchild);
			R_Rotate(T);
	}
}