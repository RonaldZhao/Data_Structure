/* 删除静态链表的第i个元素的操作 */

// 将要删除元素回收到备用链表
void Free_SLL(StaticLinkList space, int i)
{
    space[i].cur = space[0].cur;
    space[0].cur = i;
}

Status ListDelete(StaticLinkList space, int i)
{
    int j, k;
    if( i < 1 || i > ListLength(space) )
    {
        return ERROR;
    }

    j = MAXSIZE - 1;
    for( j = 1; j < i - 1; j++)
    {
        j = space[j].cur;
    }
    k = space[j].cur;   // k是要删除元素的下标
    space[j].cur = space[k].cur;
    Free_SLL(space, k);
    return OK;
}