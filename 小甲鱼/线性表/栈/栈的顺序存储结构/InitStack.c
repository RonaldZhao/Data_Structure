#define STACK_INIT_SIZE 100
void InitStack(SqStack *s)
{
    s->base = (ElemType *)malloc(sizeof(ElemType) * STACK_INIT_SIZE);
    if(!(s->base))
    {
        exit(0);
    }
    s->top = s->base;
    s->stackSize = STACK_INIT_SIZE;
}