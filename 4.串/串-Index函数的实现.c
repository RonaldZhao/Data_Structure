/* T为非空串。若主串S中第pos个字符之后存在与T相等的子串，则返回第一个这样的子串在S中的位置，否则返回0 */
int Index(String S, String T, int pos)
{
	int n, m, i;
	String sub;
	if(pos > 0)
	{
		n = StrLength(S);	// 得到主串S的长度
		m = StrLength(T);	// 得到子串T的长度
		i = pos;
		while(i <= n-m+1)
		{
			SubString(sub, S, i, m);	// 取主串第i个位置长度与T相等的子串给sub
			if(StrCompare(sub, T) != 0)	// 如果两串不相等
				++i;
			else
				return i;
		}
	}
	return 0;	// 若无子串与T相等，返回0
}

int StrLength(String S)
{
	int len = 0;
	while(S[len] != '\0')
		++len;
	return len;
}