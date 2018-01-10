###############################################################################
# btree-mem-long/Makefile
#
# COPYRIGHT (c) 1995, 1997 by David Van Wagner ALL RIGHTS RESERVED
# Source and executables may be distributed under the terms of the GNU
# General Public License version 2, see the file COPYING for details.
#
# davevw@alumni.cse.ucsc.edu
# http://alumni.cse.ucsc.edu/~davevw/
###############################################################################

.PHONY: tags all progs restart
#CFLAGS=-O3 -m486 -DNDEBUG
#CFLAGS=-O3 -g
CC=gcc
CFLAGS=-DSUN -O
#CFLAGS=-O3 -DNDEBUG -g
#CFLAGS=-g -pg
#CFLAGS=-g
PROGS=test_btree random demo_btree
all: $(PROGS)
demo_btree: btree.o demo_btree.o my_assert.o
	$(CC) $(CFLAGS) -o $@ btree.o demo_btree.o my_assert.o
test_btree: btree.o test_btree.o my_assert.o
	$(CC) $(CFLAGS) -o $@ btree.o test_btree.o my_assert.o
random: random.o my_assert.o
	$(CC) $(CFLAGS) -o $@ random.o my_assert.o
tags:
	ctags btree.c random.c test_btree.c
clean:
	rm ttt* $(PROGS) *.o tags .depend 2>/dev/null || true
