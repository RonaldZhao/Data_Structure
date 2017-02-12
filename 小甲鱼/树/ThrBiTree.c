/*
    中序线索二叉树实现
    输入样例：
    ABC^^D^^E^F^^   (一个^代表一个空格)
    输出样例：
    ABC  D  E F
    InOrderTraverse:
    CBDAEF
*/
#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;

// 线索存储的标志位：Link(0)表示指向左右孩子的指针，Thread(1)表示指向前驱后继的线索
typedef enum {Link, Thread} PointerTag;

typedef struct ThrBiNode
{
    ElemType data;
    struct ThrBiNode *lchild, *rchild;
    PointerTag ltag, rtag;
}ThrBiNode, *ThrBiTree;

// 全局变量，始终指向刚刚访问过的结点
ThrBiTree pre;

// 创建一棵二叉树，约定用户遵照前序遍历的方式输入数据
void CreateThrBiTree(ThrBiTree *T)
{
    ElemType c;

    scanf("%c", &c);
    if( ' ' == c)
    {
        *T = NULL;
    }
    else
    {
        *T = (ThrBiNode *)malloc(sizeof(ThrBiNode));
        (*T)->data = c;
        (*T)->ltag = Link;
        (*T)->rtag = Link;
        CreateThrBiTree(&((*T)->lchild));
        CreateThrBiTree(&((*T)->rchild));
    }
}

// 中序遍历线索化
void InThreading(ThrBiTree T)
{
    if( T )
    {
        InThreading(T->lchild); // 递归左孩子线索化

        if(!T->lchild)  // 如果该结点没有左孩子，设置ltag为Thread，并把lchild指向刚刚访问的结点
        {
            T->ltag = Thread;
            T->lchild = pre;
        }

        if(!pre->rchild)
        {
            pre->rtag = Thread;
            pre->rchild = T;
        }

        pre = T;

        InThreading(T->rchild); // 递归右孩子线索化
    }
}

void InOrderThreading(ThrBiTree *head, ThrBiTree T)
{
    *head = (ThrBiTree)malloc(sizeof(ThrBiNode));
    (*head)->ltag = Link;
    (*head)->rtag = Thread;
    (*head)->rchild = *head;
    if( !T )    // 如果 T 是空树，则把 head 的rchild指向 head 自身，结束
    {
        (*head)->lchild = *head;
    }
    else
    {
        (*head)->lchild = T;
        pre = *head;

        InThreading(T);

        pre->rchild = *head;
        pre->rtag = Thread;
        (*head)->rchild = pre;
    }
}

void visit(ElemType c)
{
    printf("%c", c);
}

// 中序遍历二叉树，非递归
void InOrderTraverse(ThrBiTree T)
{
    ThrBiTree p;
    p = T->lchild;
    while(p != T)
    {
        while(p->ltag == Link)
        {
            p = p->lchild;
        }
        visit(p->data);

        while(p->rtag == Thread && p->rchild != T)
        {
            p = p->rchild;
            visit(p->data);
        }

        p = p->rchild;
    }
}

int main()
{
    ThrBiTree T = NULL, head;
    CreateThrBiTree(&T);
    InOrderThreading(&head, T);
    printf("InOrderTraverse:\n");
    InOrderTraverse(head);

    return 0;
}
