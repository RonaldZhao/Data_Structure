typedef struct StackNode
{
    ElemType data;          // 数据域，存放栈的数据
    struct StackNode *next;
}StackNode, *LinkStackPtr;
typedef struct LinkStack
{
    LinkStackPtr top;   // 栈顶指针
    int count;          // 栈元素计数器
}LinkStack;