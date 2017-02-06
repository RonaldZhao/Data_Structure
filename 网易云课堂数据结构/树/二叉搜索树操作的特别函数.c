Position Find(ElementType X, BinTree BST)
{
	if(!BST)	// 查找失败
		return NULL;
	if(X > BST->Data)
		return Find(X, BST->Right);	// 在右子树中继续查找
	else if(X < BST->Data)
		return Find(X, BST->Left);	// 在左子树中继续查找
	else
		return BST;	// 查找成功，返回找到的结点的地址
}

// 由于非递归函数的执行效率高，可将“尾递归”函数改为迭代函数
Position IterFind(ElementType X, BinTree BST)
{
	while(BST)
	{
		if(X > BST->Data)
			BST = BST->Right;	// 在右子树中继续查找
		else if(X < BST->Data)
			BST = BST->Left;	// 在左子树中继续查找
		else
			return BST;	// 查找成功，返回找到的结点的地址
	}
	return NULL;
}	// 查找效率决定于树的高度

Position FindMin(BinTree BST)	// 一直往左子树找，最后一个结点就是最小值
{
	if(!BST)
		return NULL;
	while(BST->Left)
	{
		BST = BST->Left;
	}
	return BST;
}

Position FindMax(BinTree BST)	// 一直往左右子树找，最后一个结点就是最大值
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
		printf("要删除的元素未找到！\n");
	else if(X < BST->Data)
		BST->Left = Delete(X, BST->Left);	// 左子树递归删除
	else if(X > BST->Data)
		BST->Right = Delete(X, BST->Right);	// 右子树递归删除
	else	// 找到了要删除的结点
		if(BST->Left && BST->Right)	// 要删除的结点的左右子树都不为空
		{
			Tmp = FindMin(BST->Right);	// 在右子树中找到最小的元素填充要删除的结点（或在左子树中找到最大元素）
			BST->Data = Tmp->Data;
			BST->Right = Delete(BST->Data, BST->Right);	//在删除结点的右子树中删除最小元素
		}
		else 	// 被删除结点有一个子结点或无子结点
		{
			Tmp = BST;
			if(!BST->Left)	// 有右孩子或无子结点
				BST = BST->Right;
			else if(!BST->Right)	// 有左孩子或无子结点
				BST = BST->Left;
			free(Tmp);
		}
	return BST;
}