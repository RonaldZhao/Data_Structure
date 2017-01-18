/*
Author: gitzzg
Date: 2017-1-18
Test Everement: VS-2017-RC
*/
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define OK 1
#define ERROR 0
#define True 1
#define False 0
typedef int ElemType;
typedef int Status;

typedef struct CLinkList
{
	ElemType data;
	struct ClinkList *next;
}node;

Status InitList(node **pNode)
{
	ElemType item;
	node *target;
	node *temp;
	printf("输入结点的值，输入0完成初始化：\n");
	while (1)
	{
		scanf("%d", &item);
		fflush(stdin);
		if (item == 0)
		{
			return OK;
		}
		if ((*pNode) == NULL)
		{
			*pNode = (node*)malloc(sizeof(struct CLinkList));
			if (!(*pNode))
			{
				exit(0);
			}
			(*pNode)->data = item;
			(*pNode)->next = *pNode;	// 构成单循环
		}
		else
		{
			for (target = (*pNode); target->next != (*pNode); target = target->next)
			{
				;
			}
			temp = (node *)malloc(sizeof(struct CLinkList));
			if (!temp)
			{
				exit(0);
			}
			temp->data = item;
			temp->next = target->next;
			target->next = temp;
		}
	}
}

void PrintList(node *L)
{
	node *temp;
	for (temp = L; temp->next != L; temp = temp->next)
	{
		printf("%-5d", temp->data);
	}
	printf("\n");
}

Status ListInsert(node **pNode, int i)
{
	ElemType item;
	node *temp;
	node *target;
	int j = 1;
	printf("请输入要插入的结点的值：");
	scanf("%d", &item);
	if (i == 1)
	{
		temp = (node *)malloc(sizeof(struct CLinkList));
		if (!temp)
		{
			exit(0);
		}
		for (target = (*pNode); target != (*pNode); target = target->next)
		{
			;
		}
		temp->data = item;
		temp->next = (*pNode);
		target->next = temp;
		*pNode = temp;
	}
	else
	{
		target = (*pNode);
		for (; j < i - 1; ++j)
		{
			target = target->next;
		}
		temp = (node *)malloc(sizeof(struct CLinkList));
		if (!temp)
		{
			exit(0);
		}
		temp->data = item;
		temp->next = target->next;
		target->next = temp;
	}
	return OK;
}

Status ListDelete(node **pNode, int i, ElemType *e)
{
	node *target;
	node *temp;
	int j = 1;
	if (i == 1)
	{
		for (target = (*pNode); target->next != (*pNode); target = target->next)
		{
			;
		}
		temp = *pNode;
		*pNode = (*pNode)->next;
		target->next = *pNode;
		*e = temp->data;
		free(temp);
	}
	else
	{
		target = *pNode;
		for (; j < i - 1; ++j)
		{
			target = target->next;
		}
		temp = target->next;
		target->next = temp->next;
		*e = temp->data;
		free(temp);
	}
	return OK;
}

int ListSearch(node *L, ElemType e)
{
	node *target;
	int i = 1;
	for (target = L; target->data != e && target->next != L; ++i)
	{
		target = target->next;
	}
	if (target->next == L)
	{
		return 0;
	}
	else
	{
		return i;
	}
}

void PrintMenu()
{
	printf("请选择菜单：\n");
	printf("1.初始化链表\n");
	printf("2.插入结点\n");
	printf("3.删除结点\n");
	printf("4.返回结点的位置\n");
	printf("5.遍历链表\n");
	printf("0.退出");
}

int main()
{
	int Exit = False;
	int choice;
	int i;
	node *L = NULL;
	ElemType e;
	PrintMenu();
	while (!Exit)
	{
		printf("请选择你的操作：");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:InitList(&L);
			break;
		case 2:
			printf("请输入要插入的位置：");
			scanf("%d", &i);
			ListInsert(&L,i);
			break;
		case 3:
			printf("请输入要删除的位置：");
			scanf("%d", &i);
			ListDelete(&L, i, &e);
			printf("已删除第%d个结点的元素，其元素值为%d\n", i, e);
			break;
		case 4:
			printf("请输入要查找的元素的值：");
			scanf("%d", &e);
			i = ListSearch(L, e);
			printf("元素%d的位置是：%d\n", e, i);
			break;
		case 5:PrintList(L);
			break;
		case 0:Exit = True;
			break;
		default:printf("输入错误！\n");
			break;
		}
	}
	return 0;
}