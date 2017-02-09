/*
用递归实现把输入的任意长字符串倒序输出，输入以'#'结束
*/
#include <stdio.h>

void print()
{
	char c;
	scanf("%c",&c);
	if(c!='#')
		print();
	if(c!='#')
		printf("%c",c);
}

int main()
{
	print();
	return 0;
}