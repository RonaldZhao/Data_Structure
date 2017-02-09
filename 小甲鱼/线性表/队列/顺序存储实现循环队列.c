// ��˳��洢�ṹʵ��һ��ѭ������
// ����
#define MAXSIZE 100
typedef struct
{
	ElemType *base;
	int front;
	int rear;
}cycleQueue;

// ��ʼ��
initQueue(cycleQueue *q)
{
	q->base = (ElemType *)malloc(sizeof(ElemType)*MAXSIZE);
	if(!q->base)
		exit(0);
	q->front = q->rear = 0;
}

// ���
InQueue(cycleQueue *q, ElemType e)
{
	if((q->rear+1)%MAXSIZE == q->front)
		return;	// ����
	q->base[q->rear] = e;
	q->rear = (q->rear+1)%MAXSIZE;
}

// ����
DeQueue(cycleQueue *q, ElemType *e)
{
	if(q->front == q->rear)
		return;	// �ӿ�
	*e = q->base[q->front];
	q->front = (q->front+1)%MAXSIZE;
}