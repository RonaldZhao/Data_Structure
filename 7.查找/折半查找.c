int Binary_Search(int *a, int n, int key)
{
	int low, high, mid;
	low = 1;
	high = n;
	while(low <= high)
	{
		mid = (low+high)/2;
		// 上面一行改为：mid = low + (high+low)*(key-a[low])/(a[high]-a[low]);则为插值查找
		// 从时间复杂度上来看，插值查找也是O(logn)，但对于表长较大，关键字分布又比较均匀的查找表来说，插值查找算法的
		// 平均性能比折半查找要好得多
		if(a[mid] > key)
			high = mid-1;
		else if(a[mid] < key)
			low = mid+1;
		else
			return mid;
	}
	return 0;
}// 时间复杂度为O(logn)