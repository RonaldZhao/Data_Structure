
/*
约瑟夫问题：41个人轮流自杀，排成一个圆圈，从第一个人开始报数，每报到3的自杀，直到死光。
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}node;

node *create(int n)
{
    node *p=NULL,*head;
    head=(node*)malloc(sizeof(node));
    p=head;
    node *s;
    int i=1;

    if(n)
    {
        while(i<=n)
        {
            s=(node*)malloc(sizeof(node));
            s->data=i++;
            p->next=s;
            p=s;
        }
        s->next=p->next;
    }
    free(head);
    return s->next;
}

int main()
{
    int n=41;
    int m=3;
    int i;
    node *p=create(n);
    node *temp;
    m %= n;
    while(p!=p->next)
    {
        for(i=1;i<m-1;i++)
        {
            p=p->next;
        }
        printf("%d->",p->next->data);
        temp=p->next;
        p->next=temp->next;
        free(temp);
        p=p->next;
    }
    printf("%d\n",p->data);//输出最后一个
    return 0;
}

/*
课后题：
    编号为1~N的N个人按顺时针方向围坐一圈，每人持有一个密码(正整数，可以自由输入)，开始人选一个正整数作为报数上限值M，
    从第一个人按顺时针方向自1开始顺序报数，报到M时停止报数。报M的人出列，将他的密码作为新的M值，从他顺时针方向的下一人
    开始从1报数，直到所有人全部出列为止。
*/