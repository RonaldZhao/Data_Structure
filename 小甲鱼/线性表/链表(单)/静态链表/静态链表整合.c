/*
静态链表优缺点总结：
优点：
    在插入和删除操作时，只需要修改游标，不需要移动元素，从而改进了在顺序存储结构中的插入和删除操作需要移动大量元素的缺点。
缺点：
    没有解决连续存储分配(数组)带来的表长难以确定的问题；
    失去了顺序存储结构随机存取的特点。
*/
// 用数组描述的链表称为静态链表。
// 线性表的静态链表存储结构：
#define MAXSIZE 1000
typedef struct
{
    ElemType data;  // 数据
    int cur;        // 游标
}Component, StaticLinkList[MAXSIZE];
// 第一个和最后一个结点的数据域不用

// 对静态链表初始化相当于初始化数组
Status InitList(StaticLinkList space)
{
    int i;
    for(i=0;i<MAXSIZE-1;i++)
    {
        space[i].cur=i+1;// 指向下一个结点的游标(下标)
    }
    space[MAXSIZE-1].cur=0;
    return OK;
}
/*
注意：
    1.要对数组的第一个和最后一个元素做特殊处理，它们的data域不存放数据
    2.通常把未使用的数组元素称为备用链表
    3.数组的第一个元素，即下标为0的那个元素的cur就存放备用链表的第一个结点的下标
    4.数组的最后一个元素，即下标为MAXSIZE-1的cur则存放第一个有数值的元素的下标，相当于单链表中的头结点作用
*/

// 静态链表的插入操作
// 首先是获得静态分量的下标
int Malloc_SLL(StaticLinkList space)
{
    int i=space[0].cur;
    if(space[0].cur)
    {
        space[0].cur=space[i].cur;// 把它的下一个分量用来作为备用
    }
    return i;
}

// 返回L中数据元素的个数
int ListLength(StaticLinkList L)
{
    int len=0;
    int i=L[MAXSIZE-1].cur;
    // 根据最后一个有数据元素的游标一定是0
    while(i)
    {
        i=L[i].cur;
        len++;
    }
    return len;
}

/* 在静态链表L中第i个位置 之前 插入新的数据元素e */
Status ListInsert(StaticLinkList L, int i, ElemType e)
{
    int j,k;
    k = MAXSIZE-1;
    if(i < 1 || i > ListLength(L) + 1)  // ListLength(L)+1 ?为什么要+1？
    {
        return ERROR;
    }

    j = Malloc_SLL(L);
    if(j)
    {
        L[j].data=e;
        for(int l = 1; l < i; l++)
        {
            k = L[k].cur; // 直到找到第i个元素的下标
        }
        L[j].cur = L[k].cur;
        L[k].cur = j;
        return OK;
    }
    return ERROR;
}
//静态链表元素的删除
Status ListDelete(StaticLinkList L, int i)
{
    int i,j;
    if(i<1||i>ListLength(L))
    {
        return ERROR;
    }
    k=MAXSIZE-1;
    for(j=1;j<i-1;j++)
    {
        k=L[k].cur;
    }
    j=L[k].cur;
    L[k].cur=L[j].cur;
    Free_SLL(L,j);
    return OK;
}

//将下标为k的空闲结点回收到空闲链表
void Free_SLL(StaticLinkList space,int k)
{
    space[k].cur=space[0].cur;
    space[0].cur=k;
}