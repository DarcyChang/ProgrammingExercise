/*****************************************************************************
 * btree-mem-long/btree.c
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

/* MUST BE ODD, greater than 1, less than 32 */
BTREE_POS BTREE_ORDER;

/******************************************************************************
 * btree_new()                                                                *
 *                                                                            *
 * INPUTS:	global BTREE_ORDER                                                *
 * OUTPUTS:	warning errors to stderr                                          *
 * RETURNS:	pointer to newly allocated B-Tree node							  *
 *				with allocated and initialized ptr and key members			  *
 ******************************************************************************/
BTREE *btree_new()
{
	BTREE *new = (BTREE *)malloc(sizeof(BTREE));
	if (new == NULL)
		fprintf(stderr, "btree_new() failed\n");
	else {
		memset(new, 0, sizeof(*new));
		new->ptr = (BTREE **)malloc(sizeof(BTREE *)*BTREE_ORDER);
		if (new->ptr == NULL) {
			free(new);
			new = NULL;
		} else {
			memset(new->ptr, 0, sizeof(BTREE *)*BTREE_ORDER);
			new->key = (BTREE_KEY *)malloc(sizeof(BTREE_KEY)*(BTREE_ORDER-1));
			if (new->key == NULL) {
				free(new->ptr);
				free(new);
				new = NULL;
			} else
				memset(new->key, 0, sizeof(BTREE_KEY)*(BTREE_ORDER-1));
		}
	}
	return new;
}

/******************************************************************************
 * btree_find
 * INPUTS:	root of B-Tree to be searched
 *			key value to search for (or find insertion point)
 *			pointer to int for returning position
 * OUTPUTS:	modifies contents of pos pointer to int to position of matched key
 *			(-1 if not found, 0 based into key array)
 * RETURNS:	BTREE node of leaf where num is found or should be inserted  
 ******************************************************************************/
BTREE *btree_find(BTREE *node, BTREE_KEY num, BTREE_POS *pos)
{
	BTREE_POS i;
	BTREE *prev=NULL;

	*pos = -1;

	assert(node != NULL);

	while (node != NULL) {
		prev = node;
		for (i=0; i < node->count; ++i) {
			if (num < node->key[i]) {
				node = node->ptr[i];
				break;
			} else if (num == node->key[i]) {
				if (BTREE_POS_STORED(node, i))
					*pos = i;
				node = NULL;
				break;
			}
		}
		if (node == prev && i == node->count)
			node = node->ptr[i];
	}

	return prev;
}

/******************************************************************************
 * btree_add_internal()
 *
 * INPUTS:	root of B-Tree to add to
 *			split left & right trees of node (for recursive use only,
 *				should be NULL by normal callers)
 *			key value to add
 *			pointer to int for returning position where added
 * OUTPUTS:	modifies contents of B-Tree, assertion errors to stderr
 *          modifies contents of pos pointer to int to added position
 *			(-1 for failure, 0 based into key array)
 * RETURNS:	pointer to node where added
 *
 * NOTE:	currently never returns -1 as failed assert() will terminate program
 *			and _not_ return
 ******************************************************************************/
