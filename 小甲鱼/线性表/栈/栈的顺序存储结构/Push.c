#define STACKINCREMENT 10
void Push(SqStack *s, ElemType e)
{
    if(s->top - s->base >= s->stackSize)
    {
        s->base = (ElemType *)realloc(s->base, (s->stackSize + STACKINCREMENT) * sizeof(ElemType));
        if(!(s->base))
        {
            exit(0);
        }
        s->top = s->base + s->stackSize;
        s->stackSize += STACKINCREMENT;
    }
    *(s->top) = e;
    s->top++;
}
