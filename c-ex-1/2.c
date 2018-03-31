#include <stdio.h>
int main()
{
    double rad, high, area, vol;
	printf("Please input number rad and high: ");
	scanf("%lf,%lf", &rad,&high);
	area = 3.1416 * rad * rad;
	vol = rad * rad * high;
	printf("Output:\n");
	printf("area=%.2f\n", area);
	printf("Vol=%.2f\n", vol);
	return 0;
}
