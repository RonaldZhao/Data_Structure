#define MAX_TREE_SIZE 100

typedef char ElemType;

typedef struct CTNode
{
	int child;
	struct CTNode *next;
}*ChildPtr;

typedef struct 
{
	ElemType data;
	int parent;
	ChildPtr firstchild;
}CTBox;

typedef struct
{
	CTBox boxes[MAX_TREE_SIZE];
	int r, n;
}PCTree;