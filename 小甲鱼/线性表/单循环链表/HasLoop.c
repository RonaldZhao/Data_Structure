/*
判断单链表中是否有环(尾结点的next指向之前的某个结点)
    主要有以下两种方法：
    方法一：比较步数法
        使用p、q两个指针，p总是向前走，但是q每次都从头开始走；对于每个结点，看p走的步数和q是否一样。当到达同一个结点时，
        若p和q走的步数不一样，则存在环。
    方法二：快慢指针法
        使用p、q两个指针，p每次向前走一步，q每次向前走两步，若存在某个时刻p==q，则存在环。
*/
// 比较步数的方法
int HasLoop1(LinkList L)
{
    LinkList p = L;
    int step1 = 0;
    while(p)
    {
        LinkList q= L;
        int step2 = 0;
        while(q)
        {
            if(q==p)
            {
                if(step1==step2)
                {
                   break;
                }
               else
               {
                   printf("环的位置在第%d个结点处。\n\n", step2);
                   return 1;
               }
            }
            q = q->next;
            step2++;
        }
        p = p->next;
        step1++;
    }
    return 0;
}

// 快慢指针方法
int HasLoop2(LinkList L)
{
    LinkList p,q;
    p = q = L;
    while(p && q && q->next)    // 只要有一个为NULL，就说明不存在环
    {
        p = p->next;
        q = q->next->next;
        printf("p:%d,q:%d\n",p->data,q->data);
        if(p == q)
        {
            return 1;
        }
    }
    return 0;
}