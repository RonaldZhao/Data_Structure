#define MAXSIZE 20
typedef int ElemType;
typedef struct
{
    ElemType data[MAXSIZE];
    int length; //用来表示线性表的当前长度
}SqList;
/*
这里我们封装了一个结构，事实上就是对一个数组进行了封装，增加了一个表示当前长度的变量罢了。
*/

/*
顺序存储结构封装需要三个属性：
    1. 存储空间的起始位置：数组data。它的存储位置就是线性表存储空间的存储位置。
    2. 线性表的最大存储容量：数组的长度 MAXSIZE。
    3. 线性表的当前长度：length。
注意：区分 MAXSIZE 与 length。
*/