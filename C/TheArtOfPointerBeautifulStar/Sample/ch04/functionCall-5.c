/* functionCall-5.c*/
#include <stdio.h>
#include <stdlib.h>
double average(double, double);
int main()
{
    double x, y, aver;
    printf("�п�Jx�Py���B�I��: ");
    scanf("%lf %lf", &x, &y);
    aver=average(x, y);
    printf("x�Py�������Ƭ�: %.2f\n", aver);
    system("PAUSE");
    return 0;
} 

double average(double a, double b)
{
    double average;
    average=(a+b)/2;
    return average;
}
    
    
