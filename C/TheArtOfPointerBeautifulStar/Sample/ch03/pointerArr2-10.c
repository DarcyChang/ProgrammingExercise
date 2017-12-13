/* pointerArr2-10.c */  
#include <stdio.h>
#include <conio.h>

int main()
{
     int k[3][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
     printf("&k[1][2] = %p\n", &k[1][2]);
     printf("k[1][2] = %d\n", k[1][2]);
     printf("*(k + 1) + 2 = %p\n", *(k + 1) + 2);
     printf("*(*(k + 1) + 2) = %d\n", *(*(k + 1) + 2));
     printf("k[1] + 2 = %p\n", k[1] + 2);
     printf("*(k[1] + 2) = %d\n", *(k[1] + 2));
     getch();
     return 0;
}
