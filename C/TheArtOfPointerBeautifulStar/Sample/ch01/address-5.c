/* address-5.c*/
#include <stdio.h>
#include <stdlib.h>
 
int main()
{
    double x, y, average;
    printf("請輸入浮點數x與y: ");
    scanf("%lf %lf", &x, &y);
    average = (x+y)/2;
    printf("x與y的平均數為: %.2f\n", average);
    system("PAUSE");
    return 0;
} 
    
    
