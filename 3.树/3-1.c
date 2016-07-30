/*
静态查找
  方法1：顺序查找
  方法2：二分查找（Binary Search）
二分查找判定树：
  *判定树上每个结点需要的查找次数刚好为该结点所在的层数；
  *查找成功时查找次数不会超过判定树的深度
  *n个结点的判定树的深度为[log_2(n)]+1
  *ASL，平均查找次数
树的一些基本术语：
  1.结点的度（Degree）：结点的子树个数
  2.树的度：树的所有结点中最大的度数
  3.叶结点（Leaf）：度为0的结点
  4.父节点（Parent）：有子树的结点是其子树的根结点的父结点
  5.子结点（Child）：若A结点是B结点的父结点，则称B结点是A结点的子结点，子结点也称为孩子结点
  6.兄弟结点（Sibling）：具有同一父结点的各结点彼此是兄弟结点
  7.路径和最长路径：路径是一个结点序列，路径所包含的边的个数为路径的长度
  8.祖先结点（Ancestor）：沿树根到某一结点路径上的所有结点都是这个结点的子孙
  9.子孙结点（Descendant）：某一结点的子树中的所有结点都是这个结点的子孙
  10.结点的层次（Level）：规定根结点在1层，其他任一结点的层数是其父结点的层数+1
  11.树的深度（Depth）：树中所有结点中的最大层次是这棵树的深度
树的表示：
 儿子-兄弟表示法——>二叉树
 二叉树的子树有左右顺序之分
 特殊二叉树：
  *斜二叉树（Skewed Binary Tree）
  *完美二叉树）（Perfect B T）== 满二叉树(Full B T)
  *完全二叉树（Complete B T）
二叉树常用的遍历方法：
  *void PreOrderTraversal(BinTree BT);//先序---根->左子树->右子树
  *void InorderTraversal(BinTree BT);//中序---左子树->根->右子树
  *void PostorderTraversal(BinTree BT);//后序---左子树->右子树->根
  *void LevelorderTraversal(BinTree BT);//层次遍历，从上到下、从左到右
*/
/*二叉树的链表结构：
typedef struct TNode *Position;
typedef Position BinTree; // 二叉树类型
struct TNode{ //树结点定义
    ElementType Data; // 结点数据
    BinTree Left;     // 指向左子树
    BinTree Right;    // 指向右子树
};
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
