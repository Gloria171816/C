#include <stdio.h>
struct time{
    int hour;
    int minute;
    int second; 
};
int main(){
    struct time time1,time2; 
    int timestart, timeend, hours, minutes, seconds;
	printf("������ʼʱ��:");
    scanf("%d:%d:%d",&time1.hour,&time1.minute,&time1.second);
	printf("�������ʱ��:");
    scanf("%d:%d:%d",&time2.hour,&time2.minute,&time2.second);
	timestart=time1.hour*3600+time1.minute*60+time1.second;
	timeend=time2.hour*3600+time2.minute*60+time2.second;
	hours=(timeend-timestart)/3600;
	minutes=(timeend-timestart-3600*hours)/60;
	seconds=timeend-timestart-3600*hours-60*minutes;
	printf("��ʱ�����:%dСʱ%d��%d��\n",hours,minutes,seconds);
	return 0;
}
