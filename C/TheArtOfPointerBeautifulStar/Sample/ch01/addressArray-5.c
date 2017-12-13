/* addressArray-5.c */
#include <stdio.h>
#include <conio.h>
int main()
{
	int x[5];
    int i;

	for(i=0; i<5; i++)
	{
		printf("請輸入x[%d]的整數值: ", i);
		scanf("%d", &x[i]);
    }		
	for(i=0; i<5; i++)
		printf("x[%d] = %d\n", i, x[i]);	
    printf("\n");
    
  	for(i=0; i<5; i++)
	{
		printf("請輸入x[%d]的整數值: ", i);
		scanf("%d", x+i);
    }		
	for(i=0; i<5; i++)
		printf("x[%d] = %d\n", i, x[i]);	
    printf("\n");
    getch();
	return 0;
}

