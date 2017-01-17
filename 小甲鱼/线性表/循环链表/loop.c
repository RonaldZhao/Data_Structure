//初始化循环链表

//两个循环链表的连接
LinkList Connect(LinkList A, LinkList B)//A、B分别指向两个链表的表尾
{
    LinkList p = A->next;
    A->next = B->next->next;
    free(B->next);
    B->next=p;
    return B;
}

/*
判断单链表中是否有环
    主要有以下两种方法：
    方法一：
        使用p、q两个指针，p总是向前走，但是q每次都从头开始走；对于每个结点，看p走的步数和q是否一样。当到达同一个结点时，
        若p和q走的步数不一样，则存在环。
    方法二：
        使用p、q两个指针，p每次向前走一步，q每次向前走两步，若存在某个时刻p==q，则存在环。
*/
//比较步数的方法
int HasLoop1(LinkList L)
{
    LinkList cur1 = L;
    int pos1 = 0;
     while(cur1)
     {
         LinkList cur2 = L;
         int pos2 = 0;
         while(cur2)
         {
             if(cur2==cur1)
             {
                 if(pos1==pos2)
                 {
                    break;
                 }
                else
                {
                    printf("环的位置在第%d个结点处。\n\n", pos2);
                    return 1;
                }
             }
             cur2 = cur2->next;
             pos2++;
         }
         cur1 = cur1->next;
         pos1++;
     }
     return 0;
}

//快慢指针方法
int HasLoop2(LinkList L)
{
    int step1 = 1;
    int step2 = 2;
    LinkList p,q;
    p = q = L;
    while(p && q && q->next)
    {
        p = p->next;
        if(q->next)
        {
            q = q->next->next;
        }
        printf("p:%d,q:%d\n",p->data,q->data);
        if(p==q)
        {
            return 1;
        }
    }
    return 0;
}