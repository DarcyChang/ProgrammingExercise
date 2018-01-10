/* 程式範例: Ch2-3-2.c */
#include <stdio.h>
#include <stdlib.h>
#define NUM_STUDENTS       3    /* 學生人數 */ 
/* 主程式 */ 
int main() {
   struct test {                /* 宣告結構 */
      int math;
      int english;
      int computer;
   };
   /* 結構陣列變數宣告 */
   struct test students[NUM_STUDENTS];
   int i, c;
   /* 各科成績總分變數 */
   int m_sum = 0, e_sum = 0, c_sum = 0;
   /* 各科平均成績變數 */   
   float m_ave, e_ave, c_ave;
   /* 使用迴圈讀取學生成績 */
   for ( i = 0; i < NUM_STUDENTS; i++ ) {
      printf("學生編號: %d\n",i + 1);
      printf("請輸入數學成績. ==> ");
      scanf("%d", &students[i].math); /* 讀取數學成績 */
      m_sum += students[i].math;      /* 計算數學總分 */
      printf("請輸入英文成績. ==> ");
      scanf("%d",&students[i].english);/* 讀取英文成績 */
      e_sum += students[i].english;    /* 計算英文總分 */
      printf("請輸入電腦成績. ==> ");
      scanf("%d",&students[i].computer);/* 讀取電腦成績 */
      c_sum += students[i].computer;    /* 計算電腦總分 */
   }
   /* 計算平均成績 */ 
   m_ave = (float) m_sum / (float) NUM_STUDENTS;
   e_ave = (float) e_sum / (float) NUM_STUDENTS;
   c_ave = (float) c_sum / (float) NUM_STUDENTS;
   printf("數學平均成績: %6.2f \n", m_ave);
   printf("英文平均成績: %6.2f \n", e_ave);
   printf("電腦平均成績: %6.2f \n", c_ave);
   system("PAUSE");
   return 0; 
}
