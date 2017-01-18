/*
在单循环链表中插入结点
参数：链表的第一个结点pNode，插入位置i
*/
void ListInsert(node **pNode, int i)
{
    node *temp;
    node *target;
    node *p;
    int item;
    int j = 1;

    printf("请输入要插入的结点的值：");
    scanf("%d", &item);

    if( i == 1 )    // 新插入的结点作为第一个结点
    {
        temp = (node*)malloc(sizeof(struct CLinkList));

        if( !item )
        {
            exit(0);
        }

        // 寻找到最后一个结点
        for( target = (*pNode); target->next != (*pNode); target = target->next )
        {
            ;
        }
        temp->data=item;
        temp->next = (*pNode);
        target->next = temp;
        *pNode = temp;
    }
    else
    {
        target = *pNode;

        for( ; j < (i - 1); ++j)
        {
            target = target->next;
        }

        temp = (node *)malloc(sizeof(struct ClinkList));

        if( !temp )
        {
            exit(0);
        }

        temp->data = item;

        p = target->next;
        target->next = temp;
        temp->next = p;
    }
}