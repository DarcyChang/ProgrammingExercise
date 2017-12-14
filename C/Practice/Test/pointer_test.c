#include <stdio.h>
void fun(int *,int *);
void fun2(int & , int &);
int main(void)
{

	int aaa[3]={100,200,300};
	int *ptr;
	int a=10,b=20;
	int c=10,d=20;
	fun(&a,&b);
	printf("a is %d , b is %d\n",a,b);
	fun2(c,d);
	printf("c is %d , d is %d\n",c,d);
//	ptr=aaa;
//	scanf("%d",ptr);
//	printf("%d\n",*ptr);
//	printf("%d\n",*aaa);

 	return 0;
}
void fun(int *x, int *y)
{
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}
void fun2(int &j, int &k)
{
	int temp;
	temp=j;
	j=k;
	k=temp;
}
