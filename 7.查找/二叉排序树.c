// 结构定义
typedef struct BinTNode
{
	int data;
	struct BinTNode *lchild, *rchild;
}BinTNode, *BinTree;
// 二叉排序树查找实现
// 递归查找二叉排序树中是否存在key，
// 指针f指向T的双亲，其初始调用值为NULL，
// 若查找成功，则指针p指向该数据元素结点，并返回TRUE
// 否则指针p指向查找路径上访问的最后一个结点并返回FALSE
Status SearchBST(BinTree T, int key, BinTree f, BinTree *p)
{
	if(!T)	// 查找不成功
	{
		*p = f;
		return FALSE;
	}
	else if(key == T->data)	// 查找成功
	{
		*p = T;
		return TRUE;
	}
	else if(key < T->data)
		return SearchBST(T->lchild, key, T, p);	// 在左子树中继续查找
	else
		return SearchBST(T->rchild, key, T, p);	// 在右子树中继续查找
}

// 二叉排序树插入操作
// 当二叉排序树T中不存在关键字等于key的数据元素时
// 插入key并返回TRUE，否则返回FALSE
Status InsertBST(BinTree *T, int key)
{
	BinTree p, s;
	if(!SearchBST(*T,key,NULL,&p))	// 查找不成功
	{
		s = (BinTree)malloc(sizeof(BinTNode));
		s->data = key;
		s->lchild = s->rchild = NULL;
		if(!p)
			*T = s;	// 插入s为新的根节点
		else if(key < p->data)
			p->lchild = s;	// 插入s为左孩子
		else
			p->rchild = s;	// 插入s为右孩子
		return TRUE;
	}
	else
		return FALSE;	// 树中已经有key，不再插入
}

// 创建一个二叉排序树的示例代码如下
int i;
int a[10] = {62,88,58,47,35,73,51,99,37,93};
BinTree T = NULL;
for(i = 0; i < 10; i++)
{
	InsertBST(&T, a[i]);
}

// 二叉排序树的删除操作
// 若二叉排序树T中存在关键字等于key的数据元素时，则删除该数据元素的结点，并返回TRUE；否则返回FALSE
Status DeleteBST(BinTree *T, int key)
{
	if(!*T)	// 空树
		return FALSE;
	else
	{
		if(key == (*T)->data)	// 找到关键字等于key的数据元素
			return Delete(T);
		else if(key < (*T)->data)
			return DeleteBST(&(*T)->lchild,key);
		else
			return DeleteBST(&(*T)->rchild,key);
	}
}
// 从二叉树中删除结点p，并重接它的左子树或右子树
Status Delete(BinTree *p)
{
	BinTree q, s;
	if((*p)->rchild == NULL)	// 右子树为空
	{
		q = *p;
		*p = (*p)->lchild;
		free(q);
	}
	else if((*p)->rchild == NULL)	// 左子树为空
	{
		q = *p;
		*p = (*p)->rchild;
		free(q);
	}
	else	// 左右子树都不为空
	{
		q = *p;
		s = (*p)->lchild;
		while(s->rchild)	// 寻找左孩子中的最大值
		{
			q = s;
			s = s->rchild;
		}
		(*p)->data = s->data;
		if(q != *p)
		{
			q->rchild = s->lchild;
		}
		else
			q->lchild = s->lchild;
		free(s);
	}
}