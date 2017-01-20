Status Push(LinkStack *s, ElemType e)
{
    LinkStackPtr p = (LinkStackPtr)malloc(sizeof(StackNode));
    p->data = e;
    p->next = s->top;
    s->top = p;
    s->count++;
    return OK;
}