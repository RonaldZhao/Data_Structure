/* 线性表的静态链表存储结构 */
#define MAXSIZE 1000
typedef struct
{
    ElemType data;  //数据域
    int cur;        //游标
}Component, StaticLinkList[MAXSIZE];
/*
注意：
    静态链表的下标为0和下标为MAXSIZE-1的元素的数据域都不存放任何东西。
    并且约定：下标为0的元素的游标存放第一个没有数据的元素的下标；
             下标为MAXSIZE-1的元素的游标存放第一个有数据的元素的下标；
             而其他的元素的游标都是指向下一个元素的下标。
*/