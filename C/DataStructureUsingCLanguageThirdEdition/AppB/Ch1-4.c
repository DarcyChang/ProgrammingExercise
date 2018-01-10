/* 祘Α絛ㄒ: Ch1-4.c */
#include <stdio.h>
#include <stdlib.h>
#include "Ch1-4.h"
/* ㄧ计 */
static void maxvalue(void);
static void minvalue(void);
int var1, var2;
static int result;
/* ㄧ计: 程 */
static void maxvalue() {
   if ( var1 > var2 ) result = var1;
   else               result = var2;
}
/* ㄧ计: 程 */
static void minvalue() {
   if ( var1 < var2 ) result = var1;
   else               result = var2;
}
/* ㄧ计: 陪ボ俱计跑计ゑ耕挡狦 */
void cmpresult(int type) {
   printf("跑计1: %d\n", var1);
   printf("跑计2: %d\n", var2);
   if ( type == MAXCMP ) {
       maxvalue();
       printf("程: %d\n", result);
   } else {
       minvalue();
       printf("程 : %d\n", result);
   }
}
