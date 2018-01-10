/* 程式範例: Ch1-5-2.c */
#include <stdio.h>
#include <stdlib.h>
/* 函數: 計算n!的值 */
long factorial(int n) {
   if ( n == 1 )                  /* 終止條件 */
      return 1;
   else
      return n * factorial(n-1);
}
/* 主程式 */
int main() {
   /* 變數宣告 */
   int no = 0;
   char c;
   while( no != -1 ) {
      printf("請輸入階層數(-1結束)==> ");
      scanf("%d", &no);
      if ( no > 0 )
         /* 函數的呼叫 */
         printf("%d!函數的值: %ld\n",no,factorial(no));
   }
   system("PAUSE");
   return 0; 
}
