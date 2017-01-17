#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0

typedef char ElemType;
typedef int Status;

//双向链表结点结构的定义
typedef struct DualNode
{
    ElemType data;
    struct DualNode *prior;     //前驱结点
    struct DualNode *next;      //后继结点
}DualNode,*DuLinkList;

Status InitList(DuLinkList *L)
{
    DualNode *p,*q;
    int i;

    *L = (DuLinkList)malloc(sizeof(DualNode));
    if( !(*L))
    {
        return ERROR;
    }
    (*L)->next=(*L)->prior=NULL;
    p=(*L);

    for(i=0;i<26;i++)
    {
        q = (DualNode *)malloc(sizeof(DualNode));
        if( !q )
        {
            return ERROR;
        }
        q->data = 'A'+i;
        q->prior=p;
        q->next=p->next;
        p->next=q;

        p=q;
    }
    p->next=(*L)->next;
    (*L)->next->prior=p;

    return OK;
}

void Caesar(DuLinkList *L, int i)
{
    if( i>0 )
    {
        do
        {
            (*L)=(*L)->next;
        }while( --i );
    }

    if( i<0 )
    {
        do
        {
            (*L)=(*L)->next;
        }while( ++i );
    }
}

int main()
{
    DuLinkList L;
    int i, n;

    InitList(&L);

    printf("Please Input a number:\n");
    scanf("%d",&n);
    Caesar(&L, n);

    for(i=0;i<26;i++)
    {
        L=L->next;
        printf("%c",L->data);
    }

    printf("\n");
    
    return 0;
}