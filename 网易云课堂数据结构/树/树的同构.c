/*
���⣺
	����������T1��T2�����T1����ͨ�����ɴ����Һ��ӻ����ͱ��T2�������������ǡ�ͬ�����ġ�
	�����ʽ��
		����������ö���������Ϣ��
			������һ�и��������Ľ���������N��
			����i�ж�Ӧ��ŵ�i����㣬�����ý���д洢����ĸ�������ӽ��ı�š��Һ��ӽ��ı��
			��������ӽ��Ϊ�գ�������Ӧλ���ϸ���"-"
����������
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

���˼·��
	1.��������ʾ
	2.��������
	3.ͬ���б�

��������ʾ��
	�ṹ�����ʾ����������̬������
*/
#define MaxTree 10
#define ElementType char
#define Tree int
#define Null -1	// ����NULL(��Ϊ��ϵͳĬ����0)

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
	// ��������1
	R1 = BuildTree(T1);
	// ��������2
	R2 = BuildTree(T2);
	// �б��Ƿ�ͬ�������
	if(Isomorphic(R1,R2))
		printf("Yes\n");
	else
		printf("No\n");
	return 0;
}