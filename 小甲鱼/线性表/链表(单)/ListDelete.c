//初始条件：单链表L(带头结点)已存在且 1<= i <= ListLength(L)
//操作结果：删除单链表L的第i个数据元素并用e返回其值，L的长度-1

Status ListDelete(LinkList *L, int i, ElemType *e)
{
  int j;
  LinkList p, q;
  p = *L;
  j = 1;
  while (p && j < i)  //定位插入位置
  {
    p = p->next;
    ++j;
  }
  if (!p || j > i)    //未找到或插入位置不合法
  {
    return ERROR;
  }
  q = p->next;        //记录要删除的结点
  p->next = q->next;  //删除数据元素的结点
  *e = q->data;       //返回删除的数据元素的值
  free(q);            //释放删除的数据元素的空间
  return OK;
}
