/* 程式範例: Ch5-4-2.c */
#include <stdio.h>
#include <stdlib.h>
int maze[7][10] = { /* 迷宮陣列,數字0可走, 1不可走 */
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 0, 1, 0, 1, 0, 0, 0, 0, 1,
        1, 0, 1, 0, 1, 0, 1, 1, 0, 1,
        1, 0, 1, 0, 1, 1, 1, 0, 0, 1,
        1, 0, 1, 0, 0, 0, 0, 0, 1, 1,
        1, 0, 0, 0, 1, 1, 1, 0, 0, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
/* 走迷宮的遞迴函數 */
int findPath(int x,int y) {
   if ( x == 1 && y == 1 ) {      /* 是否是迷宮出口 */
      maze[x][y] = 2;             /* 記錄最後走過的路 */
      return 1;
   }
   else if ( maze[x][y] == 0 ) {  /* 是不是可以走的路 */
          maze[x][y] = 2;         /* 記錄己經走過的路 */
          if ( ( findPath(x - 1,y) +       /* 往上 */
                 findPath(x + 1,y) +       /* 往下 */
                 findPath(x,y - 1) +       /* 往左 */
                 findPath(x,y + 1) ) > 0 ) /* 往右 */
              return 1;
          else {
              maze[x][y] = 0;    /* 此路不通取消記號 */
              return 0;
          }
        }
        else return 0;
}
/* 主程式: 使用遞迴函數在陣列走迷宮 */
int main() {
   int i,j;
   findPath(5,8);                   /* 呼叫遞迴函數 */
   printf("迷宮路徑圖(從右下角到左上角): \n");
   for ( i = 0; i <= 6; i++) {      /* 顯示迷宮圖形 */
      for ( j = 0; j <= 9; j++)
         printf("%d ", maze[i][j]); /* 顯示座標值 */
      printf("\n");
   }
   printf("\n數字 1: 牆壁\n數字 2: 走過的路徑\n");  
   system("PAUSE");
   return 0; 
}
