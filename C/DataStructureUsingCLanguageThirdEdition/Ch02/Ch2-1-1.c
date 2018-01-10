/* 程式範例: Ch2-1-1.c */ 
#include <stdio.h>
#include <stdlib.h>
/* 主程式 */
int main() {
   int sum = 0;  /* 總分 */
   /* 建立整數陣列 */
   int scores[5] = {56, 89, 75, 66, 98};
   printf("整數int記憶體大小: %d\n", sizeof(int));
   printf("scores[0]的位址: %p\n", &scores[0]);
   printf("scores[1]的位址: %p\n", &scores[1]);
   printf("scores[2]的位址: %p\n", &scores[2]);
   printf("scores[3]的位址: %p\n", &scores[3]);
   printf("scores[4]的位址: %p\n", &scores[4]); 
   /* 計算總分 */
   sum = scores[0] + scores[1] + \
         scores[2] + scores[3] + \
         scores[4];
   printf("成績總分: %d\n", sum);   
   system("PAUSE");
   return 0; 
}
