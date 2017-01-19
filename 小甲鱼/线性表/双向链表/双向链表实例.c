/*
——要求实现用户输入一个数使得26个字母的排列发生变化，例如输入3，输出结果为：
    DEFGHIJKLMNOPQRSTUVWXYZABC
——同时需要支持负数，例如输入-3，输出结果为：
    XYZABCDEFGHIJKLMNOPQRSTUVW
*/
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
}DualNode,*DualLinkList;

Status InitList(DualLinkList *L)    // 创建并初始化双向链表，完成后链表存在头指针
{
    DualNode *p,*q;
    int i;

    *L = (DualLinkList)malloc(sizeof(DualNode));
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
        // 以下四行是关键步骤
        q->prior=p;
        q->next=p->next;
        p->next=q;
        p=q;
    }
    p->next=(*L)->next;
    (*L)->next->prior=p;

    return OK;
}

void Caesar(DualLinkList *L, int i) // 本质就是移动头指针的位置（指向）
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
        (*L) = (*L)->next->prior;
		do
		{
			(*L) = (*L)->prior;
        }while( ++i );
    }
}

int main()
{
    DualLinkList L;
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
/*
课后作业：
Vigenere（维吉尼亚）加密：
——当输入明文，自动生成随机密匙匹配明文中每个字母并移位加密。
    如：
          明文   I L  O  V E  F I  S  H  C
        随机密匙 3 15 23 2 52 1 33 49 13 19
          密文   L A  L  X E  G P  P  U  V
——建议：由于随机密匙生成后不能丢掉，否则就很难把明文还原回来了，建议把密匙和密文加密存储在一起。
*/