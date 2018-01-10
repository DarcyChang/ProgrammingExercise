/*****************************************************************************
 * btree-mem-long/test_btree.c
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
#include "btree.h"

#ifndef CLOCKS_PER_SEC
#define CLOCKS_PER_SEC 1000000
#endif

int main(int argc, char *argv[])
{
	int count=10000;
	BTREE_KEY *data=(long *)malloc(sizeof(long)*count);
	int i, j;
	int levels, repeat;
 	BTREE_POS pos;
	int debug_i_start, debug_i_end;
	int debug_count=0;
	int debug_slow=0;
	int debug_progress=0;
	BTREE *tree;
	char s[100];
	FILE *fp;

	if (getenv("COUNT") != NULL)
		count = atoi(getenv("COUNT"));

	if (getenv("DEBUG_COUNT") != NULL)
		debug_count=1;

	if (getenv("DEBUG_SLOW") != NULL)
		debug_slow=1;

	if (getenv("DEBUG_PROGRESS") != NULL)
		debug_progress=1;

	if (argc == 1)
		fp=fopen("random.data", "r");
	else
		fp=fopen(argv[1], "r");

	if (argc > 2)
		debug_i_start = atoi(argv[2]);
	else
		debug_i_start = -1;

	if (argc > 3)
		debug_i_end = atoi(argv[3]);
	else
		debug_i_end = debug_i_start;

	if (fp == NULL) {
		perror("btree");
		return 1;
	}

	/* read the data */
	for (i=0; i<count; ++i) {
		if (fgets(s, sizeof(s), fp) == NULL) {
			fprintf(stderr, "btree: fgets returned NULL, exiting, i=%d\n", i);
			return 1;
		}
		data[i] = atol(s);
	}

	fclose(fp);

	/* test for orders 3 through 31 */
	for (BTREE_ORDER=3; BTREE_ORDER<=31; BTREE_ORDER+=2)
		/* repeat each test three times */
		for (repeat=0; repeat<1; ++repeat) {
			clock_t now;
			clock_t then=clock();
		
			tree = btree_new();
			assertf(btree_count(tree) == 0, "%ld\n", btree_count(tree));
/*
			btree_display(tree, 1);
*/
		
			for (i=0; i<count; ++i) {
/*
				fprintf(stderr, "%d ", i);
				fflush(stderr);
*/
				assert(tree != NULL);
	
				if (i % 100 == 0 && debug_progress) {
					printf("\nAdding %ld (data[%d]):\n", data[i], i);
					fflush(stdout);
				}

				btree_add(tree, data[i], &pos);
				if (tree->parent != NULL)
					tree = tree->parent;
		
/*
				btree_print(tree);
				printf("\n\n");
*/
		
/*
				levels = btree_levels(tree);
				for (j=1; j<=levels; ++j) {
					btree_display(tree, j);
					printf("\n");
				}
				printf("\n");
*/
		
/*
				btree_display2(tree, 0);
				printf("bree_count(tree)=%d\n", btree_count(tree));
*/

				if (debug_count)
					assertf2(btree_count(tree) == i+1, "%ld != %d\n",
						btree_count(tree), i+1);
			}
		
/*
			btree_display2(tree, 0);
*/
			now = clock();
		
			printf("Inserting %d items in %d-order B-Tree: %.3g seconds",
				count, BTREE_ORDER, (double)(now-then)/CLOCKS_PER_SEC);

			assertf2(btree_count(tree) == count,
				"%ld != %d\n", btree_count(tree), count);

			then = clock();

			for (i=count-1; i>=0; --i) {
				BTREE *ptr;
				BTREE_POS pos;
				ptr = btree_find(tree, data[i], &pos);
				assert(ptr != NULL);
				assertf2(pos >= 0, "pos=%d, i=%d\n", pos, i);
				assertf2(pos < BTREE_ORDER, "pos=%d, i=%d\n", pos, i);

				if ((i % 100 == 0 && debug_progress)
					|| (i >= debug_i_start && i <= debug_i_end) )
				{
					printf("BEFORE DELETING %ld (data[%d])\n", data[i], i);
					if (i >= debug_i_start && i <= debug_i_end)
						btree_display2(tree,0);
				}

				btree_delete(ptr, pos);

				if (i >= debug_i_start && i <= debug_i_end) {
					printf("\nAFTER DELETING %ld\n", data[i]);
					btree_display2(tree,0);
					printf("\n");
				}

				if (debug_count)
					assertf(btree_count(tree) == i, "i=%d\n", i);

				/* shouldn't be able to find it again */
				ptr = btree_find(tree, data[i], &pos);
				assertf(pos == -1, "%d\n", pos);

				if (debug_slow) {
					/* verify that other entries are there */
					for(j=0; j<i; ++j) {
						BTREE *ptr = btree_find(tree, data[j], &pos);
						assertfn(pos >= 0,
							fprintf(stderr,
						 	"after deleting btree[%d]=%ld, btree[%d]=%ld missing\n",
						 	i, data[i], j, data[j]) );
					}
				}

			}

			now = clock();

/*
			printf("Deleting %d items in %d-order B-Tree: %.3g secs\n",
				count, BTREE_ORDER, (double)(now-then)/CLOCKS_PER_SEC);
*/
			printf(", Deleting: %.3g secs\n",
				(double)(now-then)/CLOCKS_PER_SEC);

			assertf(btree_count(tree) == 0, "%ld\n", btree_count(tree));

			btree_free(tree);
		}
    getchar();
	return 0;
}
