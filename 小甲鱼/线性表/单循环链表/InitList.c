/* 初始化循环链表 */
void InitList(node **pNode)
{
    int item;
    node *temp;
    node *target;
    
    printf("输入结点的值，输入0完成初始化：\n");

    while(1)
    {
        scanf("%d", &item);
        fflush(stdin);  // 强制刷新缓冲区
        
        if( item == 0 ) // 输入完毕
        {
            return;
        }

        if( (*pNode) == NULL )  // 循环链表中只有一个结点
        {
            *pNode = (node*)malloc(sizeof(struct CLinkList));
            if( !(*pNode) ) // 分配空间失败
            {
                exit(0);    // 异常退出
            }
            (*pNode)->data = item;
            (*pNode)->next = *pNode;
        }
        else
        {
            // 找到next指向第一个结点的结点
            for( target = (*pNode); target->next != (*pNode); terget = target->next )
            {
                ;
            }
            
            // 生成一个新的结点
            temp = (node *)malloc(sizeof(struct CLinkList));

            if( !item )
            {
                exit(0);
            }

            temp->data = item;
            temp->next = *pNode;
            target->next = temp;
        }
    }
}