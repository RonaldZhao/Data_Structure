#define ERROR 0										//�������״̬����
#define OK 1
#define EQUAL 1
#define OVERFLOW -1
#define LIST_INIT_SIZE 100							//˳���洢�ռ�ĳ�ʼ������
#define LISTINCREMENT 10							//˳���洢�ռ�ķ�������

typedef int Status;									//StatusΪ��������ֵ���ͣ���ֵΪ�������״̬����

struct STU
{
	char name[20];
	char stuno[10];
	int age;
	int score;
};

typedef struct STU ElemType;						//˳���������Ԫ������

struct LIST
{
	ElemType *elem;									//˳���Ĵ洢�ռ����ַ
	int length;										//��ǰ����
	int listsize;									//��ǰ���������
};

typedef struct LIST SqList;							//���Ա��˳��洢�ṹ�Ķ���

Status InitList_SqList(SqList *);					//����һ���µ�˳���L
int ListLength_SqList(SqList);						//��˳���ĳ���L
void GetElem_SqList(SqList,int,ElemType *);			//��ȡ˳���L�ĵ�i��Ԫ��
int EqualList(ElemType,ElemType);					//�ж�����Ԫ��e1��e2�Ƿ����
int Less_EqualList(ElemType,ElemType);				//�ж�����Ԫ��e1�Ƿ�С�ڵ���e2
int LocateElem_SqList(SqList,ElemType,int);			//��˳���L��Ѱ�ҵ�һ��������Ԫ��e����type��ϵ��Ԫ��
Status ListInsert_SqList(SqList *,int,ElemType);	//��˳���L�ĵ�i��Ԫ��ǰ�����µ�Ԫ��e
Status Destroy_SqList(SqList *);					//����һ��˳���
void UnionList_SqList(SqList *,SqList);				//��������˳���Lb�е�����˳���La�е�����Ԫ�ز��뵽La��
void MergeList_SqList(SqList,SqList,SqList *);		//һֱ˳���La��LbԪ�ذ�ֵ�ǵݼ����У��鲢�õ��µ�˳���LcҲ���ǵݼ�˳������
void printlist_SqList(SqList);						//���˳���
