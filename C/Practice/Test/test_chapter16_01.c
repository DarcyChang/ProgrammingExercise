#include <stdio.h>
#include <test_chapter16_01.h>

#ifndef abc
	#define abc 100
#endif


int main(void)
{
#ifdef abc
	printf("abc is %d\n",abc);	
	return 0;
}


