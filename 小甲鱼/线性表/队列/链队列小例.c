/*
编写一个链队列，任意输入一串字符，以'#'作为结束标志，然后将队列中的元素打印出来。
*/
#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;
typedef struct
{
    ElemType data;
    struct QNode *next;
}QNode, *QNodePtr;
typedef struct
{
    QNodePtr front,rear;
}QLinkList;

void InitQueue(QLinkList *q)
{
    q->front=q->rear=(QNodePtr)malloc(sizeof(QNode));
    if(!q->front)
        exit(0);
    q->front->next=NULL;
}

int QueueEmpty(QLinkList q)
{
    if(q.front == q.rear)
        return 1;
    return 0;
}

void InQueue(QLinkList *q, ElemType e)
{
    QNodePtr t;
    t = (QNodePtr)malloc(sizeof(QNode));
    if(!t)
        exit(0);
    t->next = NULL;
    t->data = e;
    q->rear->next = t;
    q->rear = t;
}

void DeQueue(QLinkList *q, ElemType *e)
{
    if(QueueEmpty(*q))
    {
        return;
    }
    QNodePtr t;
    t = q->front->next;
    *e = t->data;
    q->front->next = t->next;
    if(q->rear == t)
        q->front = q->rear;
    free(t);
}

void DestroyQueue(QLinkList *q) // 与小甲鱼视频上不一样，感觉视频上的不对
{
    while(q->rear!=q->front)
    {
        q->rear = q->front->next;
        free(q->front);
        q->front=q->rear;
    }
    free(q->front);
}

int main()
{
    QLinkList q;
    InitQueue(&q);
    char c, e;
    scanf("%c", &c);
    while(c!='#')
    {
        InQueue(&q, c);
        scanf("%c", &c);
    }
    while(!QueueEmpty(q))
    {
        DeQueue(&q, &e);
        printf("%c", e);
    }
    printf("\n");
    DestroyQueue(&q);

    return 0;
}
