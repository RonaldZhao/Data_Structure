void PostOrderTraversal(BinTree BT)	// ºóĞò±éÀú
{
	if(BT)
	{
		PostOrderTraversal(BT->Left);
		PostOrderTraversal(BT->Right);
		printf("%d", BT->Data);
	}
}