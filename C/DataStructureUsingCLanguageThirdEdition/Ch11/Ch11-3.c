/* 程式範例: Ch11-3.c */
#include <stdio.h>
#include <stdlib.h>
#include "createHeap.c"
/* 函數: 堆積排序法 */ 
void heapSort(int *heap, int len) {
   int i,j,temp;
   /*將二元樹轉成堆積*/
   for ( i = ( len / 2 ); i >= 1; i-- )
      shiftDown(heap, i, len);
   printf("\n堆積的內容: ");
   for ( j = 1; j < 10; j++ )     /* 顯示堆積 */
      printf("[%d]", heap[j]);   
   /* 堆積排序法的主迴圈 */ 
   for ( i = len - 1; i >= 1; i-- ) {
      temp = heap[i+1];           /* 交換最後元素 */
      heap[i+1] = heap[1];
      heap[1] = temp;
      shiftDown(heap, 1, i);      /* 重建堆積 */
      printf("\n重建的堆積: ");
      for ( j = 1; j < 10; j++ )  /* 顯示處理內容 */
         printf("[%d]", heap[j]);
   }
}
/* 主程式 */ 
int main() {
   /* 二元樹的節點資料 */
   int data[10] = { 0, 5, 6, 4, 8, 2, 3, 7, 1, 9 };
   int i;
   printf("二元樹內容: ");
   for ( i = 1; i < 10; i++ )     /* 顯示二元樹內容 */
      printf("[%d]", data[i]);
   heapSort(data, 9);             /* 堆積排序法 */
   printf("\n\n輸出排序結果: ");
   for ( i = 1; i < 10; i++ )     /* 顯示排序結果 */
      printf("[%d]", data[i]);
   printf("\n");
   system("PAUSE");
   return 0; 
}
