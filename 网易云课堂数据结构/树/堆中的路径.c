/*
  ��Ŀ������
  	��һϵ�и������ֲ���һ����ʼΪ�յ�С���� H[]����������������±� �� i ������ӡ�� H[i] ��������·����
  ����������
  5 3
  46 23 26 24 10
  5 4 3
  ���������
  24 23 10
  46 23 10
  26 10
*/
#include <stdio.h>

#define MAXN 1001		// �������±�Ϊ 1 ��ʼ���±�Ϊ 0 �ĵط�����
#define MINH -10001

int H[MAXN], size;

void Create()
{
	size = 0;
	H[0] = MINH;		// ���á����ڡ�
}

void Insert(int X)
{
	// �� X ���� H������ʡ�Լ����Ƿ������Ĵ���
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