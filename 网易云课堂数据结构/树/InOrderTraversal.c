void InOrderTraversal(BinTree BT)	// ÖÐÐò±éÀú
{
	if(BT)
	{
		InOrderTraversal(BT->Left);
		printf("%d", BT->Data);
		InOrderTraversal(BT->Right);
	}
}