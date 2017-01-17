/* 树的孩子兄弟表示法 */
typedef int TElemType;								/* 树结点的数据类型，目前暂定为整型 */
typedef struct CSNode
{
	TElemType data;											/* 数据域 */
	struct CSNode *firstchild,*rightsib;/* 都是指针域，firstchild存储该结点的第一个孩子结点的存储地址，rightsib存储该结点的右兄弟结点的存储地址 */
}CSNode,*CSTree;