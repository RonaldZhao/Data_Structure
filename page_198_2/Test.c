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
	printf("First Insert function.\n");

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
	_getch();
	strcpy(e.name,"stu5");
	strcpy(e.stuno,"100003");
	e.age = 80;
	e.score = 1000;
	ListInsert_SqList(&La,3,e);
	printlist_SqList(La);
	printf("List A length now is %d.\n\n",La.length);
	_getch();

	InitList_SqList(&Lb);

	strcpy(e.name,"stu2");
	strcpy(e.stuno,"100001");
	e.age = 80;
	e.score = 1000;
	ListInsert_SqList(&Lb,1,e);
	strcpy(e.name,"stu4");
	strcpy(e.stuno,"100002");
	e.age = 80;
	e.score = 1000;
	ListInsert_SqList(&Lb,2,e);
	strcpy(e.name,"stu6");
	strcpy(e.stuno,"100001");
	e.age = 80;
	e.score = 1000;
	ListInsert_SqList(&Lb,3,e);
	printlist_SqList(Lb);
	printf("List B length now is %d.\n\n",Lb.length);
	_getch();

	printf("First is MergeList _SqList function.\n");
	printf("Now Merge List A and B...\n");
	MergeList_SqList(La,Lb,&Lc);
	printlist_SqList(Lc);
	_getch();

	printf("Second is UnionList_SqList function.\n");
	printf("Now Union List A and B...\n");
	UnionList_SqList(&La,Lb);
	printlist_SqList(La);
	printf("List A length now is %d.\n\n",La.length);
	_getch();

	//Destroy_SqList(&La);//不需要，La、Lb、Lc会在程序结束时自动释放
	//Destroy_SqList(&Lb);
	//Destroy_SqList(&Lc);
}//main
