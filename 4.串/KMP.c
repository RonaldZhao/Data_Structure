/* 通过计算返回子串T的next数组 */
void get_next(String T, int *next)
{
	int i, j;
	i = 1;
	j = 0;
	next[1] = 0;
	while(i < T[0])	// 此处T[0]表示串T的长度
	{
		if(j == 0 || T[i] == T[j])	// T[i]表示后缀的单个字符，T[j]表示前缀的单个字符
		{
			++i;
			++j;
			next[i] = j;
		}
		else
		{
			j = next[j];	// 若j值不相同，则j值回溯
		}
	}
}// 这段代码的目的是为了计算出当前要匹配的串T的next数组
int Index_KMP(String S, String T, int pos)
{
	int i = pos;	// i用于主串S当前位置下标值，若pos不为1，则从pos位置开始匹配。
	int j = 1;	// j用于子串T中当前位置下标值
	int next[255];	// 定义一个next数组
	get_next(T, next);	// 对串T作分析，得到next数组
	while(i <= S[0] && j <= T[0])	// 若i小于S的长度且j小于T的长度时，循环继续
	{
		if(j == 0 || S[i] == T[j])	// 两字母相等则继续，与朴素算法相比增加了j==0判断
		{
			++i;
			++j;
		}
		else
		{
			j = next[j];	// j退回合适的位置，i值不变
		}
	}
	if(j > T[0])
	{
		return i-T[0];
	}
	else
	{
		return 0;
	}
}

















