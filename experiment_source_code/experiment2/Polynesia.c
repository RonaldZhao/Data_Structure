#include "Polynesia.h"
#include<conio.h>
int main() {
  pPOLYN pa = NULL, pb = NULL;
  printf("请输入第一个多项式的数据：\n");
  PolynInput(&pa);
  printf("\n请输入第二个多项式的数据：\n");
  PolynInput(&pb);
  PolynAdd(pa, pb);
  printf("两个多项式之和为：");
  PolynPrint(pa);

  _getch();
  return 0;
}
