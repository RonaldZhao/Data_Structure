/*
中序遍历的非递归实现
基本思路：使用堆栈
遇到一个结点，就把它压栈，并去遍历它的左子树；
当左子树遍历结束后，从栈顶弹出这个结点并访问它；
然后按其右指针再去中序遍历该结点的右子树。
*/
void InorderTraversalNonRecursive(BinTree BT)
{
	BinTree T=BT;
	Stack S = CreateStack(MaxSize);	// 创建并初始化堆栈S
	while(T||!IsEmpty(S))
	{
		while(T)	// 一直向左并将沿途结点压入堆栈
		{
			Push(S,T);
			T = T->Left;
		}
		if(!IsEmpty(S))
		{
			T = Pop(S);	// 结点弹出堆栈
			printf("%5d",T->Data);	// 访问结点（在这里是打印）
			T = T->Right;	// 转向右子树
		}
	}
}

// 其他参考：http://www.wengweitao.com/er-cha-shu-de-san-chong-bian-li-fang-shi-di-gui-fei-di-gui-he-morrisbian-li.html