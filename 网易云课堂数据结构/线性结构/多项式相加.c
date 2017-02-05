struct PolyNode
{
	int coef;	// ϵ��
	int expon;	// ָ��
	struct PolyNode *next;	// ָ����һ������ָ��
};
typedef struct PolyNode *Polynomial;
Polynomial p1,p2;

int Compare(int x, int y)
{
	return x==y?0:(x>y?1:-1);
}

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

Polynomial PolyAdd(Polynomial p1, Polynomial p2)
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
	/* ��δ���������һ������ʽ�����нڵ�һ�θ��Ƶ��������ʽ��ȥ */
	for(;p1;p1=p1->next)
		Attach(p1->coef,p1->expon,&rear);
	for(;p2;p2=p2->next)
		Attach(p2->coef,p2->expon,&rear);
	rear->next = NULL;
	temp = front;
	front = fron->next;	// ��frontָ��������ʽ��һ��������
	free(temp);			// �ͷ���ʱ�ձ�ͷ���
	return front;
}