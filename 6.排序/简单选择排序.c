// 简单选择排序时间复杂度：O(n^2)，虽然时间复杂度和冒泡排序一样，但是性能上略优于冒泡排序，因为此算法只在找到每轮循环的最小值时才进行交换
// 对顺序表L作简单选择排序
void SelectionSort(SqList *L)
{
	int i, j, min;
	for(i = 1; i < L->length; i++)
	{
		min = i;
		for(j = i+1; j <= L->length; j++)
		{
			if(L->r[min] > L->r[j])
				min = j;
		}
		if(i != min)
			swap(L, i, min);
	}
}