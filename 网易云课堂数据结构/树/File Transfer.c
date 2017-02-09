/*
    ��������1��
    5
    C 3 2
    I 3 2
    C 1 5
    I 4 5
    I 2 4
    C 3 5
    S

*/
#include <stdio.h>

#define MAXN 1000                  /* �������Ԫ�ظ��� */
typedef int ElemType;           /* Ĭ��Ԫ�ؿ����÷Ǹ�������ʾ */
typedef int SetName;               /* Ĭ���ø������±���Ϊ�������� */
typedef ElemType SetType[MAXN]; /* ���輯��Ԫ���±��0��ʼ */

void Union( SetType S, SetName Root1, SetName Root2 )
{
    if(Root1 != Root2)  /* ȷ��Root1��Root2�ǲ�ͬ���ϵĸ���� */
    {
        /* ��֤С���ϲ���󼯺� */
        if ( S[Root2] < S[Root1] ) { /* �������2�Ƚϴ� */
            S[Root2] += S[Root1];     /* ����1���뼯��2  */
            S[Root1] = Root2;
        }
        else {                         /* �������1�Ƚϴ� */
            S[Root1] += S[Root2];     /* ����2���뼯��1  */
            S[Root2] = Root1;
        }
    }
}

SetName Find( SetType S, ElemType X )
{ /* Ĭ�ϼ���Ԫ��ȫ����ʼ��Ϊ-1 */
    if ( S[X] < 0 ) /* �ҵ����ϵĸ� */
        return X;
    else
        return S[X] = Find( S, S[X] ); /* ·��ѹ�� */
}

void Input_connection(SetType S)
{
    ElemType u, v;
    SetName Root1, Root2;
    scanf("%d %d\n", &u, &v);
    Root1 = Find(S, u-1);
    Root2 = Find(S, v-1);
    if(Root1 != Root2)
        Union(S, Root1, Root2);
}

void Check_connection(SetType S)
{
    ElemType u, v;
    SetName Root1, Root2;
    scanf("%d %d\n", &u, &v);
    Root1 = Find(S, u-1);
    Root2 = Find(S, v-1);
    if(Root1 == Root2)
        printf("yes\n");
    else
        printf("no\n");
}

void Check_network(SetType S, int n)
{
    int i, counter = 0;
    for(i=0;i<n;i++)
    {
        if(S[i]<0)
            counter++;
    }
    if(counter==1)
        printf("The network is connected.\n");
    else
        printf("There are %d components.\n", counter);
}

void Init(SetType *S, int n)
{
    int i;
    for(i=0;i<n;i++)
        (*S)[i] = -1;
}

int main()
{
    SetType S;
    int n;
    char in;
    scanf("%d\n", &n);
    Init(&S, n);
    do
    {
        scanf("%c", &in);
        switch(in)
        {
        case 'I':Input_connection(S);
            break;
        case 'C':Check_connection(S);
            break;
        case 'S':Check_network(S, n);
            break;
        }
    }while(in != 'S');

    return 0;
}
