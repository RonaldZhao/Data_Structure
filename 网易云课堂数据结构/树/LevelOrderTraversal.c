/*
���������
	����ʵ�֣�
	�����Ӹ���㿪ʼ�����Ƚ��������ӣ�Ȼ��ʼִ��ѭ����������+���ʸý��+�����Һ������.
*/
void LevelOrderTraversal(BinTree BT)
{
	Queue Q;
	BinTree T;
	if(!BT)	// ���ǿ�����ֱ�ӷ���
		return;
	Q = CreateQueue(MaxSize);	// ��������ʼ������ Q
	AddQ(Q, BT);
	while(!IsEmpty(Q))
	{
		T = DeleteQ(Q);
		printf("%d\n", T->Data);	// ���ʳ��ӵĽ��
		if(T->Left)
			AddQ(Q, T->Left);
		if(T->Right)
			AddQ(Q, T->Right);
	}
}
