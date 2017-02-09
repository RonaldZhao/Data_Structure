#include <stdio.h>

void move(int n, char x, char y, char z, int *s)
{
	if(n == 1)
		printf("%c-->%c\n", x, z);
	else
	{
		move(n-1, x, z, y, s);
		(*s)++;
		printf("%c-->%c\n", x, z);
		move(n-1, y, x, z, s);
		(*s)++;
	}
}

int main()
{
	int n, s;
	scanf("%d", &n);
	s = 1;
	move(n, 'X', 'Y', 'Z', &s);
	printf("一共需要移动 %d 步.\n", s);

	return 0;
}
