void PreOrderTraversal(BinTree BT)	// ÏÈÐò±éÀú
{
	if(BT)
	{
		printf("%d", BT->Data);
		PreOrderTraversal(BT->Left);
		PreOrderTraversal(BT->Right);
	}
}