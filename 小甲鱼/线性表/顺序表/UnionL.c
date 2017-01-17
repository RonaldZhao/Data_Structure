// La 表示 A 集合，Lb 表示 B 集合，实现两个集合的并集
void unionL(List *La, List Lb) {
  int La_len, Lb_len, i;

  ElemType e;
  La_len = ListLength(*La);
  Lb_len = ListLength(Lb);

  for (i = 1; i <= Lb_len; i++)
  {
    GetElem(Lb, i, &e);
    if (!LocateElem(*La, e)) //如果La中没有当前要插入的e元素
    {
      ListInsert(La, ++La_len, e);
    }
  }
}
