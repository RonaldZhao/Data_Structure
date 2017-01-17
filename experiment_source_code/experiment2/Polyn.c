#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
typedef struct node {
  int coef;          //系数项
  int expn;          //指数项
  struct node *next; //指向下一项
} linknode;
typedef linknode *linklist;
linklist create_list(linklist head) {
  linklist x, p;
  if (!(head = (linklist)malloc(sizeof(linknode)))) {
    printf("内存分配失败！\n");
    exit(0);
  }
  head->next = NULL;
  head->coef = 0;
  head->expn = 0;
  p = head;
  printf("\n请输入系数(支持为int类型)和指数(支持为int类型),中间以空格隔开:\n");
  while (1) {
    if (!(x = (linklist)malloc(sizeof(linknode)))) {
      printf("内存分配失败！\n");
      exit(0);
    }
    scanf("%d %d", &(x->coef), &(x->expn));
	x->next = NULL;
    if (x->coef == 0) {
      printf("■■■■■■■■■■■■■■ List Created! ■■■■■■■■■■■■■■\n\n");
      break;
    }
    p->next = x;
    p = x;
  }
  return head;
}
void print_list(linklist head) {
  linklist p;
  p = head->next;
  while (p) {
    printf("%dX^%d", p->coef, p->expn);
    if (p->next && p->next->coef > 0) {
      printf("+");
    }
    p = p->next;
  }
  printf("\n");
}
void free_list(linklist head) {
  linklist p;
  while (head) {
    p = head;
    head = head->next;
    free(p);
  }
}
linklist polynAdd(linklist head1, linklist head2) {
  linklist p1, p2, s, p3, head3;
  if (!(head3 = (linklist)malloc(sizeof(linknode)))) {
    printf("内存分配失败！\n");
    exit(0);
  }
  head3->next = NULL;
  p3 = head3;
  p1 = head1->next;
  p2 = head2->next;
  while (p1 && p2) {
    if (!(s = (linklist)malloc(sizeof(linknode)))) {
      printf("内存分配失败！\n");
      exit(0);
    }
	s->next = NULL;
    if (p1->expn < p2->expn) {
      s->expn = p1->expn;
      s->coef = p1->coef;
      p1 = p1->next;
    } else if (p1->expn == p2->expn) {
      s->expn = p1->expn;
      s->coef = p1->coef + p2->coef;
      p1 = p1->next;
      p2 = p2->next;
    } else {
      s->expn = p2->expn;
      s->coef = p2->coef;
      p2 = p2->next;
    }
	p3->next = s;
    p3 = s;
  }
  p3->next = NULL;
  if (p1) {
    p3->next = p1;
  }
  if (p2) {
    p3->next = p2;
  }
  return head3;
}
linklist polynSub(linklist head1, linklist head2) {
  linklist p;
  p = head2->next;
  while (p) {
    p->coef = (-1) * p->coef;
    p = p->next;
  }
  return polynAdd(head1, head2);
}
linklist polynSubInverse(linklist p)
{
	linklist head, n, t;
	head = p;
	n = p->next;
	head->next = NULL;
	while (n) {
		t = head->next;
		head->next = n;
		n = n->next;
		head->next->next = t;
	}
	return head;
}//polynSubInverse
int main(int argc, char const *argv[]) {
  linklist head1, head2, head3, head4;
  head1 = NULL;
  head2 = NULL;
  head3 = NULL;
  head4 = NULL;
  printf("\n\t链表输入时,当系数为0时结束输入\n");
  printf("\n\t程序输出时由指数低到高排列\n");
  head1 = create_list(head1);
  head2 = create_list(head2);
  print_list(head1);
  print_list(head2);
  head3 = polynAdd(head1, head2);
  print_list(head3); head3 = NULL;
  head3 = polynSub(head1, head2);
  print_list(head3);
  head4 = polynSubInverse(head3);
  print_list(head4);
  free_list(head1);
  free_list(head2);
  //free_list(head3);//bug,未解决
  //free_list(head4);//bug,未解决
  return 0;
}