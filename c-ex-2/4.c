#include <stdio.h>
int main()
{
    int y,m,d,sum1=0,sum2=0,i=0,sumok1=0,sumok2=0;
    int a1[]={31,29,31,30,31,30,31,31,30,31,30,31};
    int a2[]={31,28,31,30,31,30,31,31,30,31,30,31};
    printf("����������(�ö��Ÿ���)��\n");
    scanf("%d,%d,%d",&y,&m,&d);
    if (y%4==0&&y%100!=0||y%400==0)  /*���꣬2��29��*/
    {
        while (i<m-1)
        {
        sum1=a1[i]+sum1;
        i++;
        }
        sumok1=sum1+d;    
        printf("���Ǹ���ĵ�%d��\n",sumok1);
    }
    else
    {
        while (i<m-1)
        {
        sum2=a2[i]+sum2;
        i++;
        }
        sumok2=sum2+d;
        printf("���Ǹ���ĵ�%d��\n",sumok2);
    }
	return 0;
}
