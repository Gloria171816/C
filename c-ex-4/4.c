#include <stdio.h>
#include <stdlib.h>
void intoa (int value, char string[]);
void main(void)
{
    int value;
    char str[10] = {0};

    printf("������һ������: ");
    scanf("%d", &value);
    intoa(value, str, 10);
    printf("%s\n", ch);
}
