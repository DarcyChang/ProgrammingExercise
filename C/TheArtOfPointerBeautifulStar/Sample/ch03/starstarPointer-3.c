/* starstarPointer-3.c */
#include <stdio.h>
#include <conio.h>

int main()
{
    int i[5]={10, 20, 30, 40, 50};
	int *ptr[] = {i, i+1, i+2, i+3, i+4};
	int **p2 = ptr;
    int k;
 
    for(k=0; k<5; k++)
	     printf("*ptr[%d]=%d\n", k, *ptr[k]);

    printf("\n");
	for(k=0; k<5; k++)
        printf("**(p2+%d) = %d\n", k, **(p2+k));
    getch();
    return 0;
}
