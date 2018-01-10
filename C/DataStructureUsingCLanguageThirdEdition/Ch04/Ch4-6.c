/* 程式範例: Ch4-6.c */
#include <stdio.h>
#include <stdlib.h>
#include "Ch4-6.h"
#include "createPoly.c"
/* 主程式 */
int main() {
   PList a = NULL;    /* 多項式串列1的開頭指標 */
   PList b = NULL;    /* 多項式串列2的開頭指標 */
   /* 建立多項式物件所需的陣列 */
   float list1[6] = { 4, 0, 3, 0, 7, 0 };
   float list2[6] = { 9, 7, 1, 0, 5, 6 };
   a = createPoly(6, list1);  /* 建立多項式串列1 */
   b = createPoly(6, list2);  /* 建立多項式串列2 */
   printPoly(a);     /* 顯示多項式1 */
   printPoly(b);     /* 顯示多項式2 */
   system("PAUSE");
   return 0; 
}
