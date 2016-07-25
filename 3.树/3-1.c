/*
静态查找
  方法1：顺序查找
  方法2：二分查找（Binary Search）
二分查找判定树：
  *判定树上每个结点需要的查找次数刚好为该结点所在的层数；
  *查找成功时查找次数不会超过判定树的深度
  *n个结点的判定树的深度为[log_2(n)]+1
  *ASL，平均查找次数
*/
typedef struct LNode *List;
struct LNode {
  ElementType Element[MAXSIZE];
  int length;
};

//顺序查找的一种实现（无“哨兵”）
int SequentialSearch(
    List Tbl,
    ElementType k) { //在Element[1]~Element[n]中查找关键字为k的数据元素
  int i;
  for (i = Tbl->length; i > 0 && Tbl->Element[i] != k; i--) {
    ;
  }
  return i; //查找成功返回所在单元下标，不成功返回0
}

//顺序查找的另一种实现（有“哨兵”）
int SequentialSearch(
    List Tbl,
    ElementType k) { //在Element[1]~Element[n]中查找关键字为k的数据元素
  int i;
  Tbl->Element[0] = k; //建立哨兵
  for (i = Tbl->length; Tbl->Element[i] != k; i--)
    ;
  return i; //查找成功返回所在单元下标，不成功返回0
}
//二分查找
int BinarySearch(List Tbl, ElementType k) {
  int left, right, mid, NotFound = -1;

  left = 1;
  right = Tbl->length;
  while (left <= right) {
    mid = (left + right) / 2;
    if (k < Tbl->Element[mid])
      right = mid - 1;
    else if (k > Tbl->Element[mid])
      left = mid + 1;
    else
      return mid;
  }
  return NotFound;
}
