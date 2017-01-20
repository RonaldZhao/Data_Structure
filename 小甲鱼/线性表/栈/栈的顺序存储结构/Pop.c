void Pop(SqStack *s, ElemType *e)
{
    if(s->top == s->base)   // 栈为空
    {
        return;
    }
    *e = *(--(s->top));
}