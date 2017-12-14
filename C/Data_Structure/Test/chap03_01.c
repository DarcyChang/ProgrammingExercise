/*stack exercise*/

#include <stdio.h>
#include <stdlib.h>
#define max 10
//void push(int * , int stack[]);
//void pop(int * , int stack[]);
void push(int * , int *);
void pop(int * , int *);

int main(void)
{
	int top=-1,num=0,c=0;
	int stack[max]={0};
	printf("choose your need and enter a number:\n");
	printf("1.push\n");
	printf("2.pop\n");
	printf("3.list the stack\n");
	printf("4.enter 'q' is quit\n");
	printf("------------------------------------\n");
	while(scanf("%d",&num)==1)
	{
		switch(num)
		{
			case 1: push(&top,stack);
				break;
			case 2: pop(&top,stack);
				break;
			case 3: 
				for(c=0;c<=top;c++)
					printf("The stack item %d is %d\n", c, stack[c]);
				break;
			default:printf("you enter a wrong number, please enter again!\n");
		}
	}

	return 0;
}

void push(int *top , int *stack)
{
	if(*top>=max-1)
		printf("stack has been full!\n");
	else
	{
		(*top)++;
		scanf("%d", &stack[*top]);
	}
}
void pop(int *top , int *stack)
{
	if(*top<0)
		printf("stack is empty!\n");
	else
	{
		printf("The item %d : %d has been delete.\n", *top, stack[*top]);
		(*top)--;
	}
}

