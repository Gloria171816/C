#include<stdio.h>
int main() {
	int x,y, arr[10],temp,n,end;
	printf("������ʮ������");
	for ( y = 0; y < 10; y++)
	{
		scanf("%d", &arr[y]);
	}
	for (x = 0; x < 10; x++)
	{
		n = x + 1;
		for (; n < 10; n++)
		{
			if (arr[x]>arr[n])
			{
				temp = arr[x];
				arr[x] = arr[n];
				arr[n] = temp;
			}
		}
	}
	printf("�����\n");
	for ( end = 0; end < 10; end++)
	{
		printf("%d  ", arr[end]);
	}
	return 0;
}
