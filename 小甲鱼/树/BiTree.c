/*
    输入样例：(一个 ^ 代表一个空格)
    AB^D^^CE^^^
    
    输出样例：
    A 位于第 1 层.
    B 位于第 2 层.
    D 位于第 3 层.
    C 位于第 2 层.
    E 位于第 3 层.
*/
#include <stdio.h>
#include <stdlib.h>

// 数据类型
typedef char ElemType;

// 二叉树的结点
typedef struct BiTNode
{
    ElemType data;
    struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

// 创建一棵二叉树，约定用户用前序遍历的方式输入数据
void CreateBiTree(BiTree *T)
{
    ElemType c;

    scanf("%c", &c);

    if(' ' == c)
    {
        *T = NULL;
    }
    else
    {
        *T = (BiTNode *)malloc(sizeof(BiTNode));
        (*T)->data = c;
        CreateBiTree(&((*T)->lchild));
        CreateBiTree(&((*T)->rchild));
    }
}

// 访问二叉树结点的具体操作
void visit(ElemType c, int level)
{
    printf("%c 位于第 %d 层.\n", c, level);
}

// 前序遍历二叉树
void PreOrderTraverse(BiTree T, int level)
{
    if( T )
    {
        visit(T->data, level);
        PreOrderTraverse(T->lchild, level+1);
        PreOrderTraverse(T->rchild, level+1);
    }
}

int main()
{
    int level = 1;
    BiTree T = NULL;

    CreateBiTree(&T);
    PreOrderTraverse(T, level);

    return 0;
}