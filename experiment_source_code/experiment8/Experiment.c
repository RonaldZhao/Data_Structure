/*
在完善“12.11.4 参考源程序”的基础上，进行典型内部排序算法的比较
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

typedef struct list {
	int *elem;
	int length, move, compare;
}List;

void randnum(List *a);//随机数
void printArray(List);//输出
void init(List, List*);//初始化
void InsertSort(List*);//直插
void BInsertSort(List *a);//折半
void ShellSort(List *a);//希尔
void BubbleSort(List *a);//冒泡
void QuickSort(List *a);//快排
void SelectSort(List *a);//直选
void HeapSort(List *a);//堆
void MergeSort(List *a); //二路归并
void swap(int *, int *);

int main() {
	List *array, *t;
	DWORD tstart, tstop, runtime[8];
	t = (List *)malloc(sizeof(List));
	array = (List *)malloc(sizeof(List));
	randnum(array);
	t->elem = (int *)malloc(sizeof(int)*(array->length + 1));
	/*printf("生成随机数组如下：\n");
	printArray(*array);*/

	printf("正在计算时间差......\n");
	init(*array, t);
	tstart = clock();
	InsertSort(t);
	tstop = clock();
	runtime[0] = tstop - tstart;
	printArray(*t);

	init(*array, t);
	tstart = clock();
	BInsertSort(t);
	tstop = clock();
	runtime[1] = tstop - tstart;
	printArray(*t);

	init(*array, t);
	tstart = clock();
	ShellSort(t);
	tstop = clock();
	runtime[2] = tstop - tstart;
	printArray(*t);

	init(*array, t);
	tstart = clock();
	BubbleSort(t);
	tstop = clock();
	runtime[3] = tstop - tstart;
	printArray(*t);

	init(*array, t);
	tstart = clock();
	QuickSort(t);
	tstop = clock();
	runtime[4] = tstop - tstart;
	printArray(*t);

	init(*array, t);
	tstart = clock();
	SelectSort(t);
	tstop = clock();
	runtime[5] = tstop - tstart;
	printArray(*t);

	init(*array, t);
	tstart = clock();
	HeapSort(t);
	tstop = clock();
	runtime[6] = tstop - tstart;
	printArray(*t);

	init(*array, t);
	tstart = clock();
	MergeSort(t);
	tstop = clock();
	runtime[7] = tstop - tstart;
	printArray(*t);

	puts("");
	printf("InsertSort use %u CPU time\nmove %d, compare %d\n", runtime[0], t->move, t->compare);
	printf("BInsertSort use %u CPU time\nmove %d, compare %d\n", runtime[1], t->move, t->compare);
	printf("ShellSort use %u CPU time\nmove %d, compare %d\n", runtime[2], t->move, t->compare);
	printf("BubbleSort use %u CPU time\nmove %d, compare %d\n", runtime[3], t->move, t->compare);
	printf("QuickSort use %u CPU time\nmove %d, compare %d\n", runtime[4], t->move, t->compare);
	printf("SelectSort use %u CPU time\nmove %d, compare %d\n", runtime[5], t->move, t->compare);
	printf("HeapSort use %u CPU time\nmove %d, compare %d\n", runtime[6], t->move, t->compare);
	printf("MergeSort use %u CPU time\nmove %d, compare %d\n", runtime[7], t->move, t->compare);

	system("pause");
	return 0;
}
//初始化
void init(List a, List *b) {
	for (int i = 1; i <= a.length; i++) {
		b->elem[i] = a.elem[i];
	}
	b->move = 0;
	b->compare = 0;
	b->length = a.length;
}
//折半
void BInsertSort(List *a) {
	int low, high, mid;
	for (int i = 2; i <= a->length; i++) {
		a->elem[0] = a->elem[i];
		a->move++;
		low = 1;
		high = i - 1;
		while (low <= high) {
			a->compare++;
			mid = (low + high) / 2;
			a->compare++;
			if (a->elem[0] < a->elem[mid]) {
				high = mid - 1;
			}
			else {
				low = mid + 1;
			}
		}
		for (int j = i - 1; j >= high + 1; j--) {
			a->move++;
			a->elem[j + 1] = a->elem[j];
		}
		a->move++;
		a->elem[high + 1] = a->elem[0];
	}
}
//希尔
void ShellInsert(List* a, int dela) {
	for (int i = 1 + dela; i <= a->length; i++) {
		a->compare++;
		if (a->elem[i] < a->elem[i - dela]) {
			a->elem[0] = a->elem[i];
			for (int j = i - dela; j > 0 && a->elem[0] < a->elem[j]; j -= dela) {
				a->elem[j + dela] = a->elem[j];
				a->elem[j + dela] = a->elem[0];
				a->move += 2;
			}
		}
	}
}
void ShellSort(List *a) {
	int delt[] = { 100, 80, 60, 40, 20, 10, 5, 3, 2, 1 };
	for (int i = 0; i < 10; ++i) {
		ShellInsert(a, delt[i]);
	}
}
//冒泡
void BubbleSort(List *a) {
	for (int i = a->length; i > 0; i--) {
		for (int j = 0; j < i - 1; j++) {
			a->compare++;
			if (a->elem[j] > a->elem[j + 1])
			{
				a->move++;
				swap(&a->elem[j], &a->elem[j + 1]);
			}

		}
	}
}
//快排
int median3(List *a, int arr[], int left, int right) {
	int center = (left + right) / 2;
	a->compare++;
	if (arr[left] > arr[center])
	{
		swap(&arr[left], &arr[center]);
		a->move++;
	}
	a->compare++;
	if (arr[left] > arr[right])
	{
		a->move++;
		swap(&arr[left], &arr[right]);
	}
	a->compare++;
	if (arr[center] > arr[right]) {
		a->move++;
		swap(&arr[right], &arr[center]);
	}
	a->move++;
	swap(&arr[center], &arr[right - 1]);
	return arr[right - 1];
}
void insertionsort(List *a, int arr[], int n) {
	int tmp;
	for (int i = 1; i <= n; i++) {
		tmp = arr[i];
		for (int j = i; j > 0 && arr[j - 1] > tmp; j--) {
			a->move++;
			arr[j] = arr[j - 1];
			arr[j] = tmp;
		}
	}
}
void qusort(List *a, int arr[], int left, int right) {
	int pivot, i, j;
	if (left + 2 <= right) {
		pivot = median3(a, arr, left, right);
		i = left;
		j = right - 1;
		while (1) {
			while (arr[++i] < pivot) {
				a->compare++;
				a->move++;
			}
			while (arr[--j] > pivot) {
				a->compare++;
				a->move++;
			}
			if (i < j) {
				a->move++;
				swap(&arr[i], &arr[j]);
			}
			else {
				break;
			}
		}
		a->move++;
		swap(&arr[i], &arr[right - 1]);
		qusort(a, arr, left, i - 1);
		qusort(a, arr, i++, right);
	}
	else {
		insertionsort(a, arr + left, right - left + 1);
	}
}

