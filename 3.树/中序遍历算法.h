/* 二叉树的中序遍历递归算法 */
void InOrderTraverse(BiTree T)
{
	if(T == NULL)
		return;
	InOrderTraverse(T->lchild);/* 先中序遍历左子树 */
	printf("%c",T->data);			 /* 再显示结点数据，可以更改为其他对结点的操作 */
	InOrderTraverse(T->rchild);/* 最后中序遍历右子树 */
}