#include<stdio.h>
#define PI 3.14159
float area(float r)
{    
    float s;
    s=PI*r*r;
    return(s);
}
main()
{
    float r1,r2,s;
    scanf("%lf %lf",&r1,&r2);
    s=area(r1)-area(r2);
    printf("s=%f\n",s);
}

