/*
题意：
	给定两棵树T1和T2，如果T1可以通过若干次左右孩子互换就变成T2，则这两棵树是“同构”的。
	输入格式：
		输入给出两棵二叉树的信息：
			·先在一行给出该树的结点数，随后N行
			·第i行对应编号第i个结点，给出该结点中存储的字母、其左孩子结点的编号、右孩子结点的编号
			·如果孩子结点为空，则在相应位置上给出"-"
输入样例：
8
A 1 2
B 3 4
C 5 -
D - -
E 6 -
G 7 -
F - -
H - -
8
G - 4
B 7 6
F - -
A 5 1
H - -
C 0 -
D - -
E 2 -

求解思路：
	1.二叉树表示
	2.建二叉树
	3.同构判别

二叉树表示：
	结构数组表示二叉树（静态链表）：
*/
#define MaxTree 10
#define ElementType char
#define Tree int
#define Null -1	// 不是NULL(因为它系统默认是0)

struct TreeNode
{
	ElementType Element;
	Tree Left;
	Tree Right;
}T1[MaxTree], T2[MaxTree];

Tree BuildTree(struct TreeNode T[])
{
	scanf("%d\n", &N);
	if(N)
	{
		for(i=0;i<N;i++)
			check[i]=0;
		for(i=0;i<N;i++)
		{
			scanf("%c %c %c",&T[i].Element,&cl,&cr);
			if(cl!='-')
			{
				T[i].Left = cl-'0';
				check[T[i].Left] = 1;
			}
			else
				T[i].Left = Null;
		}
		for(i=0;i<N;i++)
			if(!check[i])
				break;
		Root = i;
	}
	return Root;
}

int Isomorphic(Tree R1,Tree R2)
{
	if((R1==Null) && (R2==Null))	// both empty
		return 1;
	if(((R1==Null)&&(R2!=Null))||((R1!=Null)&&(R2==Null)))	// one of them is empty
		return 0;
	if(T1[R1].Element != T2[R2].Element)	// roots are different
		return 0;
	if((T1[R1].Left==Null)&&(T2[R2].Left==Null))	// both have no left subtree
		return Isomorphic(T1[R1].Right,T2[R2].Right);
	if(((T1[R1].Left!=Null)&&(T2[R2].Left!=Null))&&((T1[T1[R1].Left].Element)==(T2[T2[R2].Left].Element)))
		// no need to swap the left and the right
		return (Isomorphic(T1[R1].Left,T2[R2].Left)&&Isomorphic(T1[R1].Right,T2[R2].Right));
	else	// need to swap the left and the right
		return (Isomorphic(T1[R1].Left,T2[R2].Right)&&Isomorphic(T1[R1].Right,T2[R2].Left));
}

int main()
{
	Tree R1,R2;
	// 建二叉树1
	R1 = BuildTree(T1);
	// 建二叉树2
	R2 = BuildTree(T2);
	// 判别是否同构并输出
	if(Isomorphic(R1,R2))
		printf("Yes\n");
	else
		printf("No\n");
	return 0;
}