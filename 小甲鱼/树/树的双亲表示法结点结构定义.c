#define MAX_TREE_SIZE 100

typedef int ElemType;

typedef struct PTNode
{
	ElemType data;	// ���λ��
	int parent;		// ˫��λ��
}PTNode;

typedef struct
{
	PTNode nodes[MAX_TREE_SIZE];
	int r;	// ����λ��
	int n;	// �����Ŀ
}PTree;