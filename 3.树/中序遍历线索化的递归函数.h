BiThrTree pre;					/* 全局变量，始终指向刚刚访问过的结点 */
/* 中序遍历进行中序线索化 */
void InThreading(BiThrTree p)
{
	if(p)						/* 树 p 非空 */
	{
		InThreading(p->lchild);	/* 递归左子树线索化 */
		/* start */
		if(!p->lchild)			/* 没有左孩子 */
		{
			p->LTag=Thread;		/* 前驱线索 */
			p->lchild=pre;		/* 左孩子指针指向前驱 */
		}
		if(!pre->rchild)		/* 前驱没有右孩子 */
		{
			pre->RTag=Thread;	/* 后继线索 */
			pre->rchild=p;		/* 前驱右孩子指针指向后继(当前结点 p ) */
		}
		pre=p;					/* 保持 pre 指向 p 的前驱 */
		/* end */
		InThreading(p->rchild);	/* 递归右子树线索化 */
	}
}
/*
start:
这之间的代码是做了这样的一些事：
if(!p->lchild) 表示如果某结点的左指针域为空，因为其前驱结点刚刚访问过，赋值给了pre，所以可以将 pre 赋值给p->lchild，
并修改 p->LTag=Thread（也就是定义为Thread）以完成前驱结点的线索化。
后继结点就要稍麻烦一些。因为此时 p 结点的后继还没有访问到，因此只能对它的前驱结点 pre 的右指针 rchild 做判断，if(!pre->rchild) 表示
如果为空，则 p 就是 pre 的后继，于是 pre->rchild=p ，并且设置 pre->RTag=Thread ，完成后继结点的线索化。
最后将当前的结点 p 赋值给 pre ，以便下一次使用。
end;
*/