static BTREE *btree_add_internal(BTREE *node, BTREE *left, BTREE *right,
	BTREE_KEY num, BTREE_POS *pos)
{
	assert(node != NULL);

	/* verify parameters */
	assert((left==NULL && right==NULL) || (left!=NULL && right!=NULL));

	/* find num and position, or simply node where it should be inserted */
	node = btree_find(node, num, pos);

	if (*pos >= 0)
		return node;	/* don't add again */
	else if (node == NULL) 
		return (BTREE *)NULL;	/* failed */
	else {
		BTREE_POS i, j;

		for (i=0; i < node->count && num >= node->key[i]; ++i)
			if (node->key[i] == num)
				*pos = i;

		if (*pos >= 0) {
			/* WAS PREVIOUSLY STORED, JUST MARKED STORED AGAIN... */
			node->stored = node->stored | BTREE_BIT(*pos);
		} else if (node->count < BTREE_ORDER-1) {
			/* fits, so insert it... */
			for (i=0; i < node->count && num > node->key[i]; ++i)
				;
			if (node->count-1 >= i) {
				for (j=node->count-1; j>=i; --j) {
					/* move right pointer and key to right */
					node->ptr[j+2] = node->ptr[j+1];
					node->key[j+1] = node->key[j];
				}
				/* move last right pointer to right */
				node->ptr[j+2] = node->ptr[j+1];
			}

			/* INSERT BIT i INTO node->stored */
			node->stored = ((i==0)?0:(node->stored & BTREE_BITMASK(i-1)))
				| ((node->stored & BTREE_BITMASK_LOHI(i, node->count-1)) << 1)
				| BTREE_BIT(i);
			node->key[i] = num;
			*pos = i;
			++node->count;

			if (left != NULL) {
				assert(right != NULL);
				/* both left and right not NULL */
				node->ptr[*pos] = left;
				left->parent = node;
				node->ptr[(*pos)+1] = right;
				right->parent = node;
			}
		} else {
			/* no room, split and insert into parent */
			/* note: node is full, don't need to look at count anymore... */
			BTREE *new = btree_new();
			BTREE *ptr = NULL;
			BTREE *added;
			BTREE_POS temp_pos;
			BTREE_KEY temp_num;

			if (new == NULL)
				return (BTREE *)NULL;

			/* assume has same parent, if it splits will fix itself */
			new->parent = node->parent;

			/* doesn't fit, split into two nodes, right first */
			new->count = BTREE_ORDER/2;

			/* figure out where num would be inserted if there was room */
			/* so can figure out stored bit mask */
			for (i=0; i < BTREE_ORDER-1 && num > node->key[i]; ++i)
				;
			/* INSERT BIT i INTO node->stored, will be BTREE_ORDER # of bits! */
			node->stored = ((i==0)?0:(node->stored & BTREE_BITMASK(i-1)))
				| ((node->stored & BTREE_BITMASK_LOHI(i, node->count-1)) << 1)
				| BTREE_BIT(i);

			/* new will have right portion of node */
			/* (most significant bits of stored) */
			new->stored = (node->stored
				& BTREE_BITMASK_LOHI(BTREE_ORDER/2+1, BTREE_ORDER-1))
				>> (BTREE_ORDER/2+1);

			/* copy to right node highest to lowest */
			for (j=BTREE_ORDER/2-1; j>=0; --j) {
				if (num > node->key[j+BTREE_ORDER/2]) {
					new->key[j] = num;
					num = node->key[j+BTREE_ORDER/2];
					if (*pos < 0) {
						ptr = new;
						*pos = j;
					}
				} else
					new->key[j] = node->key[j+BTREE_ORDER/2];

				if (*pos >= 0) {
					if (j < BTREE_ORDER/2-1)
						new->ptr[j+1] = node->ptr[j+2+BTREE_ORDER/2];
				} else
					new->ptr[j+1] = node->ptr[j+1+BTREE_ORDER/2];
			}
			if (*pos >= 0)
				new->ptr[0] = node->ptr[BTREE_ORDER/2+1];
			else
				new->ptr[0] = node->ptr[BTREE_ORDER/2];

			/* RESET CHILDREN OF NEW TO POINT TO NEW PARENT */
			for (j=0; j<=BTREE_ORDER/2; ++j) {
				if (new->ptr[j] != NULL)
					new->ptr[j]->parent = new;
			}

			/* now split left */
			node->count = BTREE_ORDER/2;
			for (j=0; j<BTREE_ORDER/2; ++j) {
				if (num < node->key[j]) {
					temp_num = num;
					num = node->key[j];
					node->key[j] = temp_num;
					if (*pos < 0) {
						ptr = node;
						*pos = j;
					}
				}
			}
			/* wipe out pointers moved to the new node */
			for (j=BTREE_ORDER/2+1; j<BTREE_ORDER; ++j)
				node->ptr[j] = NULL;
			/* if num inserted in left, shift pointers over */
			if (ptr == node)
				for (j=BTREE_ORDER/2; j > *pos+1; --j)
					node->ptr[j] = node->ptr[j-1];

			/* add to parent, create parent if necessary */
			if (node->parent == NULL)
				node->parent = btree_new();
			else {
				/* NULL terminate the parent's pointer to this node */
				for (i=0; i <= node->parent->count; ++i) {
					if (node->parent->ptr[i] == node) {
						node->parent->ptr[i] = NULL;
						break;
					}
				}
				assertf(i <= node->parent->count, "%d\n", i);
			}

			assert(node->parent != NULL);

			/* insert the median and the split nodes into the parent node */
			if (ptr == NULL) {
				added = btree_add_internal(node->parent, node, new, num,
					&temp_pos);
				*pos = temp_pos;
			} else
				added = btree_add_internal(node->parent, node, new, num,
					&temp_pos);

			assert(added->key[temp_pos] == num);
			assert(BTREE_POS_STORED(added, temp_pos));

			/* if median value was deleted, re-mark as deleted */
			if (BTREE_POS_CLEARED(node, BTREE_ORDER/2))
				added->stored = added->stored ^ BTREE_BIT(temp_pos);
			node->stored = node->stored & BTREE_BITMASK(BTREE_ORDER/2-1);

			if (left != NULL) {
				if (ptr == NULL) {
					node->ptr[BTREE_ORDER/2] = left;
					assert(left->parent == node);
					new->ptr[0] = right;
					right->parent = new;
					node = added;
				} else {
					/* both left and right not NULL */
					assert(right != NULL);
					ptr->ptr[*pos] = left;
					ptr->ptr[(*pos)+1] = right;
					left->parent = ptr;
					right->parent = ptr;
					node = ptr;
				}
			}
		}

		return node;
	}
}

