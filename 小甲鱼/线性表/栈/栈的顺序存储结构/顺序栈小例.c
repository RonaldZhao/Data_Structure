/*
利用栈的数据结构特点，将二进制转换为相应的十进制数。
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef char ElemType;
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 20
typedef struct
{
	ElemType *base;
	ElemType *top;
	int stackSize;
}SqStack;

void InitStack(SqStack *s)
{
	s->base = (ElemType *)malloc(sizeof(ElemType) * STACK_INIT_SIZE);
	if (!s->base)
	{
		exit(0);
	}
	s->top = s->base;
	s->stackSize = STACK_INIT_SIZE;
}

void Push(SqStack *s, ElemType e)
{
	if (s->top - s->base >= s->stackSize)
	{
		s->base = (ElemType *)realloc(s->base, (s->stackSize + STACKINCREMENT) * sizeof(ElemType));
		if (!s->base)
		{
			exit(0);
		}
		s->top = s->base + s->stackSize;
		s->stackSize += STACKINCREMENT;
	}
	*(s->top) = e;
	s->top++;
}

void Pop(SqStack *s, ElemType *e)
{
	if (s->top == s->base)
	{
		return;
	}
	*e = *(--(s->top));
}

int StackLen(SqStack s)
{
	return (s.top - s.base);
}

int main()
{
	ElemType c;
	SqStack s;
	int len, i, sum = 0;

	InitStack(&s);

	printf("请输入二进制数，输入#符号表示输入结束:\n");
	scanf("%c", &c);
	while (c != '#')
	{
		Push(&s, c);
		scanf("%c", &c);
	}

	getchar();	// 把最后的'\n'从键盘缓冲区去掉

	len = StackLen(s);
	printf("栈的当前长度是: %d\n", len);

	for (i = 0; i < len; i++)
	{
		Pop(&s, &c);
		sum += (c - 48)*pow(2, i);
	}

	printf("转换后的十进制数是：%d\n", sum);

	return 0;
}
/*
课后完成：
    二进制转换为八进制，二进制转换为十六进制。
*/