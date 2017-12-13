/* pointerTestCompatiable.c */
#include <stdio.h>
#include <conio.h>
int main()
{
    int *pt;
    int (*pa)[3];
    int **p2;
    int arr1[2][3]={0, 1, 2, 3, 4, 5};
    int arr2[3][2]={10, 20, 30, 40, 50, 60};
    
    printf("&arr1[0][0]=%x\n", &arr1[0][0]);    
    printf("&arr2[0][0]=%x\n\n", &arr2[0][0]);
    
    pt=&arr1[0][0];
    printf("pt=%x, &arr1[0][0]=%x\n", pt, &arr1[0][0]);
    pt=arr1[0];   /* 不要寫成 pt=arr1 */
    printf("pt=%x, arr1[0]=%x\n", pt, arr1[0]);
    pt=arr1[0];
    printf("*pt=%d\n", *pt);
    pa=arr1;  /* 不要寫成 pa=arr2 */ 
    printf("**pa=%d\n", **pa);
    p2=&pt;   /* 不要寫成p2=pt */ 
    printf("**p2=%d\n", **p2);
    *p2=arr2[0]; /* 要先將 p2指向某一變數的位址，如 p2=&pt */ 
    printf("*p2=%p, arr2[0]=%p\n", *p2, arr2[0]);
    printf("**p2=%d\n", **p2);
 
    getch();
    return 0;
}
