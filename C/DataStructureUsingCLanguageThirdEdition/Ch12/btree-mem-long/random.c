/*****************************************************************************
 * btree-mem-C/random.c
 *
 * COPYRIGHT (c) 1995, 1997 by David Van Wagner ALL RIGHTS RESERVED
 * Source and executables may be distributed under the terms of the GNU
 * General Public License version 2, see the file COPYING for details.
 *
 * davevw@alumni.cse.ucsc.edu
 * http://alumni.cse.ucsc.edu/~davevw/
 *****************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <memory.h>
#include <math.h>
#include <time.h>
#include "my_assert.h"

#ifndef RAND_MAX
#define RAND_MAX ((unsigned long)(2<<30))-1
#endif

#define random_int(x) (int)((double)(rand())*x/(double)((unsigned long)RAND_MAX+1))

int main(int argc, char *argv[])
{
	long data[10000];
	const int count=sizeof(data)/sizeof(*data);
	int i;

	if (argc > 1)
		srand(atoi(argv[1]));

	/* initialize the data */
	for (i=0; i<count; ++i) {
		data[i] =i;
	}

	/* randomize the data via swapping each element with a random position */
	for (i=0; i<count; ++i) {
		long temp;
		int swap = random_int(10000);
		if (swap < 0 || swap >= 10000)
			printf("swap = %d\n", swap);
		assert(swap >=0 && swap <10000);
		temp=data[swap];
		data[swap]=data[i];
		data[i]=temp;
	}

	for (i=0; i<count; ++i)
		printf("%ld\n",data[i]);

	return 0;
}
