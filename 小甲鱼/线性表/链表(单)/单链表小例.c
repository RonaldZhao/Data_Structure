/*
写一个完整的程序，实现随机生成20个元素的链表（尾插法或头插法任意），用快慢指针的思想
快速查找到中间结点的值并显示出来。
Author：gitzzg
Date：2017-1-18
Test Environment：VS-2017-RC
*/
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status;
typedef int ElemType;
typedef struct Node
{
	ElemType data;
	struct Node* next;
}Node;
typedef struct Node* LinkList;

void HeadInsertToCreateList(LinkList *L, int n)
{
	LinkList p;
	*L = (LinkList)malloc(sizeof(Node));
	(*L)->next = NULL;
	
	srand((unsigned)time(NULL));

	for (int i = 0; i < n; i++)
	{
		p = (LinkList)malloc(sizeof(Node));
		p->data = rand() % 100 + 1;

		p->next = (*L)->next;
		(*L)->next = p;
	}
}

void TailInsertToCreateList(LinkList *L, int n)
{
	LinkList p, q;

	*L = (LinkList)malloc(sizeof(Node));
	q = *L;

	srand((unsigned)time(0));
	
	for (int i = 0; i < n; i++)
	{
		p = (LinkList)malloc(sizeof(Node));
		p->data = rand() % 100 + 1;

		q->next = p;
		q = p;
	}
	q->next = NULL;
}

Status GetMid(LinkList L, ElemType *e)
{
	LinkList search, mid;
	search = mid = L;
	while (search->next)
	{
		mid = mid->next;
		if (search->next->next)
		{
			search = search->next->next;
		}
		else
		{
			search = search->next;
		}
	}
	*e = mid->data;
	return OK;
}

void PrintList(LinkList L)
{
	LinkList p;
	int num = 1;
	p = L->next;
	while (p)
	{
		printf("%d: %d\n", num++, p->data);
		p = p->next;
	}
	printf("\n");
}

int main()
{
	int n = 30;
	ElemType e1, e2;
	LinkList L1, L2;
	HeadInsertToCreateList(&L1, n);
	TailInsertToCreateList(&L2, n);
	PrintList(L1);
	PrintList(L2);
	GetMid(L1, &e1);
	GetMid(L2, &e2);
	printf("头插法链表的中间元素值：%d\n尾插法链表的中间元素值：%d\n", e1, e2);
	return 0;
}