/******************************************************************************
 * btree_add()
 *
 * INPUTS:	root of B-Tree to add to
 *			key value to add
 *			pointer to int for returning position where added
 * OUTPUTS:	modifies contents of B-Tree, assertion errors to stderr
 *          modifies contents of pos pointer to int to added position
 *			(-1 for failure, 0 based into key array)
 * RETURNS:	pointer to node where added
 *
 * NOTE:	currently never returns -1 as failed assert() will terminate program
 *			and _not_ return
 ******************************************************************************/
BTREE *btree_add(BTREE *node, BTREE_KEY num, BTREE_POS *pos)
{
	return btree_add_internal(node, (BTREE *)NULL, (BTREE *)NULL, num, pos);
}

/*****************************************************************************
 * btree_delete()	-	delete specified node
 *
 * INPUTS:	pointer to node containing key to delete
 *			position of key to delete
 * OUTPUTS:	modifies contents of B-Tree to mark key not stored
 * RETURNS:	nothing
 *****************************************************************************/
void btree_delete(BTREE *node, BTREE_POS pos)
{
	assert(node != NULL);
	assertf(pos >= 0 && pos < BTREE_ORDER, "%d\n", pos);
	assertf(node->count > 0 && node->count < BTREE_ORDER, "%d\n", node->count);
	assertf2(pos == 0 || node->count != 1, "pos=%d, node->count=%d\n",
		pos, node->count);
	assert(BTREE_POS_STORED(node, pos));

	/* turning the bit on allows us to guarantee that we are turning it off */
	node->stored = (node->stored | BTREE_BIT(pos)) ^ BTREE_BIT(pos);
}

/*****************************************************************************
 * btree_print() - output contents of B-Tree to stdout on one line
 *****************************************************************************/
void btree_print(BTREE *node)
{
	BTREE_POS i;

	if (node == NULL || node->count == 0) {
		printf("EMPTY\n");
		return;
	}

	for (i=0; i < node->count; ++i) {
		if (node->ptr[i] != NULL) {
			fflush(stdout);
			assert(node->ptr[i]->parent == node);
			btree_print(node->ptr[i]);
		}
		printf("%ld ", node->key[i]);
	}
	if (node->ptr[i] != NULL) {
		fflush(stdout);
		assert(node->ptr[i]->parent == node);
		btree_print(node->ptr[i]);
	}
}

