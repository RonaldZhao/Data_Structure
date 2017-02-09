// DFS��α����������
void DFS(Vertex V)
{
	visited[V] = true;
	for( V ��ÿ���ڽӵ� W )
		if( !visited[W] )
			DFS(W);
}
// ���� N ����㣬E ���ߣ��� DFS ��ʱ�临�Ӷȣ�
//     �����ڽӱ�洢����ΪO(N+E)
//     �����ڽӾ���洢����ΪO(N^2)


/* �ڽӱ�洢��ͼ - DFS */
 
void Visit( Vertex V )
{
    printf("���ڷ��ʶ���%d\n", V);
}
 
/* Visited[]Ϊȫ�ֱ������Ѿ���ʼ��Ϊfalse */
void DFS( LGraph Graph, Vertex V, void (*Visit)(Vertex) )
{   /* ��VΪ��������ڽӱ�洢��ͼGraph����DFS���� */
    PtrToAdjVNode W;
     
    Visit( V ); /* ���ʵ�V������ */
    Visited[V] = true; /* ���V�ѷ��� */
 
    for( W=Graph->G[V].FirstEdge; W; W=W->Next ) /* ��V��ÿ���ڽӵ�W->AdjV */
        if ( !Visited[W->AdjV] )    /* ��W->AdjVδ������ */
            DFS( Graph, W->AdjV, Visit );    /* ��ݹ����֮ */
}