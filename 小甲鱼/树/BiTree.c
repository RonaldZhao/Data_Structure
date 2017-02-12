/*
    ����������(һ�� ^ ����һ���ո�)
    AB^D^^CE^^^
    
    ���������
    A λ�ڵ� 1 ��.
    B λ�ڵ� 2 ��.
    D λ�ڵ� 3 ��.
    C λ�ڵ� 2 ��.
    E λ�ڵ� 3 ��.
*/
#include <stdio.h>
#include <stdlib.h>

// ��������
typedef char ElemType;

// �������Ľ��
typedef struct BiTNode
{
    ElemType data;
    struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

// ����һ�ö�������Լ���û���ǰ������ķ�ʽ��������
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

// ���ʶ��������ľ������
void visit(ElemType c, int level)
{
    printf("%c λ�ڵ� %d ��.\n", c, level);
}

// ǰ�����������
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