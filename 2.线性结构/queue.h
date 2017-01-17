#ifndef _QUEUE_H_
#define _QUEUE_H_
//循环队列的顺序存储结构
typedef int QElemType;                  //队列的基本元素类型
typedef int Status;                     //返回值状态码
typedef struct                          //队列的结构
{
    QElemType data[MAXSIZE];
    int front;
    int rear;
}SqQueue;

Status InitQueue(SqQueue *);            //初始化操作，建立一个空队列
Status DestroyQueue(SqQueue *);         //若队列Q存在，则销毁它
Status ClearQueue(SqQueue *);           //若队列Q存在，则清空它
Status QueueEmpty(SqQueue);             //若队列Q为空则返回TRUE，否则返回FALSE
Status GetHead(SqQueue, QElemType *);   //若队列Q存在且非空，用e返回队头元素的值
Status EnQueue(SqQueue *,QElemType);    //若队列Q存在且不满，插入新元素e到队列Q中并成为队尾元素
Status DeQueue(SqQueue *,QElemType *);  //删除队列Q中队头元素，并用e返回其值
int QueueLength(SqQueue);               //返回队列的元素个数

#endif