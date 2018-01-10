/* 程式範例: Ch3-4-2.c */
#include <stdio.h>
#include <stdlib.h>
#define ROWS      4
#define COLUMNS  10
/* 主程式 */
int main() {
   /* 宣告變數 */
   int i, j;
   /* 建立二維的字元陣列且指定初值 */
   char names[ROWS][COLUMNS] = { "陳會安", "江小魚",
                                 "張無忌", "楊過" };
   /* 指標陣列 */ 
   char *name[ROWS] = { "陳會安", "江小魚",
                        "張無忌", "楊過" };
   char *ptr;
   /* 顯示二維陣列的元素值 */
   printf("顯示二維字元陣列的內容: \n"); 
   for ( i = 0; i < ROWS; i++ ) {
      printf("names[%d]=[", i);
      ptr = names[i]; 
      for ( j = 0; j < COLUMNS; j++)
         printf("%c", *(ptr+j));
      printf("]\n");
   }
   /* 顯示指標陣列的元素值 */
   printf("顯示指標陣列的內容: \n");
   for ( i = 0; i < ROWS; i++ ) {
      printf("name[%d] =[", i);
      ptr = name[i];  /* 取得每一個指標 */ 
      for ( j = 0; *(ptr+j) != '\0'; j++)
         printf("%c", *(ptr+j));
      printf("]\n");
   }
   system("PAUSE");
   return 0; 
}
