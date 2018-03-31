#include <stdio.h>
struct time{
    int hour;
    int minute;
    int second; 
};
int main(){
    struct time time1,time2; 
    int timestart, timeend, hours, minutes, seconds;
	printf("输入起始时刻:");
    scanf("%d:%d:%d",&time1.hour,&time1.minute,&time1.second);
	printf("输入结束时刻:");
    scanf("%d:%d:%d",&time2.hour,&time2.minute,&time2.second);
	timestart=time1.hour*3600+time1.minute*60+time1.second;
	timeend=time2.hour*3600+time2.minute*60+time2.second;
	hours=(timeend-timestart)/3600;
	minutes=(timeend-timestart-3600*hours)/60;
	seconds=timeend-timestart-3600*hours-60*minutes;
	printf("两时刻相差:%d小时%d分%d秒\n",hours,minutes,seconds);
	return 0;
}
