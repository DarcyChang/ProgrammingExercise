/* 程式範例: Ch6-2-1.c */
#include <stdio.h>
#include <stdlib.h> 
#include "Ch6-2-1.h"
/* 函數: 檢查佇列是否是空的 */
int isQueueEmpty() {
   if ( front == rear ) return 1;
   else                 return 0;
}
/* 函數: 將資料存入佇列 */
int enqueue(int d) {
   if ( rear >= MAXQUEUE )  /* 是否超過佇列容量 */
     return 0;
   else {
      queue[++rear] = d;    /* 存入佇列 */
      return 1;
   }
}
/* 函數: 從佇列取出資料 */
int dequeue() {
   if ( isQueueEmpty() )   /* 佇列是否是空的 */
      return -1;
   else
      return queue[++front];/* 取出資料 */
}
/* 主程式 */
int main() {   
   /* 宣告變數 */
   int data[6] = {1, 2, 3, 4, 5, 6};
   int i;
   printf("存入佇列資料的順序: ");
   /* 使用迴圈將資料存入佇列 */
   for ( i = 0; i < 6; i++) {
      enqueue(data[i]);
      printf("[%d]", data[i]);
   }
   printf("\n取出佇列資料的順序: ");
   while ( !isQueueEmpty() )   /* 取出佇列資料 */
      printf("[%d]", dequeue()); 
   printf("\n");
   system("PAUSE");
   return 0; 
}
