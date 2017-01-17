//初始条件：单链表L(带头结点)已存在，且 1 <= i <= ListLength(L)
//操作结果：把数据元素e插入到单链表的第i个数据元素之前，L的长度+1

Status ListInsert(LinkList *L, int i, ElemType e)
{
  int j;
  LinkList p, s;
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
  s = (LinkList)malloc(sizeof(Node)); //申请新结点空间
  s->data = e;        //将要插入的数据保存在新结点的数据域
  s->next = p->next;  //移动结点指针
  p->next = s;
  return OK;
}
