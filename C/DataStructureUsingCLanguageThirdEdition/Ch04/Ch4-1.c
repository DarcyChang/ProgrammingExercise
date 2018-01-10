/* 程式範例: Ch4-1.c */
#include <stdio.h>
#include <stdlib.h>
/* 主程式 */
int main() {  
   struct test { /* 宣告結構 */
      int math;
   }; /* 結構陣列指標變數宣告 */
   struct test *score, *ptr;
   float *ave;
   int i, num, sum, temp;
   printf("請輸入學生人數 ==> "); /* 讀取學生人數 */
   scanf("%d", &num);
   /* 配置成績陣列的記憶體 */
   score=(struct test *)malloc(num*sizeof(struct test));
   if ( score != NULL ) { /* 檢查指標 */
      sum = 0;   /* 讀取成績 */
      for ( i = 0; i < num; i++ ) {
         ptr = &score[i];  /* 指向結構的指標 */ 
         printf("請輸入第%d位的成績. ==> ", i+1);
         scanf("%d", &temp);
         ptr->math = temp; /* 指定數學成績 */ 
         sum += temp;
      } /* 配置浮點數的記憶體 */
      ave = (float *) malloc(sizeof(float));
      *ave = (float) sum / (float) num;  /* 計算平均 */
      printf("成績總分: %6d\n", sum);
      printf("平均成績: %6.2f\n", *ave);
      free(ave);  /* 釋回記憶體空間 */
      free(score);
   } else printf("成績結構陣列的記憶體配置失敗!\n");
   system("PAUSE");
   return 0; 
}
