#include<stdio.h>
#include<string.h>
void main(){
    void printfmax(char *p); //����printfmax���������������ִ�//   
    char c[100];
	printf("������һ���ַ���\n");
	gets(c);
	printf("����ַ���������ַ���:\n");
	printfmax(c);
	printf("\n");
}
void printfmax(char *p)
{
    char *s;
	int k,max;           //k������¼ÿ���ַ��ĳ���,max��¼�����ĸ����//
	for(k=max=0,s=p;*p;p++){
    while(isalpha(*p))       //�ж�ָ��pָ����Ƿ�����ĸ//
	{
    k++;p++;
	}
	if(k>max){
	max=k;s=p-k;
	}       //��ָ��s��ָ����ַ�������ĸ��ַ//
	k=0;                     //�ж���һ�����ʺ�,kȡ0�����¼�¼//
	}
    for(k=0;k<max;k++) //��Ȼ��ַ�������ĸ��ַ�ҵ���,�������ҵ���,��Ȼ���������//
    putchar(*s++);       //ע�ⲻҪд��putchar((*s)++)//
	printf("\n�ַ����ȣ�%d \n", max);
}
