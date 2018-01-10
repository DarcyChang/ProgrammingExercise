/* 程式範例: Ch1-1a.c */
#include <stdio.h>
#include <stdlib.h>
/* 主程式 */
int main() {
   int t1,t2,t3,t4,t5;             /* 各次的成績 */
   int t6,t7,t8,t9,t10;
   int sum;                        /* 總分 */
   float average;                  /* 平均 */
   t1 = 81; t2 = 93; t3 = 77; t4 = 59; t5 = 69;
   t6 = 85; t7 = 90; t8 = 83; t9 = 100; t10 = 75;
   sum = t1 + t2 + t3 + t4 + t5 +
         t6 + t7 + t8 + t9 + t10;   /* 計算總分 */
   average = sum / 10;              /* 計算平均 */
   printf("總分: %d\n", sum);       /* 顯示總分 */
   printf("平均: %5.2f\n", average);/* 顯示平均 */
   system("PAUSE");
   return 0; 
}
