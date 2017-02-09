/*
  题目描述：
  	将一系列给定数字插入一个初始为空的小顶堆 H[]。随后对任意给定的下标 “ i ”，打印从 H[i] 到根结点的路径。
  输入样例：
  5 3
  46 23 26 24 10
  5 4 3
  输出样例：
  24 23 10
  46 23 10
  26 10
*/
#include <stdio.h>

#define MAXN 1001		// 根结点从下标为 1 开始，下标为 0 的地方空着
#define MINH -10001

int H[MAXN], size;

void Create()
{
	size = 0;
	H[0] = MINH;		// 设置“岗哨”
}

void Insert(int X)
{
	// 将 X 插入 H，这里省略检查堆是否已满的代码
	int i;
	for(i=++size;H[i/2]>X;i/=2)
		H[i] = H[i/2];
	H[i] = X;
}

int main()
{
	int n, m, x, i, j;
	scanf("%d%d", &n, &m);
	Create();
	for(i=0;i<n;i++)
	{
		scanf("%d", &x);
		Insert(x);
	}
	
	for(i=0;i<m;i++)
	{
		scanf("%d", &j);
		printf("%d", H[j]);
		while(j>1)
		{
			j /= 2;
			printf("% d", H[j]);
		}
		printf("\n");
	}
	
	return 0;
}