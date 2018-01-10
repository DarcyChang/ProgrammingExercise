/* 程式範例: Ch2-1-2.c */
#include <stdio.h>
#include <stdlib.h>
/* 主程式 */
int main() {
   /* 學生成績陣列 */
   int scores[10] = {76,85,90,67,59,79,82,95,91,65};
   int num;          /* 學號 */
   int grade;        /* 成績 */
   int i, choice;    /* 選項 */
   int doit = 1;
   /* 執行操作的主迴圈 */
   while ( doit ) {
      printf("----選單----\n"); 
      printf("1: 查詢成績\n");
      printf("2: 修改成績\n");
      printf("3: 顯示成績\n");
      printf("4: 離開作業\n");
      printf("請輸入選項( 1 到 4 ). ==> ");
      scanf("%d", &choice); 
      if (choice < 3 ) {
         printf("請輸入學生學號( 0 到 9). ==> ");
         scanf("%d", &num);  /* 讀入學號 */
      }
      switch( choice ) {
         case 1:  /* 查詢成績 */
            grade = scores[num];    /* 取得成績 */
            printf("學生成績: %d\n", grade);
            break;
         case 2:  /* 修改成績 */
            grade = scores[num];
            printf("原來學生成績: %d\n", grade);
            printf("輸入新成績. ==> ");/* 讀取新成績 */
            scanf("%d", &grade);
            scores[num] = grade;    /* 更新成績 */
            break;
         case 3:  /* 顯示成績 */
            printf("學生成績: \n");
            for ( i = 0; i < 10; i++ )
               printf("%d:%d ", i, scores[i]);
            printf("\n");
            break;
         case 4:  /* 結束作業 */
            doit = 0;
            break;
      }
   }   
   system("PAUSE");
   return 0; 
}
