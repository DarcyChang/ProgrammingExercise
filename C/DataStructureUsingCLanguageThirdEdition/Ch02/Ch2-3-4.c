/* 程式範例: Ch2-3-4.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
struct test {                 /* 考試成績的結構 */ 
   int math;
   int english;
   int computer;
};
struct student {              /* 學生資料的結構 */ 
   int id;
   char name[20];
   struct test score;         /* 結構變數 */ 
};
/* 主程式 */ 
int main() {
   /* 結構變數的宣告 */
   struct student std1;
   struct student std2 = {2, "江小魚", {45, 78, 66}};
   int total;
   std1.id = 1;               /* 指定結構變數的值 */ 
   strcpy(std1.name, "陳會安");
   std1.score.math = 78;
   std1.score.english = 65;
   std1.score.computer = 90;
   /* 顯示學生資料 */
   printf("學號: %d\n", std1.id);
   printf("姓名: %s\n", std1.name);
   total = std1.score.math + std1.score.english +
           std1.score.computer;
   printf("成績總分: %d\n", total);
   printf("--------------------\n"); 
   printf("學號: %d\n", std2.id);
   printf("姓名: %s\n", std2.name);
   total = std2.score.math + std2.score.english + 
           std2.score.computer;
   printf("成績總分: %d\n", total);
   system("PAUSE");
   return 0;  
}
