/* 程式範例: ChA-1.c */
#include <stdio.h>
#include <stdlib.h>
int total;                    /* 全域變數的宣告 */ 
/* 函數: 傳回1加到n */
int one2N(int n) {
   int i, total = 0;          /* 區域變數的宣告 */
   for ( i = 1; i <= n; i++ ) total+=i; /* 迴圈敘述 */
   return total;
}
/* 主程式 */
int main() {
   total = one2N(10);         /* 呼叫函數計算1加到10 */
   printf("從1到10的總和: %d\n", total);
   system("PAUSE");
   return 0; 
}
