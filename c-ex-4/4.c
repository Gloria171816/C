#include <stdio.h>
#include <stdlib.h>
void intoa (int value, char string[]);
void main(void)
{
    int value;
    char str[10] = {0};

    printf("请输入一个整数: ");
    scanf("%d", &value);
    intoa(value, str, 10);
    printf("%s\n", ch);
}