/*****************************************************************************
 * btree_levels()	-	count levels of the B-Tree
 *****************************************************************************/
int btree_levels(BTREE *node)
{
	BTREE_POS i;
	int levels;
	int max=1;

	if (node == NULL)
		return 0;
	for (i=0; i <= node->count; ++i) {
		levels = 1 + btree_levels(node->ptr[i]);
		if (levels > max)
			max = levels;
	}
	return max;
}

/*****************************************************************************
 * btree_count()	-	count members of the B-Tree
 *****************************************************************************/
long btree_count(BTREE *node)
{
	BTREE_POS i;
	long count=0;

	if (node == NULL)
		return 0;

	for (i=0; i <= node->count; ++i) {
		if (BTREE_POS_STORED(node, i))
			++count;
		count += btree_count(node->ptr[i]);
	}

	return count;
}

/*****************************************************************************
 * btree_display() - output contents of B-Tree to stdout showing hierarchy
 *						horizontally.  Recommended only for very small B-Trees
 *****************************************************************************/
void btree_display(BTREE *node, int only_level)
{
	BTREE_POS i;
	int level=1;
	char s[12];

	if (node == NULL || node->count == 0) {
		printf("EMPTY\n");
		return;
	}

	for (i=0; i < node->count; ++i) {
		if (node->ptr[i] != NULL) {
			assert(node->ptr[i]->parent == node);
			btree_display(node->ptr[i], only_level-1);
		}
		sprintf(s, "%ld ", node->key[i]);
		if (level != only_level)
			memset(s, ' ', strlen(s));
		printf("%s", s);
	}
	if (node->ptr[i] != NULL) {
		fflush(stdout);
		assert(node->ptr[i]->parent == node);
		btree_display(node->ptr[i], only_level-1);
	}
}

/*****************************************************************************
 * btree_display2() - output contents of B-Tree to stdout showing hierarchy
 *						vertically, easier to read display for large B-Trees
 *****************************************************************************/
void btree_display2(BTREE *node, int level)
{
	BTREE_POS i, j;

	if (node == NULL || node->count == 0) {
		printf("EMPTY\n");
		return;
	}

	for (i=0; i < node->count; ++i) {
		if (node->ptr[i] != NULL) {
			fflush(stdout);
			assert(node->ptr[i]->parent == node);
			btree_display2(node->ptr[i], level+1);
		}
		for (j=0; j<level*6; ++j)
			printf(" ");
		printf("%5ld%c\n", node->key[i],
			BTREE_POS_STORED(node, i) ? ' ' : '*');
	}
	if (node->ptr[i] != NULL) {
		fflush(stdout);
		assert(node->ptr[i]->parent == node);
		btree_display2(node->ptr[i], level+1);
	}
}

/*****************************************************************************
 * btree_free()	-	free all memory allocated for the B-Tree
 *****************************************************************************/
void btree_free(BTREE *node)
{
	BTREE_POS i;

	if (node == NULL || node->ptr == NULL)
		return;
	
	for (i=0; i <= node->count; ++i)
		btree_free(node->ptr[i]);

	free(node->ptr);
	free(node->key);
	free(node);
}

/*****************************************************************************
 * btree_check()	-	check consistency of B-Tree while traversing it
 *						halts program if error found
 *****************************************************************************/
void btree_check(BTREE *node)
{
	BTREE_POS i, count;

	if (node == NULL || node->count == 0)
		return;

	assert(node->count > 0 && node->count < BTREE_ORDER);

	for (i=count=0; i <= node->count; ++i) {
		if (i < node->count && BTREE_POS_STORED(node, i))
			++count;
		if (node->ptr[i] != NULL) {
			assert(node->ptr[i]->parent == node);
			btree_check(node->ptr[i]);
		}
	}

	assertf2(node->count == count, "node->count=%d, count=%d\n", node->count,
		count);

	assertf2(node->stored != 0 || node->count == 0,
		"node->stored=%lX, node->count=%d\n", node->stored, node->count);
}
