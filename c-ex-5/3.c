#include <stdio.h>
void main(){
    int n, M;  
	int a[M],i,k,t;
	printf("请输入m的值：\n");
	scanf("%d", &M);      
	printf("输入n的值：\n");        
	scanf("%d", &n);        
	for(i=0;i<M;i++) // 初始化数组a，每个数组元素中存放编号（1～M）          
	a[i]=i+1; // 数组元素a[i]非+0时，代表该人在圈中；a[i]为0时，代表该人出圈       
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
