/*
  输入样例：
    请输入表达式的项数：4
    请输入表达式各项的系数与指数，以空格分隔：
    3 4 -5 2 6 1 -2 0
    请输入表达式的项数：3
    请输入表达式各项的系数与指数，以空格分隔：
    5 20 -7 4 3 1
  输出样例：
  计算结果表达式中的各项系数与指数如下：
  (15,24) (-25,22) (30,21) (-10,20) (-21,8) (35,6) (-33,5) (14,4) (-15,3) (18,2)
  (-6,1)
  计算结果表达式中的各项系数与指数如下：
  (5,20) (-4,4) (-5,2) (9,1) (-2,0)
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct PolyNode *Polynomial;
struct PolyNode {
  int coef;  //系数
  int expon; //指数
  Polynomial link;
};

void Attach(int c, int e, Polynomial *pRear) {
  Polynomial p;
  p = (Polynomial)malloc(sizeof(struct PolyNode));
  p->coef = c;
  p->expon = e;
  p->link = NULL;
  (*pRear)->link = p;
  *pRear = p;
}

Polynomial ReadPoly() {
  Polynomial p, Rear, t;
  int c, e, n;
  printf("请输入表达式的项数：");
  scanf("%d", &n);
  printf("请输入表达式各项的系数与指数，以空格分隔：\n");
  p = (Polynomial)malloc(sizeof(struct PolyNode));
  p->link = NULL;
  Rear = p;
  while (n--) {
    scanf("%d %d", &c, &e);
    Attach(c, e, &Rear);
  }
  t = p;
  p = p->link;
  free(t);
  return p;
}

Polynomial Add(Polynomial p1, Polynomial p2) {
  Polynomial t1, t2, Rear, temp, p;
  int sum;
  t1 = p1;
  t2 = p2;
  p = (Polynomial)malloc(sizeof(struct PolyNode));
  p->link = NULL;
  Rear = p;
  while (t1 && t2) {
    if (t1->expon == t2->expon) {
      sum = t1->coef + t2->coef;
      if (sum)
        Attach(sum, t1->expon, &Rear);
      t1 = t1->link;
      t2 = t2->link;
    } else if (t1->expon > t2->expon) {
      Attach(t1->coef, t1->expon, &Rear);
      t1 = t1->link;
    } else {
      Attach(t2->coef, t2->expon, &Rear);
      t2 = t2->link;
    }
  }
  while (t1) {
    Attach(t1->coef, t1->expon, &Rear);
    t1 = t1->link;
  }
  while (t2) {
    Attach(t2->coef, t2->expon, &Rear);
    t2 = t2->link;
  }

  Rear->link = NULL;
  temp = p;
  p = temp->link;
  free(temp);

  return p;
}

Polynomial Mult(Polynomial p1, Polynomial p2) {
  Polynomial p, Rear, t1, t2, t;
  int c, e;

  if (!p1 || !p2)
    return NULL;

  t1 = p1;
  t2 = p2;
  p = (Polynomial)malloc(sizeof(struct PolyNode));
  p->link = NULL;
  Rear = p;
  while (t2) {
    Attach(t1->coef * t2->coef, t1->expon + t2->expon, &Rear);
    t2 = t2->link;
  }
  t1 = t1->link;
  while (t1) {
    t2 = p2;
    Rear = p;
    while (t2) {
      e = t1->expon + t2->expon;
      c = t1->coef * t2->coef;
      while (Rear->link && Rear->link->expon > e)
        Rear = Rear->link;
      if (Rear->link && Rear->link->expon == e) {
        if (Rear->link->coef + c)
          Rear->link->coef += c;
        else {
          t = Rear->link;
          Rear->link = t->link;
          free(t);
        }
      } else {
        t = (Polynomial)malloc(sizeof(struct PolyNode));
        t->coef = c;
        t->expon = e;
        t->link = Rear->link;
        Rear->link = t;
        Rear = Rear->link;
      }
      t2 = t2->link;
    }
    t1 = t1->link;
  }
  t2 = p;
  p = p->link;
  free(t2);

  return p;
}

void printPoly(Polynomial p) {
  int flag = 0;

  if (!p) {
    printf("0 0\n");
    return;
  }

  printf("计算结果表达式中的各项系数与指数如下：\n");
  while (p) {
    if (!flag)
      flag = 1;
    else {
      printf(" ");
    }
    printf("(%d,%d)", p->coef, p->expon);
    p = p->link;
  }
  printf("\n");
}

int main(int argc, char const *argv[]) {
  Polynomial p1, p2, pp, ps;

  p1 = ReadPoly();
  p2 = ReadPoly();
  pp = Mult(p1, p2);
  printPoly(pp);
  ps = Add(p1, p2);
  printPoly(ps);

  return 0;
}
