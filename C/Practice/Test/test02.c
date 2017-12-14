#include <stdio.h>
#include <string.h>

int main()
{
 int a = 0;
 float b = 123.456f;
 
 memcpy(&a, &b, 32);
	printf("int a = %d\n", a);
 a=a<<1;
 a=a>>24;
 
 printf("%d\n",a);
 return 0;

}
