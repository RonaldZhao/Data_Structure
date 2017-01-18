/* 静态链表的初始化相当于初始化数组，在这里就是初始化各元素的游标。*/
Status InitList(StaticLinkList space)
{
    for(int i = 0; i < MAXSIZE - 1; i++)
    {
        space[i].cur = i+1;
    }
    space[MAXSIZE-1].cur = 0;
    return OK;
}