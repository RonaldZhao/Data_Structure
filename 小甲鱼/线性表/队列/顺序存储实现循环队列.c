// 用顺序存储结构实现一个循环队列
// 定义
#define MAXSIZE 100
typedef struct
{
	ElemType *base;
	int front;
	int rear;
}cycleQueue;

// 初始化
initQueue(cycleQueue *q)
{
	q->base = (ElemType *)malloc(sizeof(ElemType)*MAXSIZE);
	if(!q->base)
		exit(0);
	q->front = q->rear = 0;
}

// 入队
InQueue(cycleQueue *q, ElemType e)
{
	if((q->rear+1)%MAXSIZE == q->front)
		return;	// 队满
	q->base[q->rear] = e;
	q->rear = (q->rear+1)%MAXSIZE;
}

// 出队
DeQueue(cycleQueue *q, ElemType *e)
{
	if(q->front == q->rear)
		return;	// 队空
	*e = q->base[q->front];
	q->front = (q->front+1)%MAXSIZE;
}