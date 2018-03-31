#include <stdio.h> 
void main() 
{
	char c1 = getchar(); 
	char c2 = getchar(); 
	putchar(c1);
	putchar(c2); 
	printf("\n");
	printf("%c %c\n", c1, c2); 
	printf("ASCII:%d %d\n", c1, c2);
}  
