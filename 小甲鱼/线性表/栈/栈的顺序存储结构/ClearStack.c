/*
    清空一个栈（不是销毁）
*/
void ClearStack(SqStack *s)
{
    s->top = s->base;
}