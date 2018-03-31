#include <stdio.h>
void main()
{
	int m,s,i;
	for(m=2;m<1000;m++)
	{
		s=0;
		for(i=1;i<m;i++)
		if((m%i)==0)s=s+i;
		if(s==m)
		{
		printf("%d是完数，且因子为 ",m);
		for(i=1;i<m;i++)
		if(m%i==0)
		printf("%d ",i);
		printf("\n");
		}
	}
}
