#include<stdio.h>
#include<string.h>
void main(){
    void printfmax(char *p); //定义printfmax函数用来输出最长的字串//   
    char c[100];
	printf("请输入一个字符串\n");
	gets(c);
	printf("这个字符串中最长的字符是:\n");
	printfmax(c);
	printf("\n");
}
void printfmax(char *p)
{
    char *s;
	int k,max;           //k用来记录每个字符的长度,max记录最长的字母长度//
	for(k=max=0,s=p;*p;p++){
    while(isalpha(*p))       //判断指针p指向的是否是字母//
	{
    k++;p++;
	}
	if(k>max){
	max=k;s=p-k;
	}       //用指针s来指向最长字符的首字母地址//
	k=0;                     //判断完一个单词后,k取0以重新记录//
	}
    for(k=0;k<max;k++) //既然最长字符的首字母地址找到了,长度又找到了,当然可以输出了//
    putchar(*s++);       //注意不要写成putchar((*s)++)//
	printf("\n字符长度：%d \n", max);
}
