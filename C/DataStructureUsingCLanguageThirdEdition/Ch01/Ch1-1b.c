/* 程式範例: Ch1-1b.c */
#include <stdio.h>
#include <stdlib.h>
/* 主程式 */
int main() {
   /* 儲存各次成績的陣列 */
   int t[10] = { 81,93,77,59,69,85,90,83,100,75 };
   int sum = 0;                    /* 總分 */
   float average;                  /* 平均 */
   int i;
   for ( i = 0; i < 10; i++ )
      sum += t[i];                  /* 計算總分 */
   average = sum / 10;              /* 計算平均 */
   printf("總分: %d\n", sum);       /* 顯示總分 */
   printf("平均: %5.2f\n", average);/* 顯示平均 */
   system("PAUSE");
   return 0; 
}
