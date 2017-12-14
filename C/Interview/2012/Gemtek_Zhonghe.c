/*2012/08/09 Thursday 14:00 pm*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define Q_size 256

static void *q[Q_size];
static int q_head=0;
static int q_tail=0;

void *get(void); // return an object or Null if queue is empty
int put(void *object); // return 1 if success or 0 if queue is full
int strl(char *);

int main(void)
{
	/*make a strlen function*/
#if 0
	int num=0;	
	char str[]="1 2 3 ";
	strl(str);
#endif
	/*FIFO queue with two function*/
//	exit(0);
	printf("fuck\n");		
	return 0;
}

int strl(char *string)
{
	int num=0;
	char ch;
	while(*(string++) != '\0')
		num++;
	printf("num is %d\n",num);
}

void *get(void)
{

}

int put(void *object)
{

}

