#include "page_198_2.h"
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#include <string.h>

void main()
{
	ElemType e;
	SqList La,Lb,Lc;

	system("cls");//取代clrscr()函数，头文件为stdlib.h

	printf("\n\n--------------------------List Demo is running...-----------------------------\n\n");
	printf("First Inser function.\n");

	InitList_SqList(&La);

	strcpy(e.name,"stu1");
	strcpy(e.stuno,"100001");
	e.age = 80;
	e.score = 1000;
	ListInsert_SqList(&La,1,e);
	strcpy(e.name,"stu3");
	strcpy(e.stuno,"100002");
	e.age = 80;
	e.score = 1000;
	ListInsert_SqList(&La,2,e);
	printlist_SqList(La);
	printf("List A length now is %d.\n\n",La.length);
	getch();
	strcpy(e.name,"stu5");
	strcpy(e.stuno,"100003");
	e.age = 80;
	e.score = 1000;
	ListInsert_SqList(&La,3,e);
	printlist_SqList(La);
	printf("List A length now is %d.\n\n",La.length);
	getch();

	InitList_SqList(&Lb);

	strcpy(e.name,"stu1");
	strcpy(e.stuno,"100001");
	e.age = 80;
	e.score = 1000;
	ListInsert_SqList(&Lb,1,e);
	strcpy(e.name,"stu3");
	strcpy(e.stuno,"100002");
	e.age = 80;
	e.score = 1000;
	ListInsert_SqList(&Lb,2,e);
	strcpy(e.name,"stu1");
	strcpy(e.stuno,"100001");
	e.age = 80;
	e.score = 1000;
	ListInsert_SqList(&Lb,3,e);
	strcpy(e.name,"stu3");
	strcpy(e.stuno,"100002");
	e.age = 80;
	e.score = 1000;
	ListInsert_SqList(&Lb,2,e);
	printlist_SqList(Lb);
	printf("List B length now is %d.\n\n",Lb.length);
	getch();

	printf("First is MergeList _SqList function.\n");
	printf("Now Merge List A and B...\n");
	MergeList_SqList(La,Lb,&Lc);
	printlist_SqList(Lc);
	getch();

	printf("Second is UnionList_SqList function.\n");
	printf("Now Union List A and B...\n");
	UnionList_SqList(&La,Lb);
	printlist_SqList(La);
	printf("List A length now is %d.\n\n",La.length);
	getch();

	Destroy_SqList(&La);
	Destroy_SqList(&Lb);
	Destroy_SqList(&Lc);
}//main
