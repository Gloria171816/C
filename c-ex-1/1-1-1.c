#include <stdio.h>
#include <math.h>
int main()
{
	float r5,r3,r2,r1,r0,p1,p2,p3,p4,p5,p;
	p=1000;
	r5=0.0475;
	r3=0.0425;
	r2=0.0375;
	r1=0.0300;
	r0=0.0035;
	p1=p*(1+r5*5);
	p2=p*(1+r2*2)*(1+r3*3);
	p3=p*(1+r3*3)*(1+r2*2);
	p4=p*pow(1+r1, 5);
	p5=p*pow(1+r0/4, 4*5);
	printf("p1=%f\n", p1);
	printf("p2=%f\n", p2);
	printf("p3=%f\n", p3);
	printf("p4=%f\n", p4);
	printf("p5=%f\n", p5);
	return 0;
}