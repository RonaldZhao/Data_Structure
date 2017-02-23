/*
	参数定义：
	1.事件的最早发生时间etv(earliest time of vertex)：即顶点vk的最早发生时间；
	2.事件的最晚发生时间ltv(latest time of vertex)：即顶点vk的最晚发生时间，也就是每个顶点对应的时间最晚需要开始时间，
	  超过此时间将会延误整个工期；
	3.活动的最早开工时间ete(earliest time of edge)：即弧ak的最早发生时间；
	4.活动最晚开工时间lte(latest time of edge)：即弧ak的最晚时间，也就是不推迟工期的最晚开始时间。
	我们是由1和2可以求得3和4，然后再根据ete[k]和lte[k]是否相等来判断是否是关键活动。
*/
int *etv, *ltv;	// 事件最早和最晚发生时间的数组
int *stack2;	// 用于存储拓扑序列的栈，后面求关键路径时使用
int top2;	// 用于stack2的栈顶指针
Status TopologicalSort(GraphAdjList GL)	// 拓扑排序，用于关键路径的计算
{
	EdgeNode *e;
	int i, k, gettop;
	int top = 0;	// 用于栈指针下标
	int count = 0;	// 用于统计输出顶点的个数
	int *stack;	// 建栈将入度为0顶点入栈
	stack = (int *)malloc(sizeof(int)*GL->numVertexes);
	for(i = 0; i < GL->numVertexes; i++)
		if(0 == GL->adjList[i].in)
			stack[++top] = i;
	top2 = 0;	// 初始化为0
	etv = (int *)malloc(sizeof(int)*GL->numVertexes);
	for(i = 0; i < GL->numVertexes; i++)
		etv[i] = 0;	// 初始化为0
	stack2 = (int *)malloc(sizeof(int)*GL->numVertexes);
	while(top != 0)
	{
		gettop = stack[top--];
		count++;
		stack2[++top2] = gettop;	// 将弹出的顶点序号压入拓扑排序的栈
		for(e = GL->adjList[gettop].firstedge; e; e = e->next)
		{
			k = e->adjvex;
			if(!(--GL->adjList[k].in))
				stack[++top] = k;
			if((etv[gettop]+e->weight)>etv[k])	// 求各顶点事件最早发生时间的值
				etv[k] = etv[gettop] + e->weight;
		}
	}
	if(count < GL->numVertexes)
		return ERROR;
	else
		return OK;
}
// 求关键路径的算法
void CriticaiPath(GraphAdjList GL)
{
	EdgeNode *e;
	int i, j, k, gettop;
	int ete, lte;
	TopologicalSort(GL);
	ltv = (int *)malloc(sizeof(int)*Gl->numVertexes);
	for( i = 0; i < GL->numVertexes; i++)
		ltv[i] = etv[GL->numVertexes-1];	// 初始化ltv
	while(top2 != 0)
	{
		gettop = stack2[top2--];	// 将拓扑序列出栈
		for(e = GL->adjList[gettop].firstedge; e; e = e->next)
		{// 求各顶点时间最晚发生时间ltv的值
			k = e->adjvex;
			if(ltv[k]-e->weight < ltv[gettop])	// 求各顶点事件最晚发生时间
				ltv[gettop] = ltv[k] - e->weight;
		}
	}
	for(j = 0; j < GL->numVertexes; j++)
	{
		for(e = GL->adjList[j].firstedge; e = e->next)
		{
			k = e->adjvex;
			ete = etv[j];	// 活动最早发生时间
			lte = ltv[k] - e->weight;	// 活动最晚发生时间
			if(ete == lte)	// 两者相等即在关键路径上
				printf("<v%d, v%d> length: %d", GL->adjList[j].data, GL->adjList[k].data, e->weight);
		}
	}
}