#ifndef _STACK_H_
#define _STACK_H_
#define MAXSIZE 12500
typedef int Status;                 //返回值状态码
typedef int SElemType;              //栈的基本元素类型
typedef struct                      //栈的结构
{
    //SElemType *data;//有空了把data域改为动态生成的
    SElemType data[MAXSIZE];
    int top;
}SqStack;

Status InitStack(SqStack *);        //初始化操作，建立一个空栈S
Status DestroyStack(SqStack *);     //若栈S存在，则销毁它
Status ClearStack(SqStack *);       //将栈S清空
Status StackEmpty(SqStack);         //若栈为空，返回TRUE，否则返回FALSE
Status GetTop(SqStack,SElemType *); //若栈存在且非空，用e返回栈S的栈顶元素
Status Push(SqStack *, SElemType);  //若栈S存在，插入新元素e到栈中并成为栈顶元素
Status Pop(SqStack *,SElemType *);  //删除栈S中栈顶元素，并用e返回其值
int StackLength(SqStack);           //返回栈S的元素个数
#endif
