#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#define money 10
#define overtime 40
int main(void)
{
	/*Quention*/
	/*08 retire.c*/
#if 0
	int age = 20;
	while(age++ <= 65)
	{
		printf("age is %d.\n", age);
		if((age % 20)==0)
			printf("You are %d. Here is a raise.\n", age);
		if(age=65)
			printf("You are %d. Here is your gold watch.\n", age);
	}
#endif
	/*10*/
#if 0	
	char ch;
	while((ch = getchar()) != '#')
	{
		if(ch != '\n')
		{
			printf("Step 1\n");
			if(ch != 'c')
			{
				if(ch == 'b')
					break;
				else if(ch == 'g')
				{
					printf("Step 3\n");
					continue;
				}
				printf("Step 2\n");	
				printf("Step 3\n");	
			}
				
		}
		
	}
	printf("Done\n");
#endif


	/*coding*/
	/*01*/
#if 0
	char ch;
	int isspace=0,isenter=0,isother=0;
	printf("Please enter any char, '#' is quit.\n");
	while((ch = getchar()) != '#')
	{
		if(ch == ' ')
			isspace++;
		else if(ch == '\n')
			isenter++;
		else
			isother++;
	}
	
	printf("    isspace    isenter    isother\n");
	printf("%8d %10d %12d\n", isspace, isenter, isother);
#endif
	/*02*/
#if 0
	char ch;
	int eight=0;	
	printf("Please enter eight char, '#' is quit.\n");
	while((ch = getchar()) != '#')
	{
		if(ch != '\n')
		{
			printf("%c-%d ; ", ch, ch);
			eight++;
			if(eight % 8 == 0)
			{
				printf("\n");
				eight=0;
			}
		}	
	}
#endif
	/*03*/
#if 0
	int num=0;
	int even=0,odd=0;
	float evenaverage=0,oddaverage=0;
	printf("Please enter any number, '0' is quit.\n");
	while(scanf("%d",&num) && num != 0)
	{
		if(num%2 == 0)
		{
			even++;
			evenaverage+=num;	
		}
		else
		{
			odd++;
			oddaverage+=num;
		}
	}
	printf("odd have %d , average is %f\n", odd, oddaverage/odd);
	printf("even have %d , average is %f\n", even, evenaverage/even);
#endif	
	/*04*/
#if 0
	char ch;
	int total=0;	
	printf("Please enter any char, '#' is quit.\n");
	while((ch = getchar()) != '#')
	{
		if(ch == '.')
		{
			ch = '!';
			total++;
		}
		else if(ch == '!')
		{
			ch = '.';
			total++;
		}
		putchar(ch);
	}
	printf("Change number is %d\n", total);
#endif
	/*05*/
#if 0
	int num=0;
	int even=0,odd=0;
	float evenaverage=0,oddaverage=0;
	printf("Please enter any number, '0' is quit.\n");
	while(scanf("%d",&num) && num != 0)
	{
		switch(num%2)
		{
			case 0 : even++;
					 evenaverage+=num;
					 break;		
			case 1 : odd++;
					 oddaverage+=num;
					 break;
		}
	}
	printf("odd have %d , average is %f\n", odd, oddaverage/odd);
	printf("even have %d , average is %f\n", even, evenaverage/even);
#endif
	/*06*/
#if 0
	char ch;
	int flag=0,ei=0;	
	printf("Please enter any string, '#' is quit.\n");
	while((ch = getchar()) != '#')
	{
		if(ch == 'e')
			flag=1;
		else if(ch != 'i')
			flag=0;
		if(flag == 1 && ch == 'i')
		{
			ei++;
			flag=0;
		}
		putchar(ch);
	}
	printf("ei number is %d\n", ei);
#endif
	/*07*/
#if 0
	int hours=0;
	float pay=0;
	printf("How many work hours are you on a week?");
	scanf("%d", &hours);
	if(hours <= overtime)
		pay = money * hours;
	else
		pay = (money * overtime) + ((money*0.5)*(hours-overtime));
	printf("your pay is %f\n", pay);
	if(pay <= 300)
		pay= pay-(pay*0.15);
	else if(pay <= 450)
		pay = pay - ((300*0.15)+((pay-300)*0.2));
	else if(pay > 450)
		pay = pay - (300*0.15+150*0.2+((pay-450)*0.25));
	printf("your pay - tax rate is %f\n", pay);	
#endif
	/*08*/
#if 0
	int hours=0,choose=0;
	float pay=0,hourpay=0;
	while(choose != 5)
	{
		printf("*****************************************************************\n");
		printf("Enter the number corresponding to the desired pay rate or action:\n");
		printf("1) $8.75/hr                         2) $9.33/hr\n");
		printf("3) $10.00/hr                        4) $11.20/hr\n");
		printf("5) quit\n");
		printf("*****************************************************************\n");
		scanf("%d",&choose);
		switch(choose)
//		switch(scanf("%d",&choose)) // why does error?
		{
			case 1 :hourpay = 8.75;
					break;
			case 2 :hourpay = 9.33;
					break;
			case 3 :hourpay = 10.00;
					break;
			case 4 :hourpay = 11.20;
					break;
			case 5 :break;
			default :printf("you enter a wrong number!Please enter a number retry:");
		}
		printf("hourpay is %f\n",hourpay);
		if(choose >= 1 && choose <= 4)
		{	
			printf("How many work hours are you on a week?");
			scanf("%d", &hours);
			if(hours <= overtime)
				pay = hourpay * hours;
			else
				pay = (hourpay * overtime) + ((hourpay*0.5)*(hours-overtime));
			printf("your pay is %f\n", pay);
			if(pay <= 300)
				pay= pay-(pay*0.15);
			else if(pay <= 450)
				pay = pay - ((300*0.15)+((pay-300)*0.2));
			else if(pay > 450)
				pay = pay - (300*0.15+150*0.2+((pay-450)*0.25));
			printf("your pay - tax rate is %f\n", pay);	
		}
	}
#endif
	/*09*/
#if 0
	int num=0,c,r,flag=0;
	printf("Please enter a number:");
	scanf("%d", &num);
	for(c=2;c<=num;c++)
	{
		for(r=2;r<c;r++)
		{
			if(c%r ==0)
			{
				flag=1;
				break;
			}
		}
		if(flag==0)
			printf("%d\n",c);
		flag=0;
	}
#endif
	/*10*/
#if 0
	int num=0;
	float pay=0;
	while(num != 5)
	{
		printf("********************************************\n");
		printf("1.single           17850 is 15%, over is 28%\n");
		printf("2.home             23900 is 15%, over is 28%\n");
		printf("3.married and com  29750 is 15%, over is 28%\n");
		printf("4.married and pri  14875 is 15%, over is 28%\n");
		printf("5.quit\n");
		printf("********************************************\n\n");
		printf("Please choose one and enter your pay:");
		scanf("%d %f", &num, &pay);
		switch(num)
		{
			case 1:
					if(pay<=17850)
						pay=17850*0.15;
					else
						pay=(17850*0.15)+((pay-17850)*0.28);	
					printf("tax is %f\n\n", pay);
				    break;
			case 2:
					if(pay<=23900)
						pay=23900*0.15;
					else
						pay=(23900*0.15)+((pay-23900)*0.28);	
					printf("tax is %f\n\n", pay);
				    break;
			case 3:
					if(pay<=29750)
						pay=29750*0.15;
					else
						pay=(29750*0.15)+((pay-29750)*0.28);	
					printf("tax is %f\n\n", pay);
				    break;
			case 4:
					if(pay<=14875)
						pay=14875*0.15;
					else
						pay=(14875*0.15)+((pay-14875)*0.28);	
					printf("tax is %f\n\n", pay);
				    break;
			case 5: 
					printf("quit the system!\n", pay);
					break;
		}
	}
#endif
	/*11*/
	int num =0;
	float pound_num=0,total=0,A=0,B=0,C=0,discount=0;
	while(num !=4)
	{
		printf("********************************************\n");
		printf("1.A   $1.25 for per pound\n");
		printf("2.B   $0.65 for per pound\n");
		printf("3.C   $0.89 for per pound\n");
		printf("4.quit\n");
		printf("********************************************\n\n");
		printf("Please choose one and enter your pound:");
		scanf("%d %f", &num, &pound);
		switch(num)
		{
			case 1:
					A=pound*1.25;
					if(A>100)
						discount=A*0.05;
						A-=discount;
					if(pound<=5)
						A+=3.5;
					else if(pound>5&&pound<20)
						A+=10;
					else if(pound>=20)
						A=A+8+pound*0.1;

	}
	printf("");
	return 0;	
}
