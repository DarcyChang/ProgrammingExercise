/*1+2-3+4-5+6-7+8-9+10........n */

#include <stdio.h>

int main(void)
{
	int n,sum=1;
	printf("please enter a number:");
	scanf("%d",&n);
	if(n%2==0)
		sum=sum+(n/2+1);
	else
		sum=sum-((n-1)/2);
	printf("%d's sum is %d\n",n,sum);
}
