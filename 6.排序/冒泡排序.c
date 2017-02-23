// 冒泡排序的时间复杂度：O(n^2)
// 对顺序表L做交换排序（冒泡排序初级版）
void BubbleSort0(SqList *L)
{
	int i, j;
	for(i = 1; i < L->length; i++)
	{
		for(j = i+1; j <= L->length; j++)
		{
			if(L->r[i] > L->r[j])
				swap(L, i, j);
		}
	}
}

// 对顺序表L做冒泡改进
void BubbleSort(SqList *L)
{
	int i, j;
	for(i = 1; i < L->length; i++)
	{
		for(j = L->length-1; j>= i; j--)	// j从后往前循环，思想就是把最小的逐个冒到顶端
		{
			if(L->r[j] > L->r[j+1])	// 如果前面的比后面的大，则交换
				swap(L, j, j+1);
		}
	}
}

// 对顺序表L改进冒泡算法：如{2,3,5,6,7,4,8,9,1}->{1,2,3,5,6,7,4,8,9}->{1,2,3,4,5,6,7,8,9}
void BubbleSort2(SqList *L)
{
	int i, j;
	Status flag = TRUE;
	for(i = 1; i < L->length && flag; i++)
	{
		flag = FALSE;
		for(j = L->length-1; j >= i; i--)
		{// 若此轮循环未发生交换，则此轮循环结束时说明已经排好序，flag保持为FALSE，后面的即可不必再比较
			if(L->r[j] > L->r[j+1])
			{
				swap(L, i, j);
				flag = TRUE;
			}
		}
	}
}