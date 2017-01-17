/*
设计并验证以下算法：设顺序表L中的数据元素为整数且递增有序，删除其值相同的多余元素，即顺序表L中相同的元素只保留一个，
并逆置删除后的顺序表L
1）根据键盘输入数据建立顺序表L
2）输出顺序表L、删除值相同的多余元素后的顺序表L、逆置的顺序表L
3）假设顺序表L的长度为n，要求以O(n)的时间复杂度完成对值相同的多余元素的删除
*/
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <conio.h>

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

void Print_Menu();//打印菜单
int Init_List(SqList *);//初始化顺序表L
int Create_List(SqList *);//创建顺序表L
int List_Add_Elem(SqList *, int);//往顺序表中添加元素
int Reverse_List(SqList *);//逆置顺序表
int Delete_Useless_Same(SqList *);//删除多余的相同元素
void Print_List(SqList);//打印顺序表
void Input_Error();//输出错误信息

int main()
{
	int User_Choose;
	SqList L;
	Init_List(&L);

	Print_Menu();

	while (1)
	{
		printf("\n\t请选择您要进行的操作：\n\t");
		scanf("%d", &User_Choose);
		switch (User_Choose)
		{
		case 1:
			Create_List(&L);
			Print_Menu();
			break;
		case 2:
			Print_List(L);
			Print_Menu();
			break;
		case 3:
			Reverse_List(&L);
			Print_Menu();
			break;
		case 4:
			Delete_Useless_Same(&L);
			Print_Menu();
			break;
		case 0:
			free(L.data);//释放空间
			return 0;
		default:
			Input_Error();
			break;
		}
	}
}

void Print_Menu()
{
	system("cls");
	printf("\n\n\t1.建立顺序表\n");
	printf("\t2.输出顺序表\n");
	printf("\t3.逆置顺序表\n");
	printf("\t4.删除顺序表中相同的多余元素\n");
	printf("\t0.退出程序\n");
}

int Init_List(SqList *L)
{
	L->data = (Node *)malloc(LIST_INIT_SIZE * sizeof(Node));
	if (!L->data)
		exit(OVERFLOW);
	L->length = 0;
	L->size = LIST_INIT_SIZE;
	return OK;
}//InitList_SqList

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
}//ListInsert_SqList

int Create_List(SqList *L)
{
	system("cls");
	int Elem_Number;
	int temp;
	printf("\n\t请输入您要输入的元素个数：\n\t");
	scanf("%d", &Elem_Number);
	printf("\t请按递增有序依次输入您要输入的元素(元素之间以空格分隔)：\n");
	for (int i = 0; i < Elem_Number; i++)
	{
		printf("\t");
		scanf("%d", &temp);
		List_Add_Elem(&(*L), temp);
	}
	printf("\n\t数据添加完毕！\n\t按任意键返回主菜单.\n\t");
	_getch();
	return OK;
}//Create_List

void Print_List(SqList L)
{
	system("cls");
	printf("\n\n");
	if (L.length == 0) {
		printf("\n\t当前顺序表为空！\n\t按任意键返回主菜单.\n\t");
	}
	else {
		for (int i = 0; i < L.length; i++) {
			printf("\t第 %-3d个数据为：%d\n", i + 1, L.data[i].data);
		}
		printf("\n\t数据输出完毕！\n\t按任意键返回主菜单.\n\t");
	}
	_getch();
}//printlist_SqList

int Reverse_List(SqList *L)
{
	system("cls");
	if (L->length == 0) {
		printf("\n\t当前顺序表为空！\n\t按任意键返回主菜单.\n\t");
	}
	else {
		int	temp;
		for (int i = L->length - 1; i >= L->length / 2; i--) {
			temp = L->data[i].data;
			L->data[i].data = L->data[L->length - i - 1].data;
			L->data[L->length - i - 1].data = temp;
		}
		printf("\n\t逆置操作完毕！\n\t按任意键返回主菜单.\n\t");
	}
	_getch();
	return OK;
}//ReverseList

int Delete_Useless_Same(SqList *L)
{
	system("cls");
	if (L->length == 0) {
		printf("\n\t当前顺序表为空！\n\t按任意键返回主菜单.\n\t");
	}
	else {
		int i, j;
		for (i = 0, j = 1; j < L->length; j++) {
			if (L->data[j].data != L->data[i].data) {//寻找下一个不同的元素
				L->data[++i].data = L->data[j].data;//找到后将其移动到当前位置的下一个位置
			}
		}
		L->length = i + 1;
		printf("\n\t删除相同的多余元素完毕！\n\t按任意键返回主菜单.\n\t");
	}
	_getch();
	return OK;
}//DeleteUselessElem

void Input_Error()
{
	printf("\n\t！请输入正确的选项！\n\n");
}//Input_Error
