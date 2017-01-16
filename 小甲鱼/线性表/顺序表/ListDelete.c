// 初始条件：顺序表L已存在并不为空，且 1 <= i <= ListLength(L)
// 操作结果：把L的第 i 个位置的数据元素删除，并用e返回其值，L的长度-1

Status ListDelete(SqList *L, int i, ElemType *e)
{
  // 顺序表 L 存在但为空
  if (L->length == 0)
  {
    return ERROR;
  }
  // 要删除的位置 i 不合法
  if (i < 1 || i > L->length) {
    return ERROR;
  }
  *e = L->data[i - 1]; //把要删除的数据元素的值保存在e中
  // 如果删除的元素不是最后一个
  if (i < L->length)
  {
    // 将顺序表L的第 i 个位置及之后的所有元素都向前移动一位
    for (; i < L->length; i++)
    {
      L->data[i - 1] = L->data[i];
    }
  }
  --L->length; //将顺序表的长度-1
  return OK;
}
