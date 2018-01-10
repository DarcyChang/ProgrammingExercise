/* 程式範例: Ch2-1-4.c */ 
#include <stdio.h>
#include <stdlib.h>
/* 主程式 */
int main() {
   /* 學生功課表, 使用課程代碼 */
   int courses[6][5]={0, 2, 0, 2, 0,
                      1, 4, 1, 4, 1,
                      5, 0, 5, 0, 5,
                      0, 0, 0, 0, 0,
                      3, 0, 3, 0, 3,
                      0, 0, 0, 0, 0 };
   int sum = 0;   /* 上課總節數 */
   int i,j;
   for ( i = 0; i < 6; i++ )    /* 二維陣列的走訪 */
      for ( j = 0; j < 5; j++ )
         if ( courses[i][j] != 0 ) /* 是否有課 */
            sum++;
   /* 顯示上課總節數 */
   printf("上課總節數: %d\n", sum);
   system("PAUSE");
   return 0; 
}
