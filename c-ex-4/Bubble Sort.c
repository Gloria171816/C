#include <stdio.h>
void main() 
{
    int a[11],i,j,m,k,temp;
    for(i=0;i<10;i++)
	    scanf("%d",&a[i]);
	for(i=0;i<9;i++)
   {
        k=i;    /*���ǺŸ�ֵ*/
        for(j=i+1;j<=9;j++)   
        if(a[k]<a[j])
            k=j; /*��k����ָ�����Ԫ��*/   
        if(i!=k)  /*��k!=i�ǲŽ���������a[i]��Ϊ���*/   
        {  
            temp=a[i];   
            a[i]=a[k];   
            a[k]=temp;   
        }
   }
    for(i=0;i<10;i++)
    printf("%7d",a[i]);
}
