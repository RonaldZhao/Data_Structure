typedef struct
{
    ElemType *base; // 指向栈底
    ElemType *top;  // 指向栈顶
    int stackSize;  // 栈的当前可用最大容量
}SqStack;