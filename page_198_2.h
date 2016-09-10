#define ERROR 0										//函数结果状态代码
#define OK 1
#define EQUAL 1
#define OVERFLOW -1
#define LIST_INIT_SIZE 100							//顺序表存储空间的初始分配量
#define LISTINCREMENT 10							//顺序表存储空间的分配增量

typedef int Status;									//Status为函数返回值类型，其值为函数结果状态代码

struct STU
{
	char name[20];
	char stuno[10];
	int age;
	int score;
};

typedef struct STU ElemType;						//顺序表中数据元素类型

struct LIST
{
	ElemType *elem;									//顺序表的存储空间基地址
	int length;										//当前长度
	int listsize;									//当前分配的增量
};

typedef struct LIST SqList;							//线性表的顺序存储结构的定义

Status InitList_SqList(SqList *);					//构造一张新的顺序表L
int ListLength_SqList(SqList);						//求顺序表的长度L
void GetElem_SqList(SqList,int,ElemType *);			//获取顺序表L的第i个元素
int EqualList(ElemType,ElemType);					//判断数据元素e1和e2是否相等
int Less_EqualList(ElemType,ElemType);				//判断属于元素e1是否小于等于e2
int LocateElem_SqList(SqList,ElemType,int);			//在顺序表L中寻找第一个与数据元素e符合type关系的元素
Status ListInsert_SqList(SqList *,int,ElemType);	//在顺序表L的第i个元素前插入新的元素e
Status Destroy_SqList(SqList *);					//销毁一张顺序表
void UnionList_SqList(SqList *,SqList);				//将所有在顺序表Lb中但不在顺序表La中的数据元素插入到La中
void MergeList_SqList(SqList,SqList,SqList *);		//一直顺序表La和Lb元素按值非递减排列，归并得到新的顺序表Lc也按非递减顺序排列
void printlist_SqList(SqList);						//输出顺序表
