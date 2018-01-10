/* 程式範例: Ch3-2-3.c */
#include <stdio.h>
#include <stdlib.h>
#define ROWS      4
/* 主程式 */
int main() {
   /* 宣告變數 */
   int i;
   int values[ROWS] = { 10, 4, 5, 19 };
   /* 建立int的指標陣列 */
   int *tables[ROWS];   
   /* 指定指標陣列的元素值 */ 
   for ( i=0; i < ROWS; i++)
      tables[i] = &values[i];  /* 取得陣列元素位址 */ 
   /* 顯示指標陣列的元素值 */
   for ( i=0; i < ROWS; i++ ) {
      printf("*tables[%d]=%2d ", i, *tables[i]);      
      printf("位址=%p\n", tables[i]);
   }
   system("PAUSE");
   return 0; 
}
