#include <stdio.h>
double min(double,double);
void chline(char,int,int);
void larger_of(double * , double *);
int main(void)
{
	/*coding*/
	/*01*/
#if 0
	double x=0,y=0;
	scanf("%lf %lf", &x,&y);
	printf("%lf and %lf is %lf smallest.\n", x, y, min(x,y));
#endif
	/*02*/
#if 0
	char ch;
	int i=0,j=0;
	printf("Please enter a char,a start position, a end position.\n");
	ch=getchar();
	scanf("%d %d", &i,&j);
	chline(ch,i,j);
	printf("123456789123456789123456789123456789\n"); //for test
#endif
	/*03*/
	/*04*/
	/*05*/
#if 0
	double a,b;
	printf("Please enter two number:");
	scanf("%lf %lf",&a,&b);
	larger_of(&a,&b);
	printf("two number is %lf and %lf.\n",a,b);
#endif
	/*06*/
	return 0;
}
double min(double x, double y)
{
	return (x<y)?x:y;
}

void chline(char ch,int i,int j)
{
	int c=0;
	for(c=1;c<i;c++)	
		putchar(' ');
	for(c=i;c<=j;c++)
		putchar(ch);
	putchar('\n');
}

void larger_of(double * u, double * v)
{
//	*u > *v ? *v=*u : *u=*v; //why?
	if(*u>*v)
		*v=*u;
	else
		*u=*v;
}
