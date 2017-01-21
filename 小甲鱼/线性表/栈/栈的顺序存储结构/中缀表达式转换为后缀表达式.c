/*
运行样例：
    请输入中缀表达式，输入 = 结束输入：
    1+(2-3)*4+10/5=
    1 2 3 - 4 * + 10 5 / +
*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define OK 1
#define ERROR 0
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10

typedef int Status;

typedef char ElemType;
typedef struct
{
	ElemType *base;
	ElemType *top;
	int stackSize;
}SqStack;

Status InitStack(SqStack *s)
{
	s->base = (ElemType*)malloc(sizeof(ElemType)*STACK_INIT_SIZE);
	if (!(s->base))
	{
		exit(0);
	}
	s->top = s->base;
	s->stackSize = STACK_INIT_SIZE;
	return OK;
}

Status Push(SqStack *s, ElemType e)
{
	if (s->top - s->base >= s->stackSize)
	{
		s->base = (ElemType*)realloc(s->base, sizeof(ElemType)*(s->stackSize + STACKINCREMENT));
		if (!(s->base))
		{
			exit(0);
		}
		s->top = s->base + s->stackSize;
		s->stackSize += STACKINCREMENT;
	}
	*(s->top) = e;
	s->top++;
	return OK;
}

Status Pop(SqStack *s, ElemType *e)
{
	if (s->top == s->base)
	{
		return ERROR;
	}
	*e = *(--(s->top));
	return OK;
}

Status DestroyStack(SqStack *s)
{
	int i, len;
	ElemType *temp;
	len = s->stackSize;
	for (i = 0; i < len; i++)
	{
		temp = s->base++;
		free(temp);
	}
	s->base = s->top = NULL;
	s->stackSize = 0;
	return OK;
}

int StackLen(SqStack s)
{
	return (s.top - s.base);
}

int main()
{
	SqStack s;
	char c, e;

	InitStack(&s);

	printf("请输入中缀表达式，输入 = 结束输入：\n");
	scanf("%c", &c);

	while (c != '=')
	{
		while (isdigit(c))
		{
			printf("%c", c);
			scanf("%c",&c);
			if(!isdigit(c))
            {
                printf(" ");
            }
		}
		if (')' == c)
		{
			Pop(&s, &e);
			while ('(' != e)
			{
				printf("%c ", e);
				Pop(&s, &e);
			}
		}
		else if ('+' == c || '-' == c)
		{
			if (!StackLen(s))	// 栈为空
			{
				Push(&s, c);
			}
			else
			{
				do
				{
					Pop(&s, &e);
					if ('(' == e)
					{
						Push(&s, e);
					}
					else
					{
						printf("%c ", e);
					}
				} while (StackLen(s) && '(' != e);
				Push(&s, c);
			}
		}
		else if ('*' == c || '/' == c || '(' == c)
		{
			Push(&s, c);
		}
		else if('=' == c)
        {
            break;
        }
		else
		{
			printf("输入格式错误！\n");
			return -1;
		}
		scanf("%c", &c);
	}

    while(StackLen(s))
    {
        Pop(&s,&e);
        printf("%c ",e);
    }
	DestroyStack(&s);

	return 0;
}
