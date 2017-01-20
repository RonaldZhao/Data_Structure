/*
魔术师发牌问题，循环链表实现。
*/

#include <stdio.h>
#include <stdlib.h>

#define CardNumber 13

typedef struct node
{
    int data;
    struct node *next;
}sqlist,*LinkList;

LinkList CreateLinkList()
{
    LinkList head=NULL;
    LinkList s,r;
    int i;

    r=head;

    for(i=1;i<=CardNumber;i++)
    {
        s=(LinkList)malloc(sizeof(sqlist));
        s->data=0;

        if(head==NULL)
            head=s;
        else
            r->next=s;
        r=s;
    }
    r->next=head;
    return head;
}

// 发牌顺序计算
void Magician(LinkList head)
{
    LinkList p;
    int j;
    int Countnumber=2;
    p=head;
    p->data=1;
    while(1)
    {
        for(j=0;j<Countnumber;j++)
        {
            p=p->next;
            if(p->data!=0)
            {
                j--;
            }
        }
        p->data=Countnumber;
        Countnumber++;
        if(Countnumber > CardNumber)
        {
            break;
        }
    }
}

// 销毁
void DestroyList(LinkList *list)
{
    LinkList ptr = *list;
    LinkList temp;
    int i = 0;
    
    while(i < CardNumber)
    {
        temp = ptr;
        ptr = ptr->next;
        i++;
        free(temp);
    }
}

int main()
{
    LinkList p;
    int i;

    p=CreateLinkList();
    Magician(p);
    printf("应按如下顺序排列：\n");
    for(i=0;i<CardNumber;i++)
    {
        printf("黑桃%d\t",p->data);
        p=p->next;
    }

    DestroyList(&p);
    
    return 0;
}