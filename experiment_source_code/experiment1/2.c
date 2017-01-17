/*
设计并验证以下算法：设顺序表A和B中的数据元素为整数且单调递增有序，将这两张表合并成顺序表C
1）顺序表C单调递减有序
2）根据键盘输入数据建立顺序表A、B
3）输出顺序表A、B和C
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <malloc.h>

#define OK 1
#define ERROR 0
#define EQUAL 1
#define OVERFLOW -1
#define LIST_INIT_SIZE 1000
#define LIST_INCREMENT 50

typedef struct NODE {
	int data;
}Node;

struct LIST
{
	Node *data;
	int length;
	int size;
};

typedef struct LIST SqList;

int Init_List(SqList *);//初始化顺序表
int Create_List(SqList *);//创建顺序表
int List_Add_Elem(SqList *, int);//添加元素
int Delete_Useless_Same(SqList *);//删除相同多余元素
void Merge_List(SqList, SqList, SqList *);//合并顺序表
void Print_List(SqList);//打印表

int main()
{
	SqList La, Lb, Lc;
	Init_List(&La);
	Init_List(&Lb);
	Init_List(&Lc);
	printf("\n\t创建顺序表La:\n");
	Create_List(&La);
	printf("\n\t创建顺序表Lb:\n");
	Create_List(&Lb);
	printf("\n\t合并并逆置顺序表La和Lb\n");
	Merge_List(La, Lb, &Lc);
	printf("\n\t顺序表La:\n");
	Print_List(La);
	printf("\n\t顺序表Lb:\n");
	Print_List(Lb);
	printf("\n\t顺序表Lc:\n");
	Print_List(Lc);
	return 0;
}

int Init_List(SqList *L)
{
	L->data = (Node *)malloc(LIST_INIT_SIZE * sizeof(Node));
	if (!L->data)
		exit(OVERFLOW);
	L->length = 0;
	L->size = LIST_INIT_SIZE;
	return OK;
}//Init_List

int List_Add_Elem(SqList *L, int e)
{
	if (L->length >= L->size)
	{
		L->data = (Node *)realloc(L->data, (L->length + LIST_INCREMENT) * sizeof(Node));
		if (!L->data)
			return ERROR;
		L->size += LIST_INCREMENT;
	}
	L->data[L->length].data = e;
	L->length++;
	return OK;
}//List_Add_Elem

int Create_List(SqList *L)
{
	int Elem_Number;
	int temp;
	printf("\n\t请输入您要输入的元素个数：\n\t");
	scanf("%d", &Elem_Number);
	printf("\t请依次输入您要输入的元素(元素之间以空格分隔)：\n");
	for (int i = 0; i < Elem_Number; i++)
	{
		printf("\t");
		scanf("%d", &temp);
		List_Add_Elem(L, temp);
	}
	printf("\n\t数据添加完毕！按任意键继续.\n\t");
	_getch();
	return OK;
}//Create_List

void Print_List(SqList L)
{
	printf("\n\n");
	if (L.length == 0) {
		printf("\n\t当前顺序表为空！按任意键继续.\n\t");
	}
	else {
		for (int i = 0; i < L.length; i++) {
			printf("\t第 %-3d个数据为：%d\n", i + 1, L.data[i].data);
		}
		printf("\n\t数据输出完毕！按任意键继续.\n\t");
	}
	_getch();
}//Print_List

int Reverse_List(SqList *L)
{
	if (L->length == 0) {
		printf("\n\t当前顺序表为空！按任意键继续.\n\t");
	}
	else {
		int	temp;
		for (int i = L->length - 1; i >= L->length / 2; i--) {
			temp = L->data[i].data;
			L->data[i].data = L->data[L->length - i - 1].data;
			L->data[L->length - i - 1].data = temp;
		}
		printf("\n\t逆置操作完毕！按任意键继续.\n\t");
	}
	_getch();
	return OK;
}//Reverse_List

int Delete_Useless_Same(SqList *L)
{
	if (L->length == 0) {
		printf("\n\t当前顺序表为空！按任意键继续.\n\t");
	}
	else {
		int i, j;
		for (i = 0, j = 1; j < L->length; j++) {
			if (L->data[j].data != L->data[i].data) {
				L->data[++i].data = L->data[j].data;
			}
		}
		L->length = i + 1;
		printf("\n\t删除相同的多余元素完毕！按任意键继续.\n\t");
	}
	_getch();
	return OK;
}//Delete_Useless_Same

void Merge_List(SqList La, SqList Lb, SqList *Lc)
{
	Node *pa, *pb, *pc, *pa_last, *pb_last;
	pa = La.data;
	pb = Lb.data;
	Lc->size = Lc->length = La.length + Lb.length;
	pc = Lc->data = (Node *)malloc(Lc->size * sizeof(Node));
	if (!Lc->data)
		exit(OVERFLOW);
	pa_last = La.data + La.length - 1;
	pb_last = Lb.data + Lb.length - 1;
	while (pa <= pa_last && pb <= pb_last)
	{
		if (pa->data <= pb->data)
			*pc++ = *pa++;
		else
			*pc++ = *pb++;
	}

	while (pa <= pa_last)
	{
		*pc++ = *pa++;
	}

	while (pb <= pb_last)
	{
		*pc++ = *pb++;
	}
	Delete_Useless_Same(&(*Lc));
	Reverse_List(&(*Lc));
}//Merge_List