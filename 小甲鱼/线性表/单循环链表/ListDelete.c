/* 删除结点 */
void ListDelete(node **pNode, int i)
{
    node *target;
    node *temp;
    int j = 1;

    if( i == 1 )    // 删除的是第一个结点
    {
        // 找到最后一个结点
        for( target = *pNode; target->next != *pNode; target=target->next)
        {
            ;
        }

        temp = *pNode;  // 获取第一个结点
        *pNode = (*pNode)->next;    // 更改第一个结点
        target->next = *pNode;  // 更改尾结点的指向
        free(temp); // 释放空间
    }
    else
    {
        target = *pNode;    // 获取第一个结点

        for( ; j < i - 1; ++j)  // 找到要删除结点的前一个结点
        {
            target = target->next;
        }

        temp = target->next;    // 获取眼删除的结点
        target->next = temp->next;  // 跳过要删除的结点
        free(temp); // 释放空间
    }
}