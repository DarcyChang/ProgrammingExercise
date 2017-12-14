#include <stdio.h>
#define FORMAT "%s is a string"
#define FORMAT2 "aaaaa"
#define TEN 104
#define sixty 60
#define seven 7
void triple(float a);
void Temperatures(double a);
int main(void)
{
#if 0
	//--- QA ---//
	//--- 05 ---//
	printf(FORMAT,FORMAT);
#endif

#if 0
	//    08    //
	char n='a';
	while(n<TEN)
	{
		printf("%5c",n);
		n++;
	}
	printf("\n");
#endif

	//	coding	//
	//	01	//	
#if 0
	int min=1;
	printf("please input minute value again:\n");
	scanf("%d", &min);
	while(min>0)
	{
		printf("%d minute is %d hour %d minute\n", min, min/sixty, min%sixty);
		printf("please input minute value again:\n");
		scanf("%d", &min);
	}
#endif	
	
	//	02	//
#if 0
	int value=0,a=0;
	printf("please input a integer value:");
	scanf("%d",&value);
	a=value+10;
	while(value++ <= a)
	{
		printf("  %d  ",value-1);
	}
	printf("\n");
#endif
	
	//	03	//
#if 0
	int days=0;
	printf("please input days:");
	while(scanf("%d", &days)==1)
	{
		printf("%d days are %d weeks, %d days\n", days, days/seven, days%seven);
		printf("please input days:");
	}
#endif

	//	04	//	
#if 0
	int count=0, sum=0, aaa=0;
  	printf("please input a value:");
	scanf("%d",&aaa);
	while(count++ < aaa)
 		sum = sum + count; 	
	printf("sum = %d\n", sum);
#endif
	
	//	05	//
#if 0
        int count=0, sum=0, aaa=0;
        printf("please input a value:");
        scanf("%d",&aaa);
        while(count++ < aaa)
                sum = sum+count*count;
        printf("sum = %d\n", sum);
#endif
	//	06	//
#if 0
	float num=0;
	printf("please input number:");
	scanf("%f",&num);
	triple(num);	
#endif
	//	07	//
	double fah=0; //Fahrenheit
	printf("please input Fahrenheit Temperatures:");
	while(scanf("%lf", &fah)==1)
	{
		Temperatures(fah);
		printf("please input Fahrenheit Temperatures:");
	}
	return 0;
}

void triple(float b)
{
	printf("n*n*n = %f\n", b*b*b);
}

void Temperatures(double b)
{
	const double cel=1.8*b+32.0; //Celsius
	const double abs=cel+273.16; //absolute
	printf("Fahrenheit is %.2lf, Celsius is %.2lf, absolute is %.2lf\n", b, cel, abs);

}
