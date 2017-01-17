/* 二叉树的前序遍历递归算法 */
void PreOrderTraverse(BiTree T)
{
	if(T == NULL)
		return;
	printf("%c"T->data);				/* 先显示结点数据，可以更改为其他对结点的操作 */
	PreOrderTraverse(T->lchild);/* 再先序遍历左子树 */
	PreOrderTraverse(T->rchild);/* 最后先序遍历右子树 */
}