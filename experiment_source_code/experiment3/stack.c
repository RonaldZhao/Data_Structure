#include "stack.h"
#include <stdio.h>
#include <string.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

Status InitStack(SqStack *S)
{
    S->top = -1;
    return OK;
}//InitStack

Status DestroyStack(SqStack *S)
{
	return OK;
}//DestroyStack

Status ClearStack(SqStack *S)
{
	if (S)
	{
		memset(S->data, 0, sizeof(S->data));
		S->top = -1;
	}
}//ClearStack

Status StackEmpty(SqStack S)
{
    if(S.top == -1)
        return TRUE;
    return FALSE;
}//StackEmpty

Status GetTop(SqStack S,SElemType *e)
{
    if(!StackEmpty(S))
    {
        *e = S.top;
        return OK;
    }
    return ERROR;
}//GetTop

Status Push(SqStack *S, SElemType e)
{
    if(S->top == MAXSIZE - 1)//栈满
    {
        return ERROR;
    }
    ++S->top;
    S->data[S->top] =  e;
    return OK;
}//Push

Status Pop(SqStack *S,SElemType *e)
{
    if(!StackEmpty(*S))
    {
        *e = S->top;
        --S->top;
        return OK;
    }
    return ERROR;
}//Pop

int StackLength(SqStack S)
{
	return S.top+1;
}