/* 程式範例: Ch8-6.c */
#include <stdio.h>
#include <stdlib.h>
#include "queue.c"
#include "adjacencyList.c"
/* 函數: 圖形的拓樸排序 */ 
int topoSort(Graph head, int num) {
   Graph ptr;
   int i, vertex;
   /* 將內分支度為零頁的頂點存入佇列的迴圈 */
   for ( i = 1; i <= num; i++ )
      if ( head[i].data == 0 )  /* 如果分支度是零 */
         enqueue(i);            /* 將頂點存入佇列 */
   while ( !isQueueEmpty() ) {  /* 佇列是否已空 */
      vertex = dequeue();       /* 將頂點從佇列取出 */    
      printf(" %d ", vertex);   /* 顯示拓樸排序的頂點 */
      ptr = head[vertex].next;  /* 頂點指標 */
      while ( ptr != NULL ) {   /* 走訪至串列尾 */
         vertex = ptr->data;    /* 取得頂點值 */
         head[vertex].data--;   /* 頂點內分支度減一 */
         /* 如果內分支度是零 */
         if ( head[vertex].data == 0  )
            enqueue(vertex);    /* 將頂點存入佇列 */
         ptr = ptr->next;       /* 下一個頂點 */
      }
   }
   printf("\n");
   for ( i = 1; i <= num; i++ ) /* 檢查是否有迴圈 */
      if ( head[i].data != 0 )  /* 內分支度不是零 */
         return 1;              /* 有迴圈 */
   return 0;                    /* 沒有迴圈 */
}
/* 主程式 */
int main() {
   struct Vertex head1[MAX_VERTICES]; /* 頂點結構陣列 */
   struct Vertex head2[MAX_VERTICES]; /* 頂點結構陣列 */
   int edge[10][3] = { {3, 2, 1},     /* 邊線陣列 */
                       {2, 1, 1},
                       {2, 5, 1},
                       {2, 6, 1},
                       {1, 4, 1},
                       {5, 4, 1},
                       {7, 4, 1},
                       {6, 7, 1},
                       {5, 6, 1},
                       {7, 5, 1} };
   createGraph(head1,8,&edge[0][0]);  /* 建立圖形1 */
   printf("圖形1的鄰接串列內容================== \n");
   printGraph(head1);  /* 顯示圖形1 */
   printf("圖形1拓樸排序的內容:\n");
   if ( topoSort(head1, 7) )          /* 拓樸排序 */
      printf("圖形1有迴圈\n");
   else
      printf("圖形1沒有迴圈\n");
   front = rear = NULL;               /* 清除佇列 */
   createGraph(head2,10,&edge[0][0]); /* 建立圖形2 */
   printf("圖形2的鄰接串列內容================== \n");
   printGraph(head2);  /* 顯示圖形2 */
   printf("圖形2拓樸排序的內容:\n");
   if ( topoSort(head2, 7) )          /* 拓樸排序 */
      printf("圖形2有迴圈\n");
   else
      printf("圖形2沒有迴圈\n");
   system("PAUSE");
   return 0; 
}
