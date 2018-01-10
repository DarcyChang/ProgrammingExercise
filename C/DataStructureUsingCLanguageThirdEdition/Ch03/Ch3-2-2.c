/* 程式範例: Ch3-2-2.c */
#include <stdio.h>
#include <stdlib.h>
#define ROWS      4
#define COLS      5
/* 主程式 */
int main() {
   /* 宣告變數 */
   int i, j;
   /* 建立int的二維陣列 */
   int tables[ROWS][COLS];
   int *ptr;
   /* 指定二維陣列的元素值 */ 
   for ( i=0; i < ROWS; i++)
      for ( j=0; j < COLS; j++)
         tables[i][j] = (i+1)*(j+1);
   /* 顯示二維陣列的元素值 */ 
   ptr = &tables[0][0];
   for ( i=0; i < ROWS; i++) {
      for ( j=0; j < COLS; j++)
         printf("%d*%d=%2d ", (i+1), (j+1),
                            *(ptr+(i*COLS)+j));
      printf("\n");
   }
   printf("\n");
   system("PAUSE");
   return 0; 
}
