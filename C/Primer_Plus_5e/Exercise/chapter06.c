#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
float cond(float a, float b);
int main(void)
{
	/*	quention	*/
	/*	05	*/
#if 0
	int i,j,list[10];
	for(i=0;i<10;i++)
	{
		list[i]=2*i+3;
		for(j=0;j<=i;j++)
			printf("%d", list[j]);
		printf("\n");
	}
	printf("i = %d , j = %d \n", i, j);
#endif

	/*	08.a	*/
#if 0
	char ch;
	scanf("%c", &ch);
	while(ch!='g')
	{
		printf("%c",ch);	
		scanf("%c", &ch);
	}

	
	int row=0;
	for(row=0;row<10;row++)
		printf("row=%d\n",row);
	printf("final row=%d\n",row);	
#endif

	/*	10.d	*/
#if 0
	double mint[10];
	char aaa[10];

	scanf("%lf", &mint[2]);
	printf("mint[2]=%lf\n", mint[2]);
	scanf("%c", &aaa[2]);
	printf("aaa[2]=\'%c\'\n", aaa[2]);
#endif

	/*	coding	*/
	/*	01	*/
#if 0
	char word[26],ch='a';
	int i;
	for(i=0;i<26;i++)
	{
		word[i]=ch+i;
		printf(" %d = %c \n", i+1,word[i]);
	}
#endif

	/*	02	*/
#if 0
	int row,col;
	for(row=0;row<5;row++)
	{
		for(col=0;col<=row;col++)
			printf("$");
		printf("\n");
	}
#endif

	/*	03	*/
#if 0	
	char ch='F';
	int row,col;
	for(row=0;row<6;row++)
	{
		for(col=0;col<=row;col++)
			printf(" %c", ch-col);
		printf("\n");
	}	
	printf("\n*******\n");
	char lets[26]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int r=5,c=5;
	while(r-->=0)
	{
		c=5;
		while(c-->=r+1)
			printf(" %c ",lets[c+1]);
		printf("\n");
	}
#endif

	/*	04	*/
#if 0
	char ch;
	int width=5,row,col,c;
	printf("Please input a word:");
	for(row=0,scanf("%c",&ch);row<5;row++)
	{
		printf("%*c", width-row, ch);
		for(col=1;col<=row;col++)
		{
			printf("%c",ch+col);	
		}
		for(c=row;c>0;c--)
			printf("%c",ch+c-1);
		printf("\n");
	}
#endif

	/*	05	*/
#if 0
	int min,max;
	printf("Please input min and max number:");
	for(scanf("%d %d", &min, &max),printf("n	n*n		n*n*n\n");min*min*min<max;min++)
		printf("%d	%d		%d\n",min,min*min,min*min*min);
#endif

	/*	06	*/
#if 0	
	char word[20];
	int len;
	for(printf("please input a word:"),scanf("%s",word),len=strlen(word);len>=0;len--)
		printf("%c",word[len]);
	printf("\n");			
#endif
	
	/*	07	*/
#if 0
	float foo, bar, result=0;
	while(printf("Please input two float number:")&&scanf("%f %f",&foo, &bar)==2)
	{	
		result=(foo-bar)/(foo*bar);
		printf("result is %f\n",result);
	}

	for(printf("Please input two float number:");scanf("%f %f",&foo,&bar)==2;printf("Please input two float number:"))
	{
		result=(foo-bar)/(foo*bar);
		printf("result is %f\n",result);
	}
#endif

	/*	08	*/
#if 0
	float foo, bar, result=0;
    while(printf("Please input two float number:")&&scanf("%f %f",&foo, &bar)==2)
    {   
        result=cond(foo,bar);
        printf("result is %f\n",result);
    }
#endif
	/*	09	*/
#if 0
	int row,num[8];
	for(printf("Please input eight number:"),row=0;row<8;row++)
		scanf("%d",&num[row]);
	for(row=7;row>=0;printf("%d",num[row]),row--)
	{}
	printf("\n");
#endif
	
	/*	10	*/
#if 0
	double cond1=1.0,cond2=0.0;
	float i;
	int j;
	printf("Please input a number:");
	scanf("%d",&j);
	for(i=1;i<=j;i+=1)
		cond1=cond1+1.0/(i+1.0);
	for(i=0;i<=j;i+=2)
        cond2=cond2+1.0/(i+1);
	for(i=1;i<=j;i+=2)
		cond2=cond2-1.0/(i+1);
	printf("cond1 = %lf , cond2 = %lf\n", cond1, cond2);
#endif
	
	/*	11	*/
#if 0
	int row,num[8];
	for(row=1;row<9;row++)
	{
		num[row-1]=pow(2,row);
		printf("for loop 2^%d is %d\n", row, num[row-1]);
	}
	row=1;
	do
	{
		num[row-1]=pow(2,row);
		printf("do-while loop 2^%d is %d\n", row, num[row-1]);
	}while(row++<8);	
#endif	
	/*	12	*/
#if 0
	double num1[8],num2[8];
	int row;
	for(scanf("%lf",&num1[0]),num2[0]=num1[0],row=1;row<8;row++)
	{
		scanf("%lf",&num1[row]);
		num2[row]=num1[row]+num2[row-1];
	}
	row=0;
	while(row++<8)
		printf("%lf,", num1[row-1]);
	printf("\n");
	row=0;
	while(row++<8)
     	printf("%lf,", num2[row-1]);
	printf("\n");
#endif	
	/*	13	*/
#if 0
	char ch[4];
	int row;
	for(row=0;row<4;row++)
	{
		scanf("%c",&ch[row]);
	}
	printf("\n");
	for(row=strlen(ch),printf("row is %d\n",row);row>=0;row--)
		printf("%c\n", ch[row]);
#endif
	/*	14	*/
#if 0
	double Daphne=100,Deirdre=100;
	int year;
	for(year=1;Daphne>=Deirdre;year++)
	{
		Daphne+=10;
		Deirdre=Deirdre+Deirdre*0.05;
	}	
	printf("%d year later, Daphne's money is %lf , Deirdre's money is %lf\n", year, Daphne, Deirdre);
#endif
	/*	15	*/
#if 0
	double account=1000000;
	int year=1;
	while(account>0)
	{
		account=account+account*0.08-100000;
		year++;
	}
	printf("%d year later, Chuckie Lucky have no money: %lf\n",year, account);
#endif
	return 0;

}//end for main function


float cond(float a, float b)
{
	float c=0;
   	c=(a-b)/(a*b);
    return c;
}
