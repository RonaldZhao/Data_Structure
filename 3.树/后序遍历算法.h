/* 二叉树的后序遍历递归算法 */
void PostOrderTraverse(BiTree T)
{
	if(T == NULL)
		return;
	PostOrderTraverse(T->lchild);/* 先后序遍历左子树 */
	PostOrderTraverse(T->rchild);/* 再后序遍历右子树 */
	printf("%c",T->data);				 /* 最后显示结点数据，可以更改为对结点的其他操作 */
}