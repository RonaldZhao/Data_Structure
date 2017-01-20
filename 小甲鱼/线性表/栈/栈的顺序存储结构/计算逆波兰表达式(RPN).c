#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> // isdigit()

#define MAXBUFFER 10
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 20
typedef double ElemType;
typedef int Status;

typedef struct
{
    ElemType *base; // 指向栈底
    ElemType *top;  // 指向栈顶
    int stackSize;  // 栈的当前可用最大容量
} SqStack;

void InitStack(SqStack *s)
{
    s->base = (ElemType *)malloc(sizeof(ElemType) * STACK_INIT_SIZE);
    if (!(s->base))
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
        if (!(s->base))
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
    if (s->top == s->base) // 栈为空
    {
        return;
    }
    *e = *(--(s->top));
}

void DestroyStack(SqStack *s)
{
    int i, len;
    ElemType *temp;
    len = s->stackSize;
    for (i = 0; i < len; i++)
    {
        temp = s->base;
        free(temp);
        s->base++;
    }
    s->base = s->top = NULL;
    s->stackSize = 0;
}

int main()
{
    SqStack s;
    char c;
    double d, e;
    char str[MAXBUFFER];
    int i = 0;
    InitStack(&s);

    printf("请按逆波兰表达式输入待计算的数据，数据与运算符之间用空格隔开，输入#表示输入结束：\n");
    scanf("%c", &c);

    while (c != '#')
    {
        while (isdigit(c) || c == '.')
        {
            str[i++] = c;
            str[i] = '\0';
            if (i >= MAXBUFFER)
            {
                printf("输入的单个数据过大！\n");
                return -1;
            }
            scanf("%c", &c);
            if (c == ' ')
            {
                d = atof(str);
                Push(&s, d);
                i = 0;
                break;
            }
        }
        switch (c)
        {
        case '+':
            Pop(&s, &d);
            Pop(&s, &e);
            Push(&s, d + e);
            break;
        case '-':
            Pop(&s, &d);
            Pop(&s, &e);
            Push(&s, e - d);
            break;
        case '*':
            Pop(&s, &d);
            Pop(&s, &e);
            Push(&s, d * e);
            break;
        case '/':
            Pop(&s, &d);
            Pop(&s, &e);
            if (d != 0)
            {
                Push(&s, e / d);
            }
            else
            {
                printf("\nERROR：除数为0！\n");
                return -1;
            }
            break;
        }
        scanf("%c", &c);
    }

    Pop(&s, &e);
    DestroyStack(&s);
    printf("最终的计算结果为: %f", e);

    return 0;
}
