typedef struct Node
{
    ElemType data;     //数据域
    struct Node *next; //指针域
} Node;
typedef struct Node* LinkList;