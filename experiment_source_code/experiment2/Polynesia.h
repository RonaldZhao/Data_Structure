#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0

typedef struct polyn //定义多项式的结构
{
  float coef;         //系数项
  int expn;           //指数项
  struct polyn *next; //指向下一项
} POLYN, *pPOLYN;

void PolynInput(pPOLYN *);           //输入一元多项式
void PolynPrint(pPOLYN);           //输出一元多项式
void PolynAdd(pPOLYN pa, pPOLYN pb); //多项式相加
void PolynSub(pPOLYN pa, pPOLYN pb); //多项式相减
void PolynSubInverse(pPOLYN p);      //逆置多项式

void PolynInput(pPOLYN *p) //输入一元多项式
{
  int i, min = INT_MIN; // INT_MIN为int型的最小数
  pPOLYN p1, p2;
  if (!(*p = (POLYN *)malloc(sizeof(POLYN)))) {
    printf("内存分配失败！\n");
    exit(0);
  }
  (*p)->coef = 0; //设置头结点的系数为0
  printf("请输入该多项式的系数：");
  scanf("%d", &((*p)->expn)); //使用头结点的指数域保存项数
  (*p)->next = NULL;
  for (i = 0; i < (*p)->expn; i++) //输入多项式的各项
  {
    if (!(p1 = (pPOLYN)malloc(sizeof(POLYN)))) //分配保存一个多项式项的内存空间
    {
      printf("内存分配失败！\n");
      exit(0);
    }
    printf("第%d项系数:", i + 1);
    scanf("%f", &(p1->coef));
    do {
      printf("第%d项指数:", i + 1);
      scanf("%d", &(p1->expn));
      if (p1->expn < min) {
        printf("\n当前项指数值不能小于前一项指数值%d!\n请重新输入!\n",
               (*p)->next->expn);
      }
    } while (p1->expn < min); //使每一项的指数为递增
    min = p1->expn;           //保存本次输入的指数作为参数依据
    p1->next = (*p)->next; //将结点插入到链表中(插入到链表头后面的第一个位置)
    (*p)->next = p1;
  }
  p1 = (*p)->next; //合并多项式中指数值相同的项
  while (p1) {
    p2 = p1->next;                       //取下一个结点
    while (p2 && p2->expn == p1->expn) { //若结点有效，则两个结点的指数相同
      p1->coef += p2->coef;              //累加系数
      p1->next = p2->next; //删除p1和p2指向的结点(p1和p2在链表)
      free(p2);            //释放p2结点占用的内存
      p2 = p1->next;       //处理下一个结点
      (*p)->expn--;        //总结点数减 1
    }
    p1 = p1->next;
  }
} // PolynInput

void PolynPrint(pPOLYN p) //输出一元多项式
{
  pPOLYN p1;
  int i;
  printf("\n\n计算后的多项式共有%d项。\n", p->expn);
  p1 = p->next;
  i = 1;
  while (p1) {
    printf("第%d项-->系数：%g，指数：%d\n", i++, p1->coef, p1->expn);
    p1 = p1->next;
  }
  printf("\n");
} // PolynPrint

