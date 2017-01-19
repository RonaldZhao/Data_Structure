//两个单循环链表的连接，返回新循环链表的尾指针
LinkList ConnectList(LinkList A, LinkList B)    // A、B分别为两个非空循环链表的表指针
{
    LinkList p = A->next;   // 保存A表的第一个结点的位置
    A->next = B->next->next;// B表的第一个结点连接到A的表尾
    free(B->next);
    B->next=p;
    return B;
}