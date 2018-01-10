/* 程式範例: Ch11-4.c */
#include <stdio.h>
#include <stdlib.h> 
#include "createHeap.c"
/* 函數: 檢查優先佇列是否是空的 */
int isPriorityQueueEmpty() {
   if ( isHeapEmpty() ) return 1;
   else                 return 0;
}
/* 函數: 將資料存入優先佇列 */
void enqueue(int d) {
   insertHeap(d);        /* 存入優先佇列 */
}
/* 函數: 從優先佇列取出資料 */
int dequeue() {
   return removeHeap();  /* 取出資料 */
}
/* 主程式 */
int main() {   
   /* 宣告變數 */
   int data[6] = {6, 2, 3, 5, 4, 1};
   int i;
   printf("存入優先佇列資料的順序: ");
   /* 使用迴圈將資料存入佇列 */
   for ( i = 0; i < 6; i++ ) {
      enqueue(data[i]);
      printf("[%d]", data[i]);
   }
   printf("\n取出優先佇列資料的順序: ");
   while (!isPriorityQueueEmpty()) /* 取出佇列資料 */
      printf("[%d]", dequeue()); 
   printf("\n");
   system("PAUSE");
   return 0; 
}
