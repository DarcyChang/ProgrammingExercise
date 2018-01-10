/* 程式範例: Ch2-3-3.c */
#include <stdio.h>
#include <stdlib.h>
/* 主程式 */ 
int main() {
   struct test {               /* 宣告結構 */
      int math;
      int english;
      int computer;
   };
   typedef struct test score;  /* 定義新型態 */
   score joe, jane;            /* 使用新型態變數宣告 */
   joe.math = 80;              /* 指定成員變數 */ 
   joe.english = 85;
   joe.computer = 83;
   jane.math = 78;             /* 指定成員變數 */ 
   jane.english = 65;
   jane.computer = 55;
   /* 顯示成績 */
   printf("姓名: Joe\n");
   printf("數學: %d\n", joe.math);
   printf("英文: %d\n", joe.english);
   printf("數學: %d\n", joe.computer);
   printf("=================\n");
   printf("姓名: Jane\n");
   printf("數學: %d\n", jane.math);
   printf("英文: %d\n", jane.english);
   printf("數學: %d\n", jane.computer);
   system("PAUSE");
   return 0;  
}
