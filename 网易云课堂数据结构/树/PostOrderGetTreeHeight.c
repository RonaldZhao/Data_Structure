int PostOrderGetTreeHeight(BinTree BT)
{
	int HL,HR,MaxH;
	if(BT)
	{
		HL = PostOrderGetTreeHeight(BT->Left);	// ���������ĸ߶�
		HR = PostOrderGetTreeHeight(BT->Right);	// ���������ĸ߶�
		MaxH = (HL > HR)?HL:HR;	// ȡ���������������߶ȵĽϴ�ֵ
		return (MaxH+1);
	}
	return 0;	// �������Ϊ 0
}