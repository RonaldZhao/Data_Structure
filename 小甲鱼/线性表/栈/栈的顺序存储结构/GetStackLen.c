/*
计算栈的当前元素个数
*/
int GetStackLen(SqStack s)
{
    return (s.top - s.base);    // 相同类型的指针相减返回的是此类型的个数，不是地址差 
}