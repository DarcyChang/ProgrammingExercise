/* 程式範例: Ch2-2-3.c */
#include <stdio.h>
#include <stdlib.h>
#define ROW    6     /* 定義列數 */
#define COLUMN 5     /* 定義欄數 */
/* 主程式 */
int main() {
   /* 學生功課表, 使用課程代碼 */
   int data[25] = {0, 2, 0, 2, 0,
                   1, 4, 1, 4, 1,
                   5, 0, 5, 0, 5,
                   3, 0, 3, 0, 3,
                   0, 0, 0, 0, 0 };
   /* 指標陣列 */
   int pointer[6] = { 0, 10, 5, 20, 15, 20 };
   int sum = 0;   /* 上課總節數 */
   int i, j;
   for ( i = 0; i < 25; i++ )   /* 一維陣列的走訪 */
      printf("%d:%d ", i, data[i]); 
   printf("\n");
   for ( i = 0; i < ROW; i++ )    /* 二維陣列的走訪 */
      for ( j = 0; j < COLUMN; j++ )
         if ( data[pointer[i]+j] != 0 ) /* 是否有課 */
            sum++;
   /* 顯示上課總節數 */
   printf("上課總節數: %d\n", sum);
   system("PAUSE");
   return 0; 
}
