#include <stdio.h>
void main(){
    int n, M;  
	int a[M],i,k,t;
	printf("������m��ֵ��\n");
	scanf("%d", &M);      
	printf("����n��ֵ��\n");        
	scanf("%d", &n);        
	for(i=0;i<M;i++) // ��ʼ������a��ÿ������Ԫ���д�ű�ţ�1��M��          
	a[i]=i+1; // ����Ԫ��a[i]��+0ʱ�����������Ȧ�У�a[i]Ϊ0ʱ��������˳�Ȧ       
	i=0;        
	t=0;       
	k=0;        
	while(t<M){   
	if(a[i]!=0){   
	    k++;
		if(k%n==0){
		    printf("%d\t",a[i]);
			t++;                    
	        a[i]=0;}            
	    }            
	i++;  
	if(i==M) 
	i=0;         
	} 
}
