#include <stdio.h>
int isleap(int y)
{
    if(y%400==0||y%4==0&&y%100!=0)
    return(1);
    else
    return(0);
}
main()
{
    int year;
    for(year=1;year<=500;year++)
    {
        if(isleap(year)!=0) 
        printf("%d,",year);
	}
    printf("\n");
    return 0;
}
