#include <stdlib.h>
#include <stdio.h>
int main()
{
int number = 123456;
char string[25];
itoa(number, string, 10);
printf("integer = %d string = %s\n", number, string);
return 0;
}
/* 实现itoa函数的源代码 */
char *myitoa(int num,char *str,int radix)
{
/* 索引表 */
char index[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
unsigned unum; /* 中间变量 *
int i=0,j,k;
/* 确定unum的值 */
if(radix==10&&num<0) /* 十进制负数 */
{
unum=(unsigned)-num;
str[i++]='-';
}
else unum=(unsigned)num; /* 其他情况 */
/* 逆序 */
do C语言程序
  C语言程序
{
str[i++]=index[unum%(unsigned)radix];
unum/=radix;
}while(unum);
str[i]='\0';
/* 转换 */
if(str[0]=='-') k=1; /* 十进制负数 */
else k=0;
char temp;
for(j=k;j<=(i-k-1)/2;j++)
{
temp=str[j];
str[j]=str[i-j-1];
str[i-j-1]=temp;
}
return str;
}
itoa的第三个参数用于将数字转换成不同的进制。举个例子：
#include <stdlib.h>
#include <stdio.h>
int main(void)
{
int number = 12345;
char string[25];
itoa(number, string, 10); //按十进制转换
printf("integer = %d string = %s\n", number, string);
itoa(number, string, 16); //按16进制转换
printf("integer = %d string = %s\n", number, string);
return 0;
}
