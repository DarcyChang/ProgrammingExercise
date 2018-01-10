/* 程式範例: Ch1-6-2c.c */
#include <stdio.h>
#include <stdlib.h>
/* 函數: 顯示費氏數列 */
void fibonacci(int n) {
   int fn;                        /* F(n)變數 */
   int fn2;                       /* F(n-2)變數 */
   int fn1;                       /* F(n-1)變數 */
   int i;
   if ( n <= 1 )                  /* 項數是否小於1 */
      printf("F%d=[%d]\n", n, n); /* 顯示項目 */
   else {
      fn2 = 0;                    /* 設定 F(n-2) */
      fn1 = 1;                    /* 設定 F(n-1) */
      for ( i = 2; i <= n; i++ ) {/* 顯示數列的迴圈 */
         fn = fn2 + fn1;          /* 計算各一般項 */
         fn2 = fn1;               /* 重設 F(n-2) */
         fn1 = fn;                /* 重設 F(n-1) */
      }
      printf("F%d=[%d]\n", n, fn);/* 顯示項目 */
   }
}
/* 主程式 */
int main() {
   /* 變數宣告 */
   int n;
   printf("請輸入數列項數 ==> ");
   scanf("%d",&n);                /* 輸入項數 */
   fibonacci(n);                  /* 呼叫費氏數列函數 */ 
   system("PAUSE");
   return 0; 
}
