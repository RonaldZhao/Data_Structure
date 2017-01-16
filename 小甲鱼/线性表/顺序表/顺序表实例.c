#include<stdio.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20

typedef int Status;
typedef int ElemType;
typedef struct
{
	ElemType data[MAXSIZE];
	int length;
}SqList;

Status InitL(SqList* L)
{
	L->length = 0;
	return OK;
}

Status ListInsert(SqList *L, int i, ElemType e)
{
	if (L->length >= MAXSIZE || i < 1 || i > L->length + 1)
	{
		return ERROR;
	}
	if (i < L->length)
	{
		for (int j = L->length - 1; j >= i - 1; j--)
		{
			L->data[j + 1] = L->data[j];
		}
	}
	L->data[i - 1] = e;
	++L->length;
	return OK;
}

Status GetElem(SqList L, int i, ElemType *e)
{
	if (L.length == 0 || i<1 || i>L.length)
	{
		return ERROR;
	}
	*e = L.data[i - 1];
	return OK;
}

Status LocateElem(SqList L, ElemType e)
{
	for (int i = 0; i < L.length; i++)
	{
		if (e == L.data[i])
		{
			return TRUE;
		}
	}
	return FALSE;
}

int ListLength(SqList L)
{
	return L.length;
}

void UnionL(SqList *La, SqList Lb)
{
	int La_len, Lb_len;
	ElemType e;
	La_len = ListLength(*La);
	Lb_len = ListLength(Lb);
	for (int i = 1; i <= Lb_len; i++)
	{
		GetElem(Lb, i, &e);
		if (!LocateElem(*La, e))
		{
			ListInsert(La, ++La_len, e);
		}
	}
}

void PrintList(SqList L)
{
	for (int i = 0; i < L.length; i++)
	{
		printf("%d  ", L.data[i]);
	}
	printf("\n");
}
int main()
{
	SqList La, Lb;
	InitL(&La);
	InitL(&Lb);
	for (int i = 1; i <= MAXSIZE / 2; i++)
	{
		ListInsert(&La, i, i);
		ListInsert(&Lb, i, i * 2);
	}
	PrintList(La);
	PrintList(Lb);
	UnionL(&La, Lb);
	PrintList(La);
	return 0;
}