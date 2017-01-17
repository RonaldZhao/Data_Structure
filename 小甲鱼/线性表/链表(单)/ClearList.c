/* 单链表的整表删除 */
Status ClearList(LinkList *L)
{
    LinkList p, q;
    p = (*L)->next;
    while(p)
    {
        q=p->next;
        free(p);
        p=q;
    }
    (*L)->next=NULL;    //重新初始化头结点
    return OK
}