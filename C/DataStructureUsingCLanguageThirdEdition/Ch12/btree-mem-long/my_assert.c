/*****************************************************************************
 * btree-mem-long/my_assert.c
 *
 * COPYRIGHT (c) 1995, 1997 by David Van Wagner ALL RIGHTS RESERVED
 * Source and executables may be distributed under the terms of the GNU
 * General Public License version 2, see the file COPYING for details.
 *
 * davevw@alumni.cse.ucsc.edu
 * http://alumni.cse.ucsc.edu/~davevw/
 *****************************************************************************/

#include "my_assert.h"

void assert_trap()
{
	/* do nothing, this allows debuggers to trap an assert before exiting */
}
