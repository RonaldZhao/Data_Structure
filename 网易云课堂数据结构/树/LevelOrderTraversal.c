/*
层序遍历：
	队列实现：
	遍历从根结点开始，首先将根结点入队，然后开始执行循环：结点出队+访问该结点+其左右孩子入队.
*/
void LevelOrderTraversal(BinTree BT)
{
	Queue Q;
	BinTree T;
	if(!BT)	// 若是空树则直接返回
		return;
	Q = CreateQueue(MaxSize);	// 创建并初始化队列 Q
	AddQ(Q, BT);
	while(!IsEmpty(Q))
	{
		T = DeleteQ(Q);
		printf("%d\n", T->Data);	// 访问出队的结点
		if(T->Left)
			AddQ(Q, T->Left);
		if(T->Right)
			AddQ(Q, T->Right);
	}
}
