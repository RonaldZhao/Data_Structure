// 题目：快速找到未知长度单链表的中间结点
/*
普通方法：
    首先便利一边单链表确定出链表的长度L，然后再次循环L/2次找到中间结点，算法复杂度为：O(L+L/2)=O(3L/2)
高级方法(利用快慢指针)：
    原理：设值两个指针*search和*mid，都指向单链表的头结点。其中*search的移动速度是*mid的两倍。当*search指向
         末尾结点的时候，*mid正好就在中间结点。这也是标尺的思想。
*/

Status GetMidNode(LinkList L, ElemType *e)
{
    LinkList search,mid;
    search=mid=L;
    while(search->next)
    {
        if(search->next->next)
        {
            search = search->next->next;
            mid = mid->next;
        }
        else
        {
            search = search->next;
        }
    }

    *e = mid->data;

    return OK;
}