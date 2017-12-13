/* pointerOfArray-10.c  */
#include <stdio.h>
#include <stdlib.h>

int main()
{
     int arr2[3][4] = {0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22};
     int *parr[3] = {arr2[0], arr2[1], arr2[2]};
     printf("&arr2[0][0] = %p\n\n", &arr2[0][0]);
     printf("*(parr + 1) = %p\n", *(parr + 1));
     printf("*(parr[1] + 1) = %d\n", *(parr[1] + 1));
     printf("parr[2] + 3 = %p\n", parr[2] + 3);
     printf("arr2[1] + 3 = %p\n", arr2[1] + 3);
     printf("*(arr2[2] + 2) = %d\n", *(arr2[2] + 2));
     system("PAUSE");
     return 0;
}
