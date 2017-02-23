// 顺序查找，a为数组，n为要查找的数组个数，key为要查找的关键字
int Sequential_Search(int *a, int n, int key)
{
	int i;
	for(i = 1; i <= n; i++)
		if(a[i] == key)
			return i;
	return 0;
}

// 顺序查找优化：有哨兵的顺序查找
int Sequential_Search2(int *a, int n, int key)
{
	int i;
	a[0] = key;
	i = n;
	while(a[i] != key)
		i--;
	return i;	// 返回0说明查找失败
}// 时间复杂度：O(n)