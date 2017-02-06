int PostOrderGetTreeHeight(BinTree BT)
{
	int HL,HR,MaxH;
	if(BT)
	{
		HL = PostOrderGetTreeHeight(BT->Left);	// 求左子树的高度
		HR = PostOrderGetTreeHeight(BT->Right);	// 求右子树的高度
		MaxH = (HL > HR)?HL:HR;	// 取左子树和右子树高度的较大值
		return (MaxH+1);
	}
	return 0;	// 空树深度为 0
}