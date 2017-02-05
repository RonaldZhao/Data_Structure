#include <stdio.h>
#include <stdlib.h>

/*
输入样例：
4 3 4 -5 2 6 1 -2 0	// 第一个4是项数，之后分别是每一项的系数、指数，下同
3 5 20 -7 4 3 1
输出样例：(不输出项数)
15 24 -25 22 30 21 -10 20 -21 8 35 6 -33 5 14 4 -15 3 18 2 -6 1
5 20 -4 4 -5 2 9 1 -2 0
*/
#define Compare(x,y) (x==y?0:(x>y?1:-1))

typedef struct PolyNode *Polynomial;
struct PolyNode
{
	int coef;
	int expon;
	struct PolyNode *next;
};

void Attach(int c, int e, Polynomial *r)
{
	Polynomial t;
	t = (Polynomial)malloc(sizeof(struct PolyNode));
	t->coef = c;
	t->expon = e;
	t->next = NULL;
	(*r)->next = t;
	(*r) = t;
}

Polynomial ReadPoly()
{
	int n,c,e;
	Polynomial p,rear,t;
	p = (Polynomial)malloc(sizeof(struct PolyNode));
	p->next = NULL;
	rear = p;
	scanf("%d", &n);
	while(n--)
	{
		scanf("%d%d",&c,&e);
		Attach(c,e,&rear);
	}
	t=p;	// 删除空头结点
	p=p->next;
	free(t);
	return p;
}

Polynomial Mult(Polynomial p1, Polynomial p2)
{
	Polynomial p,rear,t1,t2,t;
	int c,e;
	if(!p1||!p2)
		return NULL;
	t1=p1;
	t2=p2;
	p = (Polynomial)malloc(sizeof(struct PolyNode));
	p->next = NULL;
	rear = p;
	while(t2)
	{
		Attach(t1->coef*t2->coef,t1->expon+t2->expon,&rear);
		t2=t2->next;
	}
	t1 = t1->next;
	while(t1)
	{
		t2=p2;
		rear=p;
		while(t2)
		{
			e = t1->expon + t2->expon;
			c = t1->coef * t2->coef;
			while(rear->next&&rear->next->expon>e)
				rear=rear->next;
			if(rear->next&&rear->next->expon==e)
			{
				if(rear->next->coef+c)
					rear->next->coef += c;
				else
				{
					t = rear->next;
					rear->next=t->next;
					free(t);
				}
			}
			else
			{
				t = (Polynomial)malloc(sizeof(struct PolyNode));
				t->coef = c;
				t->expon = e;
				t->next = rear->next;
				rear->next = t;
				rear = rear->next;
			}
			t2=t2->next;
		}
		t1=t1->next;
	}
	t2=p;
	p=p->next;
	free(t2);
	return p;
}

Polynomial Add(Polynomial p1, Polynomial p2)
{
	Polynomial front,rear,temp;
	int sum;
	rear = (Polynomial)malloc(sizeof(struct PolyNode));
	front = rear;
	while(p1&&p2)
	{
		switch(Compare(p1->expon,p2->expon))
		{
			case 1:
				Attach(p1->coef,p1->expon,&rear);
				p1 = p1->next;
				break;
			case -1:
				Attach(p2->coef,p2->expon,&rear);
				p2 = p2->next;
				break;
			case 0:
				sum = p1->coef+p2->coef;
				if(sum)
					Attach(sum,p1->expon,&rear);
				p1 = p1->next;
				p2 = p2->next;
				break;
		}
	}
	/* 将未处理完的另一个多项式的所有节点一次复制到结果多项式中去 */
	for(;p1;p1=p1->next)
		Attach(p1->coef,p1->expon,&rear);
	for(;p2;p2=p2->next)
		Attach(p2->coef,p2->expon,&rear);
	rear->next = NULL;
	temp = front;
	front = front->next;	// 令front指向结果多项式第一个非零项
	free(temp);			// 释放临时空表头结点
	return front;
}

void PrintPoly(Polynomial p)
{
	int flag = 0;
	if(!p)
	{
		printf("0 0\n");
		return;
	}
	while(p)
	{
		if(!flag)
			flag=1;
		else
			printf(" ");
		printf("%d %d",p->coef, p->expon);
		p = p->next;
	}
	printf("\n");
}

int main()
{
	Polynomial p1,p2,pp,ps;
	// 读入多项式1
	p1 = ReadPoly();
	// 读入多项式2
	p2 = ReadPoly();
	// 做乘法运算并输出
	pp = Mult(p1,p2);
	PrintPoly(pp);
	// 做加法运算并输出
	ps = Add(p1,p2);
	PrintPoly(ps);

	return 0;
}
