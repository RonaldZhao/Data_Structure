#include "page_198_2.h"//引入宏定义和函数声明的头文件
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

Status InitList_SqList(SqList *L)
{
	L->elem = (ElemType *)malloc(LIST_INIT_SIZE*sizeof(ElemType));
	if(!L->elem)
		exit(OVERFLOW);
	L->length = 0;
	L->listsize = LIST_INIT_SIZE;
	return OK;
}//InitList_SqList

int ListLength_SqList(SqList L)
{
	return L.length;
}//ListLength_SqList

void GetElem_SqList(SqList L,int i,ElemType *e)
{
	*e = L.elem[i];
}//GetElem_SqList

int EqualList(ElemType e1,ElemType e2)
{
	if(strcmp(e1.name,e2.name)==0)
		return 1;
	else
		return 0;
}//EqualList

int Less_EqualList(ElemType e1,ElemType e2)
{
	if(strcmp(e1.name,e2.name)<=0)
		return 1;
	else
		return 0;
}//Less_EqualList

int LocateElem_SqList(SqList La,ElemType e,int type)
{
	int i;
	switch (type)
	{
	case EQUAL:
		for(i=0;i<La.length;i++)
			if(EqualList(La.elem[i],e))
				return i;
		break;
	default:
		break;
	}
	return 0;
}//LocateElem_SqList

Status ListInsert_SqList(SqList *L,int i,ElemType e)
{
	ElemType *newbase,*p,*q;
	if(i<1||i>L->length+1)
		return ERROR;
	if(L->length>=L->listsize)
	{
		newbase = (ElemType *)realloc(L->elem,(L->length+LISTINCREMENT)*sizeof(ElemType));
		if(!newbase)
			return ERROR;
		L->elem = newbase;
		L->listsize += LISTINCREMENT;
	}
	q = &(L->elem[i-1]);
	for(p=&L->elem[L->length-1];p>=q;--p)
		*(p+1) = *p;
	*q = e;
	L->length++;
	return OK;
}//ListInsert_SqList

Status Destroy_SqList(SqList *L)
{
	free(L);
	return OK;
}//Destroy_SqList

void UnionList_SqList(SqList *La,SqList Lb)
{
	int La_len, Lb_len;
	int i;
	ElemType e;

	La_len = ListLength_SqList(*La);
	Lb_len = ListLength_SqList(Lb);

	for(i = 0;i<Lb_len;i++)
	{
		GetElem_SqList(Lb,i,&e);
		if(!LocateElem_SqList(*La,e,EQUAL))
			ListInsert_SqList(La,++La_len,e);
	}
}//UnionList_SqList

void MergeList_SqList(SqList La,SqList Lb,SqList *Lc)		//一直顺序表La和Lb元素按值非递减排列，归并得到新的顺序表Lc也按非递减顺序排列
{
	ElemType *pa,*pb,*pc,*pa_last,*pb_last;
	pa = La.elem;
	pb = Lb.elem;
	Lc->listsize = Lc->length = La.length + Lb.length;
	pc = Lc->elem = (ElemType *)malloc(Lc->listsize*sizeof(ElemType));
	if(!Lc->elem)
		exit(OVERFLOW);

	pa_last = La.elem + La.length-1;
	pb_last = Lb.elem + Lb.length-1;
	while(pa <= pa_last && pb <= pb_last)
	{
		if(Less_EqualList(*pa,*pb))
			*pc++ = *pa++;
		else
			*pc++ = *pb++;
	}

	while(pa <= pa_last)
	{
		*pc++ = *pa++;
	}

	while(pb <= pb_last)
	{
		*pc++ = *pb++;
	}
}//MergeList_SqList

void printlist_SqList(SqList L)
{
	int i;
	printf("name\tstuno\tage\tscore\n");
	for(i=0;i<L.length;i++)
	{
		printf("%-10s%s\t%d\t%d\n",L.elem[i].name,L.elem[i].stuno,L.elem[i].age,L.elem[i].score);
	}
	printf("\n");
}//printlist_SqList