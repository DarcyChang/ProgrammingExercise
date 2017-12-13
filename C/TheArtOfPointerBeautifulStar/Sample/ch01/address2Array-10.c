/* address2Array-10.c */
#include <stdio.h>
#include <conio.h>
int main()
{
	int x[][3] = {10, 20, 30, 40, 50, 60};
    int i, j;
 
    printf("x = %#x\n", x);

    printf("\n");
	for(i=0; i<2; i++)
		printf("x[%d] = %#x\n", i, x[i]);

    printf("\n");
	for(j=0; j<6; j++)
		printf("x[0]+%d = %#x\n", j, x[0]+j);
 		
    printf("\n");
	for(j=0; j<3; j++)
		printf("x[1]+%d = %#x\n", j, x[1]+j);

    printf("\n");
	for(i=0; i<2; i++)
		printf("x+%d = %#x\n", i, x+i);    
    getch();
	return 0;
}