void PolynAdd(pPOLYN pa, pPOLYN pb) //多项式相加
{
  pPOLYN pa1, pb1, pc1, p;
  pa1 = pa->next; //指向被加链表的第一个有效值
  pb1 = pb->next; //指向被加链表的第一个有效值
  pc1 = pa;       //指向被加链表
  pc1->next = NULL;
  pa->expn = 0;                  //清空多项式项的数量
  while (pa1 && pb1) {           //两个多项式都未结束
    if (pa1->expn > pb1->expn) { // pa1指数大于pb1指数
      pc1->next = pa1;           //将pa1加入到结果链表中
      pc1 = pa1;
      pa1 = pa1->next; //处理pa1中的下一项
      pc1->next = NULL;
    } else if (pa1->expn < pb1->expn) { // pa1指数小于pb1指数
      pc1->next = pb1;                  //将pb1加入到结果链表中
      pc1 = pb1;
      pb1 = pb1->next; //处理pb1中的下一项
      pc1->next = NULL;
    } else {                  // pa1和pb1指数相等
      pa1->coef += pb1->coef; //累加系数求和
      if (pa1->coef) {        //若系数不为零
        pc1->next = pa1;      //将相加结果添加到结果链表中
        pc1 = pa1;
        pa1 = pa1->next; //处理pa1中的下一项
        pc1->next = NULL;
        p = pb1;
        pb1 = pb1->next; //处理pb1中的下一项
        free(p);
      } else {           //系数为0，则不记录该项
        p = pa1;         //用临时指针指向pa1中的该项
        pa1 = pa1->next; //从链表中删除该项
        free(p);         //释放该项占用的内存
        p = pb1;         //用临时指针指向pb1中的该项
        pb1 = pb1->next; //从链表中删除该项
        free(p);         //释放该项占用的内存
        pa->expn--;      //后面会进行累加操作，所以此处先减一
      }
    }
    pa->expn++; //累加一个结果项
  }
  if (pa1) {         //若pa1中还有项
    pc1->next = pa1; //将pa1中的项添加到结果链表中
    while (pa1) {
      pa->expn++;
      pa1 = pa1->next;
    }
  }
  if (pb1) {         //若pb1中还有项
    pc1->next = pb1; //将pb1中的项添加到结果链表中
    while (pa1) {
      pa->expn++;
      pb1 = pb1->next;
    }
  }
  free(pb);
} // PolynAdd

void PolynSub(pPOLYN pa, pPOLYN pb) //多项式相减
{
  pPOLYN pa1, pb1, pc1, p;
  pa1 = pa->next; //指向被加链表的第一个有效值
  pb1 = pb->next; //指向被加链表的第一个有效值
  pc1 = pa;       //指向被加链表
  pc1->next = NULL;
  pa->expn = 0;                  //清空多项式项的数量
  while (pa1 && pb1) {           //两个多项式都未结束
    if (pa1->expn > pb1->expn) { // pa1指数大于pb1指数
      pc1->next = pa1;           //将pa1加入到结果链表中
      pc1 = pa1;
      pa1 = pa1->next; //处理pa1中的下一项
      pc1->next = NULL;
    } else if (pa1->expn < pb1->expn) { // pa1指数小于pb1指数
      pb1->coef *= -1;                  //将pb1系数修改为负数
      pc1->next = pb1;                  //将pb1加入到结果链表中
      pc1 = pb1;
      pb1 = pb1->next; //处理pb1中的下一项
      pc1->next = NULL;
    } else {                  // pa1和pb1指数相等
      pa1->coef -= pb1->coef; //累加系数求和
      if (pa1->coef) {        //若系数不为零
        pc1->next = pa1;      //将相加结果添加到结果链表中
        pc1 = pa1;
        pa1 = pa1->next; //处理pa1中的下一项
        pc1->next = NULL;
        p = pb1;
        pb1 = pb1->next; //处理pb1中的下一项
        free(p);
      } else {           //系数为0，则不记录该项
        p = pa1;         //用临时指针指向pa1中的该项
        pa1 = pa1->next; //从链表中删除该项
        free(p);         //释放该项占用的内存
        p = pb1;         //用临时指针指向pb1中的该项
        pb1 = pb1->next; //从链表中删除该项
        free(p);         //释放该项占用的内存
        pa->expn--;      //后面会进行累加操作，所以此处先减一
      }
    }
    pa->expn++; //累加一个结果项
  }
  if (pa1) {         //若pa1中还有项
    pc1->next = pa1; //将pa1中的项添加到结果链表中
    while (pa1) {
      pa->expn++;
      pa1 = pa1->next;
    }
  }
  if (pb1) {         //若pb1中还有项
    pc1->next = pb1; //将pb1中的项添加到结果链表中
    while (pa1) {
      pb1->coef *= -1;
      pa->expn++;
      pb1 = pb1->next;
    }
  }
  free(pb);
} // PolynSub

void PolynSubInverse(pPOLYN pa) //逆置多项式的差
{
} // PloynSubInverse
