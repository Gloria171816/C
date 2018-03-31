#include <stdio.h>
int main()
{
	int n;
	printf("input:");
	scanf("%d", &n);
	printf("output:%d\n", &n);//十进制
	printf("output:%o\n", &n);//八进制
	printf("output:%X\n", &n);//十六进制
	return 0;
}
