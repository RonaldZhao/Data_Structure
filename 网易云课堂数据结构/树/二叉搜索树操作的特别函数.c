Position Find(ElementType X, BinTree BST)
{
	if(!BST)	// ����ʧ��
		return NULL;
	if(X > BST->Data)
		return Find(X, BST->Right);	// ���������м�������
	else if(X < BST->Data)
		return Find(X, BST->Left);	// ���������м�������
	else
		return BST;	// ���ҳɹ��������ҵ��Ľ��ĵ�ַ
}

// ���ڷǵݹ麯����ִ��Ч�ʸߣ��ɽ���β�ݹ顱������Ϊ��������
Position IterFind(ElementType X, BinTree BST)
{
	while(BST)
	{
		if(X > BST->Data)
			BST = BST->Right;	// ���������м�������
		else if(X < BST->Data)
			BST = BST->Left;	// ���������м�������
		else
			return BST;	// ���ҳɹ��������ҵ��Ľ��ĵ�ַ
	}
	return NULL;
}	// ����Ч�ʾ��������ĸ߶�

Position FindMin(BinTree BST)	// һֱ���������ң����һ����������Сֵ
{
	if(!BST)
		return NULL;
	while(BST->Left)
	{
		BST = BST->Left;
	}
	return BST;
}

Position FindMax(BinTree BST)	// һֱ�����������ң����һ�����������ֵ
{
	if(!BST)
		return NULL;
	while(BST->Right)
	{
		BST = BST->Right;
	}
	return BST;
}

BinTree Insert(ElementType X, BinTree BST)
{
	if(!BST)
	{
		BST = malloc(sizeof(struct TreeNode));
		BST->Data = X;
		BST->Left = BST->Right = NULL;
	}
	else if(X < BST->Data)
		BST->Left = Insert(X, BST->Left);
	else if(X > BST->Data)
		BST->Right = Insert(X, BST->Right);
	return BST;
}

BinTree Delete(ElementType X, BinTree BST)
{
	Position Tmp;
	if(!BST)
		printf("Ҫɾ����Ԫ��δ�ҵ���\n");
	else if(X < BST->Data)
		BST->Left = Delete(X, BST->Left);	// �������ݹ�ɾ��
	else if(X > BST->Data)
		BST->Right = Delete(X, BST->Right);	// �������ݹ�ɾ��
	else	// �ҵ���Ҫɾ���Ľ��
		if(BST->Left && BST->Right)	// Ҫɾ���Ľ���������������Ϊ��
		{
			Tmp = FindMin(BST->Right);	// �����������ҵ���С��Ԫ�����Ҫɾ���Ľ�㣨�������������ҵ����Ԫ�أ�
			BST->Data = Tmp->Data;
			BST->Right = Delete(BST->Data, BST->Right);	//��ɾ��������������ɾ����СԪ��
		}
		else 	// ��ɾ�������һ���ӽ������ӽ��
		{
			Tmp = BST;
			if(!BST->Left)	// ���Һ��ӻ����ӽ��
				BST = BST->Right;
			else if(!BST->Right)	// �����ӻ����ӽ��
				BST = BST->Left;
			free(Tmp);
		}
	return BST;
}