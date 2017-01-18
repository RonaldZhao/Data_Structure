/* 静态链表的第i个位置 之前 插入新的数据元素e，分为两步完成 */

/* 首先是获得空闲分量的下标 */
int Malloc_SLL(StaticLinkList space)
{
    int i = space[0].cur;
    if( space[0].cur )
    {
        if( space[i].cur != MAXSIZE - 1)
        {
            // 独立出第一个备用分量，并把第二个备用分量重置为以后的第一个备用分量
            space[0].cur = space[i].cur;
        }
    }
    return i;
}

/* 然后就可以插入了 */
Status ListInsert(StaticLinkList space, int i, ElemType e)
{
    int j, k;
    k = MAXSIZE - 1;
    if( i < 1 || i > ListLength(space))
    {
        return ERROR;
    }
    j = Malloc_SLL(space);
    if( j )
    {
        space[j].data = e;
        for( int t = 1; t < i; t++)
        {
            k = space[k].cur;
        }
        space[j].cur = space[k].cur;
        space[k].cur = j;
        return OK;
    }
    return ERROR;
}