#include <stdio.h>
void main() 
{
    int a[11],i,j,m,k,temp;
    for(i=0;i<10;i++)
	    scanf("%d",&a[i]);
	for(i=0;i<9;i++)
   {
        k=i;    /*给记号赋值*/
        for(j=i+1;j<=9;j++)   
        if(a[k]<a[j])
            k=j; /*是k总是指向最大元素*/   
        if(i!=k)  /*当k!=i是才交换，否则a[i]即为最大*/   
        {  
            temp=a[i];   
            a[i]=a[k];   
            a[k]=temp;   
        }
   }
    for(i=0;i<10;i++)
    printf("%7d",a[i]);
}
