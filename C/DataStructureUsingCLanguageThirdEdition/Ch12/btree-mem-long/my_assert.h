/*****************************************************************************
 * btree-mem-long/my_assert.h
 *
 * COPYRIGHT (c) 1995, 1997 by David Van Wagner ALL RIGHTS RESERVED
 * Source and executables may be distributed under the terms of the GNU
 * General Public License version 2, see the file COPYING for details.
 *
 * davevw@alumni.cse.ucsc.edu
 * http://alumni.cse.ucsc.edu/~davevw/
 *****************************************************************************/

#ifndef MY_ASSERT_H
#define MY_ASSERT_H

#include <assert.h>

#ifndef NDEBUG

void assert_trap();

#undef assert
#define assert(cond) if (!(cond)) { fprintf(stderr,"%s:%d: assertion failed (%s)\n", __FILE__, __LINE__, #cond); assert_trap(); exit(1); }
#define assertf(cond,str,arg) if (!(cond)) { fprintf(stderr,"%s:%d: assertion failed (%s)\n", __FILE__, __LINE__, #cond); fprintf(stderr, str, arg); assert_trap(); exit(1); }
#define assertf2(cond,str,arg1,arg2) if (!(cond)) { fprintf(stderr,"%s:%d: assertion failed (%s)\n", __FILE__, __LINE__, #cond); fprintf(stderr, str, arg1, arg2); assert_trap(); exit(1); }
#define assertfn(cond,fn) if (!(cond)) { fprintf(stderr,"%s:%d: assertion failed (%s)\n", __FILE__, __LINE__, #cond); fn; assert_trap(); exit(1); }
#else /* ifndef NDEBUG */
#define assertf(cond,str,arg) ;
#define assertf2(cond,str,arg1,arg2) ;
#define assertfn(cond,fn) ;

#endif /* ifndef NDEBUG */

#endif /* MY_ASSERT_H */
