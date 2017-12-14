#include <stdio.h>
#include <string.h>

int main(void)
{
#if 0
	int a=10;
	int b=020;
	int c=0x10;
	printf("a oct is %#o\n",a);
	printf("a hex is %#x\n",a);
	printf("b dec is %d\n",b);
	printf("b hex is %#x\n",b);
	printf("c dec is %d\n",c);
	printf("c oct is %#o\n",c);
#endif
	
	int num=0,i;
	int num2[5];
	memset(num2,0,sizeof(num2));
	struct book{
		int money;
		char *name;
		double fuck;
	}holly;
	holly.name="holly";
	printf("money is %d\nname is %s\nfuck is %lf\n",holly.money,holly.name,holly.fuck);

	printf("holly.name[0] is %c\n",holly.name[0]);
	
	holly.name="12345";
	printf("holly.name[0] is %c\n",holly.name[0]);
	for(i=0;i<=4;i++){
		num2[i]=holly.name[i]-'0';
		printf("num2 is %d\n", num2[i]);
	}
#if 0
	num=holly.name[1]-'0';
	printf("num is %d\n", num);
	num=holly.name[2]-'0';
	printf("num is %d\n", num);
	num=holly.name[3]-'0';
	printf("num is %d\n", num);
	num=holly.name[4]-'0';
	printf("num is %d\n", num);
#endif

}
