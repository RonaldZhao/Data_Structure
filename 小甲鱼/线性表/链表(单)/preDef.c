#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

//用结构指针定义结点
typedef struct Node {
  ElemType data;     //数据域
  struct Node *next; //指针域
} Node;
typedef struct Node *LinkList;