void QuickSort(List *a) {
	qusort(a, a->elem, 1, a->length);
}
//直选
void SelectSort(List *a) {
	int k;
	for (int i = 1; i <= a->length - 1; i++) {
		k = i;
		for (int j = i + 1; j <= a->length; ++j) {
			a->compare++;
			if (a->elem[j] < a->elem[k])
				k = j;
			if (k != i) {
				a->move++;
				swap(&a->elem[i], &a->elem[k]);
			}
		}
	}
}
//堆
void sift(List *a, int k, int m) {
	int flag, t, x, i, j;
	t = a->elem[k];
	x = a->elem[k];
	i = k;
	j = 2 * k;
	flag = 0;
	while (j <= m && !flag) {
		a->compare++;
		if (j <= m && a->elem[j] < a->elem[j + 1])
			j = j + 1;
		a->compare++;
		if (x >= a->elem[j])
			flag = 1;
		else {
			a->move++;
			a->elem[i] = a->elem[j];
			i = j;
			j = 2 * i;
		}
	}
	a->move++;
	a->elem[i] = t;
}
void crtHeap(List *a) {
	for (int i = a->length / 2; i >= 1; --i) {
		sift(a, i, a->length);
	}
}
void HeapSort(List *a) {
	crtHeap(a);
	for (int i = a->length; i >= 2; --i) {
		a->move++;
		swap(&a->elem[i], &a->elem[i]);
		sift(a, 1, i - 1);
	}
}
//二路归并
void Merge(List *L, int low, int mid, int high) {
	int i = low, j = mid + 1, k = 0;
	List L1;
	L1.elem = (int *)malloc(sizeof(int)*(high - low + 1));
	while (i <= mid && j <= high) {
		L1.elem[k++] = L->elem[i] < L->elem[j] ? L->elem[i++] : L->elem[j++];
		L->compare++;
		L->move++;
	}

	while (i <= mid) {
		L->move++;
		L1.elem[k++] = L->elem[i++];
	}
	while (j <= high) {
		L->move++;
		L1.elem[k++] = L->elem[j++];
	}
	for (k = 0, i = low; i <= high; k++, i++) {
		L->move++;
		L->elem[i] = L1.elem[k];
	}
}
void MSort(List *L, int len) {
	int i;
	for (i = 1; i + 2 * len - 1 < L->length; i = i + 2 * len) {
		Merge(L, i, i + len - 1, i + 2 * len - 1);
	}
	if (i + len - 1 < L->length)
		Merge(L, i, i + len - 1, L->length);
}
void MergeSort(List *a) {
	for (int i = 1; i < a->length; i *= 2) {
		MSort(a, i);
	}
}
//直插
void InsertSort(List *a) {
	int j;
	for (int i = 2; i <= a->length; i++) {
		a->elem[0] = a->elem[i];
		a->move++;
		j = i - 1;
		a->compare++;
		while (a->elem[0] < a->elem[j]) {
			a->compare++;
			a->elem[j + 1] = a->elem[j];
			a->move++;
			j = j - 1;
		}
		a->elem[j + 1] = a->elem[0];
		a->move++;
	}
}
//交换
void swap(int *a, int *b) {
	int t;
	t = *a;
	*a = *b;
	*b = t;
}
//随机生成数组
void randnum(List *a) {
	int n;
	printf("请输入要生成的随机数个数：");
	scanf("%d", &n);
	a->elem = (int *)malloc(sizeof(int)*(n + 1));
	a->length = n;
	srand((unsigned)time(NULL));
	printf("正在生成随机数序列");
	for (int i = 1; i <= n; i++) {
		a->elem[i] = rand();
		if (i % (n / 10) == 0)
			printf(".");
	}
	puts("\nDone.");
}
//输出
void printArray(List a) {
	FILE *f;
	f = fopen("result.txt", "a");
	long counter = 0;
	for (int i = 1; i <= a.length; i++) {
		fprintf(f, "%-8d\t", a.elem[i]);
		//printf("%-8d\t", a.elem[i]);
		counter++;
		if (counter % 8 == 0)
			fprintf(f, "\n");
	}
	fprintf(f, "\n\n\n");
	fclose(f);
}
