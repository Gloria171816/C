#include <stdio.h>
#include <math.h> 
int main() 
{
    int n,m,i,j;
	printf("������һ��������n:\n");
	scanf("%d",&n); 
	printf("С��%d������Ϊ��",n);
	for(i=2;i<=n;i++)
	{
	m=sqrt(i); 
    for(j=2;j<=m;j++) 
    if(i%j==0) 
	break; 
    if(j>=m+1) 
	printf("%5d", i);
	} 
    printf("\n"); 
    return 0;
}
