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
/* ʵ��itoa������Դ���� */
char *myitoa(int num,char *str,int radix)
{
/* ������ */
char index[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
unsigned unum; /* �м���� *
int i=0,j,k;
/* ȷ��unum��ֵ */
if(radix==10&&num<0) /* ʮ���Ƹ��� */
{
unum=(unsigned)-num;
str[i++]='-';
}
else unum=(unsigned)num; /* ������� */
/* ���� */
do C���Գ���
  C���Գ���
{
str[i++]=index[unum%(unsigned)radix];
unum/=radix;
}while(unum);
str[i]='\0';
/* ת�� */
if(str[0]=='-') k=1; /* ʮ���Ƹ��� */
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
itoa�ĵ������������ڽ�����ת���ɲ�ͬ�Ľ��ơ��ٸ����ӣ�
#include <stdlib.h>
#include <stdio.h>
int main(void)
{
int number = 12345;
char string[25];
itoa(number, string, 10); //��ʮ����ת��
printf("integer = %d string = %s\n", number, string);
itoa(number, string, 16); //��16����ת��
printf("integer = %d string = %s\n", number, string);
return 0;
}
