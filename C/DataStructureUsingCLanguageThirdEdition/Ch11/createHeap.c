/* 程式範例: createHeap.c */
#include <stdio.h>
#include <stdlib.h>
#define MAX_HEAP  100
int heap[MAX_HEAP];     /* 堆積的陣列 */
int heap_len  = 0;      /* 堆積目前的元素數 */
/* 函數: 檢查堆積是否是空的 */ 
int isHeapEmpty() {
   if ( heap_len > 0 ) return 0;
   else                return 1;
}
/* 函數: 向上調整堆積 */ 
void shiftUp(int *heap, int pos) {
   int temp;
   /* 調整堆積的主迴圈 */
   while ( pos > 1 ) {            /* 是否需要調整 */
      if ( heap[pos] <= heap[pos/2] )
         break;                   /* 結束 */
      else { /* 交換父子節點的資料 */
         temp = heap[pos];
         heap[pos] = heap[pos/2];
         heap[pos/2] = temp;
      }
      pos /= 2;                   /* 移至父節點 */
   }
}
/* 函數: 插入堆積元素 */ 
void insertHeap(int data) {
   heap_len++;                    /* 元素加一 */
   heap[heap_len] = data;         /* 存入堆積 */
   shiftUp(heap, heap_len);       /* 重建堆積 */
}
/* 函數: 向下調整堆積 */ 
void shiftDown(int *heap, int pos, int len) {
   int j, temp;
   j = 2 * pos;                   /* 左子節點索引 */
   temp = heap[pos];              /* 堆積調整的節點值 */
   while ( j <= len ) {           /* 主迴圈 */
      if ( j < len &&             /* 找最大子節點 */
             heap[j] < heap[j+1] )
            j++;                  /* 右子節點 */
         if ( temp >= heap[j] )   /* 比較樹的根節點 */
            break;                /* 結束 */
         else {
            heap[j/2] = heap[j];  /* 交換父子節點 */
            j = 2 * j;            /* 繼續調整其子節點 */
         }
   }
   heap[j/2] = temp;              /* 父節點為調整的節點值 */
}
/* 函數: 刪除堆積元素 */ 
int removeHeap() {      
   int temp = -1;
   if ( !isHeapEmpty() ) {        /* 堆積不是空的 */
      temp = heap[1];             /* 取得最大的根節點 */
      heap[1] = heap[heap_len];   /* 和最後一筆交換 */
      heap_len--;                 /* 長度減一 */
      shiftDown(heap, 1,heap_len);/* 重建堆積 */
   }
   return temp;                   /* 傳回刪除節點內容 */
}
/* 函數: 顯示堆積元素 */ 
void printHeap() {
   int i;   
   printf("堆積的內容: ");
   for (i = 1; i <= heap_len; i++)/* 顯示內容 */
         printf("[%d]", heap[i]);
   printf("\n");
}
