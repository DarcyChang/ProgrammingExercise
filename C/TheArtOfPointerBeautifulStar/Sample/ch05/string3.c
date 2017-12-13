/* string3.c */
#include <stdio.h>
#include <conio.h> 
int main()
{
	char *str = "Apple iPod";
    int i; 
 	printf("¦r¦êstr¬°: ");
    for(i=0; *str!='\0'; i++)
    {
       printf("%c", *str);
       str++;
    }
    getch();
	return 0;
}
