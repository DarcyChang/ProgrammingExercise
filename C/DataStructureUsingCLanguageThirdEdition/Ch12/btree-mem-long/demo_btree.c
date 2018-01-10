/*****************************************************************************
 * btree-mem-long/demo_btree.c
 *
 * COPYRIGHT (c) 1995, 1997 by David Van Wagner ALL RIGHTS RESERVED
 * Source and executables may be distributed under the terms of the GNU
 * General Public License version 2, see the file COPYING for details.
 *
 * davevw@alumni.cse.ucsc.edu
 * http://alumni.cse.ucsc.edu/~davevw/
 *****************************************************************************/

#include <stdio.h>
#include "btree.h"

BTREE *tree;

void menu_display()
{
	printf("a=add, d=delete, e=empty, f=find, m=menu, p=print, q=quit\n");
}

void menu_response(char *c, long *n)
{
	char s[1024];

	printf("> ");
	fflush(stdout);
	*n = 0;
	if (fgets(s, sizeof(s), stdin) == NULL)
		*c = 'q';
	else {
		*c = *s;
		if (strlen(s) > 1)
			*n = atol(s+1);
	}
}

void menu_do(char c, BTREE_KEY n)
{
	BTREE_POS pos;
	BTREE *node;

	switch (c) {
		case 'a':
			node = btree_add(tree, n, &pos);
			printf("added at %lX, index %d\n", (long unsigned)node, pos);
			while (tree->parent != NULL)
				tree = tree->parent;
			break;
		case 'c':
			printf("count of elements in tree = %ld\n", btree_count(tree));
			break;
		case 'd':
			node = btree_find(tree, n, &pos);
			if (pos == -1)
				printf("%ld not found\n", n);
			else
				btree_delete(node, pos);
			break;
		case 'e':
			btree_free(tree);
			if (n > 2 && n%2 == 1)
				BTREE_ORDER = n;
			tree = btree_new();
			break;
		case 'f':
			node = btree_find(tree, n, &pos);
			if (pos == -1)
				printf("%ld not found\n", n);
			else
				printf("found at %lX, index %d\n", (long unsigned)node, pos);
			break;
		case 'p':
			btree_display2(tree, 0);
			break;
		case 'm':
		default:
			menu_display();
			break;
	}
}

int main(int argc, char *argv[])
{
	char c;
	BTREE_KEY n;

	BTREE_ORDER = 5;
	tree = btree_new();

	printf("demo_btree\n");
	menu_display();
	do {
		menu_response(&c, &n);
		if (c != 'q')
			menu_do(c, n);
	} while (c != 'q');
	return 0;
}
