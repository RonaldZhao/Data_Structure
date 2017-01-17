#include "queue.h"
#define MAXSIZE 12500
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

Status InitQueue(SqQueue *Q)
{
    if(!S->data)
        return ERROR;
    Q->front = Q->rear = 0;
    return OK;
}//InitQueue

Status DestroyQueue(SqQueue *Q)
{
    if(*Q)
    {
        *Q = NULL;
        return OK;
    }
    return ERROR;
}//DestroyQueue

Status ClearQueue(SqQueue *Q)
{
    if(QueueLength(*Q))
    {
        Q->front = Q->rear = 0;
        return OK;
    }
    return ERROR;
}//ClearQueue

Status QueueEmpty(SqQueue Q)
{
    if(QueueLength(Q))
        return FALSE;
    return TRUE;
}//QueueEmpty

Status GetHead(SqQueue Q, QElemType *e)
{
    if(!QueueEmpty(Q))
    {
        *e = Q.front;
        return OK;
    }
    return ERROR;
}//GetHead

Status EnQueue(SqQueue *Q,QElemType e)
{
    if((Q->rear+1) % MAXSIZE == Q->front)   //队列满
        return ERROR;
    Q->data[Q->rear] = e;                   //将元素e赋值给队尾
    Q->rear = (Q->rear + 1) % MAXSIZE;      //rear指针向后移动一个位置
    return OK;
}//EnQueue

Status DeQueue(SqQueue *Q,QElemType *e)
{
    if(Q->front == Q->rear)                 //队列空
        return ERROR;
    *e = Q->data[Q->front];                 //将队头元素赋值给e
    Q->front = (Q->front + 1) % MAXSIZE;    //将front指针向后移动一个位置
    return OK;
}//DeQueue

int QueueLength(SqQueue Q)
{
    return (Q.front - Q.rear + MAXSIZE) % MAXSIZE;
}//QueueLength