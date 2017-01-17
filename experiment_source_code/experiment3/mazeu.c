typedef int ElemType;
typedef struct Data {
	int r, c;    // 迷宫的行列
	ElemType pre;// 上一个可通过迷宫在三元组中的位置
}SET, QET;

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "stack.h"
#include "queue.h"

//#define MAXSIZE 12500
#define maze 1
#define mark 0
int num;

void CreateMAP(int ***, int, int, int);// 动态生成二维数组
//ElemType FindPath(ElemType **, ElemType **, SqQueue *, int i, int j, int d[][2]);// 判断8个方向是否可以通行，并入队列
void PrintPuzzle(ElemType **m, SqStack *s, int row, int column);  // 打印迷宫
void PrintMAZE(int, int, int**);// 打印输出迷宫
Status PushData(SqQueue, SqStack *);//  将通过的路径放进栈
Status isOK();//判断当前点是否可走
// 深度优先搜索
// 宽度优先搜索

ElemType Directrion[8][2] = { { 1,1 },{ 0,1 },{ -1,1 },{ -1,0 },{ -1,-1 },{ 0,-1 },{ 1,-1 },{ 1,0 } };   // 逆时针方向寻找路径

int main()
{
	int m, n;// 行数和列数
	int k, flag;// 判断是否走出了迷宫
	
	ElemType **MAZE = NULL;// 指向迷宫数组
	ElemType **MARK = NULL;// 记忆数组
	SqStack *s, s1;
	SqQueue *Q, q;
	
	srand((unsigned)time(0));
	system("color 17");// 背景色蓝色，前景色白色

	printf("请输入迷宫的行数和列数：");
	while(scanf("%d %d", &m, &n) != EOF && m && n && m <= MAXSIZE && n <= MAXSIZE)
	{
		CreateMAP(&MAZE, m, n, maze);
		CreateMAP(&MARK, m, n, mark);
		Q = &q; s = &s1;
		InitQueue(Q); // 初始化队列
		InitStack(s); // 初始化栈
		printf("\n根据您的输入构造迷宫如下：\n");
		PrintMAZE(m, n, MAZE);
		flag = FindPath(MAZE, MARK, Q, m, n, Directrion);  // 寻找路径
		if (flag) {    // 可以走出迷宫
			PushData(q, s);
			k = s->top;
			k++;
			for (int i = 0; i<k; i++) {
				system("cls");
				PrintMAZE(m, n, MAZE);  // 打印迷宫
				PrintPuzzle(MAZE, s, m, n);  // 打印迷宫
				num++;
			}
			StackTraverse(s1);   // 输出坐标
		}
		else
		{
			PrintMAZE(m, n, MAZE);
			printf("No Path!\n");
		}
	}
	return 0;
}

void CreateMAP(int ***MAP, int r, int c, int flag)
{
	int i, j;
	*MAP = (int**)calloc(r+2, sizeof(int*));// 行
	for (i = 0; i < r + 2; i++)
	{
		(*MAP)[i] = (int*)calloc(c+2, sizeof(int));// 列
		if (flag)
		{
			for (j = 0; j < c + 2; j++)
			{
				if (i == 0 || j == 0 || j == c + 1 || i == r + 1)
				{
					(*MAP)[i][j] = 1;
				}
				else
				{
					(*MAP)[i][j] = rand() % 2;
				}
			}
		}
	}
}//CreateMAP,动态生成二维数组

void PrintMAZE(int r, int c, int** MAZE)
{
	int i, j;
	for (i = 0; i< r + 2; i++)
	{
		for (j = 0; j< c + 2; j++)
		{
			if (MAZE[i][j] == 1)
			{
				printf("■");
			}
			else {
				printf("  ");
			}
		}
		printf("\n");
	}
	for (i = 0; i<r + 2; i++)
	{
		free(MAZE[i]);// 释放第二维指针
	}
	free(MAZE);// 释放第一维指针
}//PrintMAZE，打印输出迷宫

ElemType FindPath(ElemType **MAZE, ElemType **MARK, SqQueue *Q, int r, int c, int d[][2])
{
	SET *data, data1, data2;   //data2用于记录向不同方向探索的坐标
	int flag = 0;  // 判断是否走出迷宫
	data = &data1;
	data->c = 1;  // 起点纵坐标
	data->r = 1;  // 起点横坐标
	data->pre = -1;  // 代表没有前一个元素 
	EnQueue(Q, data1);  // 起点入队
	while (Q->front != Q->rear) {   // 队列非空 
		int i, j;
		DeQueue(Q, data);
		i = data->r;  // 将行 列赋给i j 便于加上方向判断是否有路径
		j = data->c;
		MARK[i][j] = TRUE;  // 表示已经走过
		data2 = data1;
		data2.pre = Q->front;   // 记录上个开始探索方向的初始位置
		if ((i == r) && (j == c))   // 走出迷宫
		{
			flag = 1;
			break;
		}
		for (int k = 0; k < 8; k++) {   // 搜索八个方向
			i = data->r; 
			j = data->c;
			i += d[k][0];
			j += d[k][1];
			if (MAZE[i][j] == 1 || MARK[i][j] == TRUE)   // 遇见墙或已走过
				continue;
			else {
				data2.r = i;
				data2.c = j;
				MARK[i][j] = TRUE;
				EnQueue(Q, data2); // 找到通路，入队
			}
		} // for
		Q->front++;
	}  //while
	return flag;
}// FindPath,判断8个方向是否可以通行，并入队列

Status PushData(SqQueue q, SqStack *s) {   //  将通过的路径放进栈
	SET data1;
	int i;
	i = q.front;  // 上一个元素的位置
	while (i != -1) {    // 起点的值为 -1
		data1 = q.base[i];
		Push(s, data1);  // 坐标入栈
		i = q.base[i].pre;
	}
	return OK;
}

void PrintPuzzle(ElemType **m, SqStack *s, int row, int column) {  // 打印迷宫
	SET *data, data1;
	int stotal = s->top;    // 记录栈元素的总个数
	int num1 = 0;
	int flag = 1;
	data = &data1;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			if (i == 0 || j == 0 || i == row - 1 || j == column - 1 || m[i][j] == 1) {   //  输出迷宫墙
				//SetConsoleTextAttribute(GetStdHandle((STD_OUTPUT_HANDLE)), 7);
				printf("■");
			}
			else {
				data->r = i;
				data->c = j;
				if (SearchStackData(s, data1) && flag) {
					//SetConsoleTextAttribute(GetStdHandle((STD_OUTPUT_HANDLE)), 10);
					printf("√");
					num1++;
					if (num1 == num)
						flag = 0;
				}
				else {
					printf("  ");
				}
				s->top = stotal;
			}
		}
		printf("\n");
	}
}
