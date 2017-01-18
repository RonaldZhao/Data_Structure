/* 返回静态链表的当前长度 */
int ListLength(StaticLinkList space)
{
    int len = 0;
    int i = space[MAXSIZE - 1].cur;
    while(i)
    {
        ++len;
        i = space[i].cur;
    }
    return len;
}