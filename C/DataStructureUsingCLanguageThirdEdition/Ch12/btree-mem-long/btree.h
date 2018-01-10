/*****************************************************************************
 * btree-mem-long/btree.h
 *
 * COPYRIGHT (c) 1995, 1997 by David Van Wagner ALL RIGHTS RESERVED
 * Source and executables may be distributed under the terms of the GNU
 * General Public License version 2, see the file COPYING for details.
 *
 * davevw@alumni.cse.ucsc.edu
 * http://alumni.cse.ucsc.edu/~davevw/
 *****************************************************************************/

#ifndef BTREE_H
#define BTREE_H

typedef unsigned long BTREE_STORED;
typedef signed long BTREE_KEY;
typedef signed char BTREE_POS;

#define BTREE_ORDER_MAX 31
extern BTREE_POS BTREE_ORDER;

typedef struct btree_struct {
	BTREE_STORED stored;	/* binary flags of which keys have values stored */
	BTREE_POS count;		/* number of keys which are valid */
	struct btree_struct *parent;
	struct btree_struct **ptr;
	BTREE_KEY *key;
} BTREE;

/******************************************************************************
 * B-tree elements are never deleted, just expired by turning off the stored  *
 * bit.  The count is decreased only when splitting a node.  For optimization *
 * the B-Tree may need to be copied to a new one?                             *
 ******************************************************************************/

BTREE *btree_new(void);
BTREE *btree_find(BTREE *node, BTREE_KEY num, BTREE_POS *pos);
BTREE *btree_add(BTREE *node, BTREE_KEY num, BTREE_POS *pos);
void btree_print(BTREE *node);
void btree_display(BTREE *node, int only_level);
long btree_count(BTREE *node);
int btree_levels(BTREE *node);
void btree_display2(BTREE *node, int level);
void btree_free(BTREE *node);
void btree_delete(BTREE *node, BTREE_POS pos);

/* value of bit turned on */
#define BTREE_BIT(bit) ((BTREE_STORED)1 << (bit))

/* value of bit number of parameter and lower are all set */
#define BTREE_BITMASK(bit) ( ( ( BTREE_BIT(bit)-1 ) << 1 ) + 1 )

/* value of bit numbers of parameters and between are all set */
#define BTREE_BITMASK_LOHI(bit1, bit2) ((bit1)==0 ? BTREE_BITMASK(bit2) \
	: (BTREE_BITMASK(bit2) ^ BTREE_BITMASK(bit1-1)))

/* check for bit set */
#define BTREE_POS_STORED(node, pos) ((node)->stored & BTREE_BIT(pos))

/* check for bit cleared */
#define BTREE_POS_CLEARED(node, pos) (!BTREE_POS_STORED((node), (pos)))

#endif
