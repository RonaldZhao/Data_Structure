/*
��������ķǵݹ�ʵ��
����˼·��ʹ�ö�ջ
����һ����㣬�Ͱ���ѹջ����ȥ����������������
�����������������󣬴�ջ�����������㲢��������
Ȼ������ָ����ȥ��������ý�����������
*/
void InorderTraversalNonRecursive(BinTree BT)
{
	BinTree T=BT;
	Stack S = CreateStack(MaxSize);	// ��������ʼ����ջS
	while(T||!IsEmpty(S))
	{
		while(T)	// һֱ���󲢽���;���ѹ���ջ
		{
			Push(S,T);
			T = T->Left;
		}
		if(!IsEmpty(S))
		{
			T = Pop(S);	// ��㵯����ջ
			printf("%5d",T->Data);	// ���ʽ�㣨�������Ǵ�ӡ��
			T = T->Right;	// ת��������
		}
	}
}

// �����ο���http://www.wengweitao.com/er-cha-shu-de-san-chong-bian-li-fang-shi-di-gui-fei-di-gui-he-morrisbian-li.html