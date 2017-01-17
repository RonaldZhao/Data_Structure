/* T指向头结点，头结点左键 lchild 指向根结点，头结点右键 rchild 指向中序遍历的最后一个结点 */
/* 中序遍历二叉线索链表表示的二叉树 T */
Status InOrderTraverse_Thr(BiThrTree T)
{
	BiThrTree p;
	p = T->lchild;					/* p 指向根节点 */
	while (p != T) {				/* 空树或遍历结束时，p == T */
		while (p->LTag == Link) {	/* 当LTag == 0 时循环到中序序列第一个结点 */
			p = p->lchild; 
		} 
		printf("%c",p->data);		/* 显示结点数据，可以更改为其他对结点的操作 */
		while (p->RTag == Thread && p->rchild != T) {
			p = p->rchild;
			printf("%c",p->data); 
		}
		p = p->rchild;				/* p 进至其右子树根 */
	}
	return OK;
}