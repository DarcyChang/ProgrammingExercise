/* 程式範例: Ch8-4-2l.c */
#include <stdio.h>
#include <stdlib.h>
#include "adjacencyList.c"
/* 主程式 */
int main() {
   struct Vertex head[MAX_VERTICES]; /* 頂點結構陣列 */
   struct Vertex head1[MAX_VERTICES]; /* 頂點結構陣列 */
   int edge[9][3] = { {1, 2,  2},     /* 加權邊線陣列 */
                      {1, 3,  5},
                      {2, 4, 16},
                      {3, 2,  6},
                      {4, 5,  9},
                      {5, 3, 10},
                      {6, 3, 20},
                      {7, 2,  4},
                      {7, 5, 14}};
   createGraph(head, 7, &edge[0][0]);   /* 建立圖形 */
   printf("圖形G9的鄰接串列內容:\n");
   printGraph(head);  /* 顯示圖形 */
   createGraph(head1, 9, &edge[0][0]);  /* 建立圖形 */
   printf("圖形G9+2的鄰接串列內容:\n");
   printGraph(head1);  /* 顯示圖形 */
   system("PAUSE");
   return 0; 
}
