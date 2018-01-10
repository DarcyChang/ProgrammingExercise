/* 程式範例: Ch5-2-1.c */
#include <stdio.h>
#include <stdlib.h>
#include "Ch5-2-1.h"
/* 函數: 檢查堆疊是否是空的 */
int isStackEmpty() {
   if ( top == -1 ) return 1;
   else             return 0;
}
/* 函數: 將資料存入堆疊 */
int push(int d) {
   if ( top >= MAXSTACK ) { /* 是否超過堆疊容量 */
      printf("堆疊內容全滿\n");
      return 0;
   }   
   else {
      stack[++top] = d;    /* 存入堆疊 */
      return 1;
   }
}
/* 函數: 從堆疊取出資料 */
int pop() {
   if ( isStackEmpty() )   /* 堆疊是否是空的 */
      return -1;
   else 
      return stack[top--]; /* 取出資料 */
}
/* 主程式 */
int main() {   
   /* 宣告變數 */
   int data[6] = {1, 2, 3, 4, 5, 6};
   int i;
   printf("存入堆疊資料的順序: ");
   /* 使用迴圈將資料存入堆疊 */
   for ( i = 0; i < 6; i++) {
      push(data[i]);
      printf("[%d]", data[i]);
   }
   printf("\n取出堆疊資料的順序: ");
   while ( !isStackEmpty() )   /* 取出堆疊資料 */
      printf("[%d]", pop()); 
   printf("\n");
   system("PAUSE");
   return 0; 
}
