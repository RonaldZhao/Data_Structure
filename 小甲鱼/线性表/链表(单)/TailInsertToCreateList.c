/*尾插法建立单链表*/

void TailInsertToCreateList(LinkList *L, int n)
{
    LinkList p,q;

    srand((unsigned)time(0));
    (*L)=(LinkList)malloc(sizeof(Node));    //头结点
    p=*L;

    for(int i=0; i<n; i++)
    {
        q=(LinkList)malloc(sizeof(Node));
        q->data=rand()%100+1;       //填充随机数据

        p->next=q;  //尾插法添加结点
        p=q;
    }
    p->next=NULL;   //将尾结点的next域设为NULL
}
