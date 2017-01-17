//初始条件：单链表L(带头结点)已存在，且1 <= i <= ListLength(L)
//操作结果：用e返回L中第i个数据元素的值
//核心思想：工作指针后移

Status getElem(LinkList L, int i, ElemType *e)
{
  int j;
  LinkList p;
  p = L->next;         //让p指向链表L的第一个结点
  j = 1;               //用作计数器
  while (p && j < i)   //当遍历完链表L或找到了第i个数据元素时结束
  {
    p = p->next;
    ++j;
  }
  if (!p || j > i)     //未找到第i个数据元素
  {
    return ERROR;
  }
  *e = p->data;        //用e返回取到的第i个数据元素的值
  return OK;
}
