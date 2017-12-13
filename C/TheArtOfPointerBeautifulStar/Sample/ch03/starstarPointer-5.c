/*  starstarPointer-5.c  */
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i[] = {10, 20, 30, 40, 50};
    int *pa[] = {i, i+2, i+1, i+4, i+3};
    int **p2 = pa;
    printf("Initial **p2 = %d\n", **p2);
    p2++;
    printf("After p2++, the	**p2 = %d\n", **p2);
    ++*p2;
    printf("After ++*p2, the **p2 = %d\n", **p2);
    **p2++;
    printf("After **p2++, the **p2 = %d\n", **p2);
    ++**p2;
    printf("After ++**p2, the **p2 = %d\n", **p2);
    system("PAUSE");
    return 0;
}
