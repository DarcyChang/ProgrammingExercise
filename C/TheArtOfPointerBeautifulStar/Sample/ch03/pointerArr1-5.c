/* pointerArr1-5.c */    
#include <stdio.h>
#include <conio.h>

int main()
{
    int arr[]= {100, 101, 102};
    int *ptr = arr;
    int i, size = 0;
    size = (sizeof arr/ sizeof (arr[0]) );
    
	/* ------------Using arr--------------*/   
	printf("使用 arr 指標常數來表示:\n");
    for(i = 0; i < size; i++)
        printf("&arr[%d] = %x\n", i, &arr[i]); 
        
	printf("\n");     
    for(i = 0; i < size; i++)
        printf("arr+%d = %x\n", i, arr+i);
     
    printf("\n");
	for(i = 0; i < size; i++)
        printf("arr[%d] = %x\n", i, arr[i]); 
     
	printf("\n");
    for(i = 0; i < size; i++)
        printf("*(arr+%d) = %x\n", i, *(arr+i)); 

	/*--------------Using ptr-------------*/
    printf("\n使用ptr 指標常數來表示:\n");
    for(i = 0; i < size; i++)
        printf("ptr+%d = %x\n", i, ptr+i);
        
   	printf("\n");
    for(i = 0; i < size; i++)
        printf("ptr[%d] = %d\n", i, ptr[i]); 

	printf("\n");
    for(i = 0; i < size; i++)
        printf("*(ptr+%d) = %d\n", i, *(ptr+i)); 
    getch();
    return 0;
}
