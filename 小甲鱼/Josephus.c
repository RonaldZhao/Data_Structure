
/*
约瑟夫问题：41个人轮流自杀，排成一个圆圈，从第一个人开始报数，每报到3的自杀，直到死光。
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node *create(int n) // 生成长度为n的单循环链表
{
    node *p = NULL, *head;
    head = (node *)malloc(sizeof(node)); // 头结点
    p = head;                            // p为游标结点
    node *s;
    int i = 1;

    if (n)
    {
        while (i <= n)
        {
            s = (node *)malloc(sizeof(node));
            s->data = i++;
            p->next = s;
            p = s;
        }
        s->next = head->next; // 尾结点的next指向头结点的next构成单循环
    }
    free(head);     // 销毁头结点
    return s->next; // 返回第一个结点
}

int main()
{
    int n = 41; // 人数
    int m = 3;  // 报数长度
    int i;
    node *p = create(n); // 生成链表
    node *temp;
    m %= n;
    while (p != p->next)
    {
        for (i = 1; i < m - 1; i++)
        {
            p = p->next;
        }
        printf("%d->", p->next->data);
        temp = p->next;       // 记录当前自杀结点
        p->next = temp->next; // 删除当前自杀结点
        free(temp);           // 释放空间
        p = p->next;
    }
    printf("%d\n", p->data); //输出最后一个
    free(p);
    return 0;
}

/*
课后题：
    编号为1~N的N个人按顺时针方向围坐一圈，每人持有一个密码(正整数，可以自由输入)，开始人选一个正整数作为报数上限值M，
    从第一个人按顺时针方向自1开始顺序报数，报到M时停止报数。报M的人出列，将他的密码作为新的M值，从他顺时针方向的下一人
    开始从1报数，直到所有人全部出列为止。
*/