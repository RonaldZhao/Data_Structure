/*
线性表的抽象数据类型描述
类型名称：线性表（List）
数据对象集：
操作集：
*/
#include <stdio.h>
#include <stdlib.h>
#define ElementType int

typedef struct LNode *List;
struct LNode {
  ElementType Data[MAXSIZE];
  int Last;
};
struct LNode L;
List PtrL;

//--------------------顺序存储---------------------------
List MakeEmpty() {
  List PtrL;
  PtrL = (List)malloc(sizeof(struct LNode));
  PtrL->Last = -1;
  return PtrL;
}

int Search(ElementType X, List PtrL) {
  int i = 0;
  while (i <= PtrL->Last && PtrL->Data[i] != X) {
    i++;
  }
  if (i > PtrL->Last)
    return -1;
  else
    return i;
}

void Insert(ElementType X, int i, List PtrL) {
  int j;
  if (PtrL->Last == MAXSIZE - 1) {
    printf("表满！\n");
    return;
  }
  if (i < 1 || i > PtrL->Last + 2) {
    printf("位置不合法！\n");
    return;
  }
  for (j = PtrL->Last; j >= i - 1; j--) {
    PtrL->Data[j + 1] = PtrL->Data[j];
  }
  PtrL->Data[i - 1] = X;
  PtrL->Last++;
  return;
}

void Delete(int i, List PtrL) {
  int j;
  if (i < 1 || i > PtrL->Last + 1) { //检查要删除的位置的合法性
    printf("不存在第%d个元素！请重新输入！\n", i);
    return;
  }
  for (j = i; j <= PtrL->Last; j++) {
    PtrL->Data[j - 1] =
        PtrL->Data[j]; //将要删除元素后边的元素一次向前移动一个位置
  }
  PtrL->Last--; // List仍指向最后元素但是减一个
  return;
}
//-----------------------顺序存储END------------------------
typedef struct LNode *List;
struct LNode {
  ElementType Data;
  List next;
};

int Length(List PtrL) {
  List p = PtrL;
  int j = 0;
  while (p) {
    p = p->next;
    j++;
  }
  return j;
}

List FindKth(int k, List PtrL) {
  List p = PtrL;
  while (p != NULL && i < k) {
    p = p->next;
    i++;
  }
  if (i == k)
    return p;
  else
    return NULL;
}

List Find(ElementType X, List PtrL) {
  List p = PtrL;
  while (p != NULL && p->Data != X)
    p = p->next;
  return p;
}

List Insert(ElementType X, int i, List PtrL) {
  List p, s;
  if (i == 1) { //若新结点插入在表头
    s = (List)malloc(sizeof(struct LNode));
    s->Data = X;
    s->next = PtrL;
    return s; //返回新表头指针
  }
  p = FindKth(i - 1, PtrL); //查找第i-1个结点
  if (p == NULL) {          //第i-1个不存在，不能插入
    printf("参数i错误\n");
    return NULL;
  } else {
    s = (List)malloc(sizeof(struct LNode));
    s->Data = X;
    s->next = p->next; //新结点插入在第i-1个结点后面
    p->next = s;
    return PtrL; //返回新表头指针
  }
}

List Delete(int i, List PtrL) {
  List p, s;
  if (i == 1) { //若要删除的是第一个结点
    s = PtrL;
    if (PtrL != NULL)
      PtrL = PtrL->next;
    else
      return NULL;
    free(s); //释放被删除的结点
    return PtrL;
  }
  p = FindKth(i - 1, PtrL);
  if (p == NULL) {
    printf("第%d个结点不存在\n", i - 1);
    return NULL;
  } else if (p->next == NULL) {
    printf("第%d个结点不存在\n", i);
    return NULL;
  } else {
    s = p->next;
    p->next = s->next;
    free(s); //释放被删除的结点
    return PtrL;
  }
}
