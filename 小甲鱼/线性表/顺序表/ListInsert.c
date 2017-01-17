//初始条件：顺序表L已存在，且 1 <= i <= ListLength(L)
//操作结果：在L中第i个位置之前插入新的数据元素e，L长度+1

Status ListInsert(SqList *L, int i, ElemType e)
{
  // 顺序线性表已经满了
  if (L->length >= MAXSIZE)
  {
    return ERROR;
  }
  // 插入位置i不符合条件
  if (i < 1 || i > L->length + 1)
  {
    return ERROR;
  }
  // 如果插入位置 i 不在顺序表的表尾
  if (i <= L->length)
  {
    // 将要插入的位置的后面的数据元素都向后移动一位
    for (int k = L->length - 1; k >= i - 1; k--)
    {
      L->data[k + 1] = L->data[k];
    }
  }
  L->data[i - 1] = e; //将要插入的新数据元素e插入
  ++L->length;
  return OK;
}
