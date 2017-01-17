/*头插法建立单链表实例*/

void HeadInsertToCreateList(LinkList *L, int n)
{
    LinkList p;

    *L=(LinkList)malloc(sizeof(Node));  //头结点
    (*L)->next=NULL;

    srand((unsigned)time(0));   //初始化随机数种子

    for(int i=0; i<n; i++)
    {
        p=(LinkList)malloc(sizeof(Node));
        p->data=rand()%100+1;   //填充随机数据
        
        p->next=(*L)->next;     //头插法添加结点
        (*L)->next=p;
    }
}
