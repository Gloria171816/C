#include <stdio.h>
int main()
{
	int a[15];
	int i,temp=0,j,len,max_1,max_2;
	for(i=0;i<5;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=1;i<5;i++)
	{
		if(a[i]>a[0])
		max_1=i;
	}
	temp=a[max_1];
	a[max_1]=a[0];
	a[0]=temp;
	for(i=0;i<5;i++)
	{
		printf("%d\t",a[i]);
	}
	temp=0;
	for(j=1;j<5;j++)
	{
		if(a[j]>a[4])
		max_2=j;
	}
	temp=a[max_2];
	a[max_2]=a[4];
	a[4]=temp;
	for(j=0;j<5;j++)
	printf("%d\t",a[j]);
 } 
