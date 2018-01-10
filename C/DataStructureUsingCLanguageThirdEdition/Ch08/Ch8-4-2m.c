/* 程式範例: Ch8-4-2m.c */
#include <stdio.h>
#include <stdlib.h>
#include "adjacencyMatrix.c"
/* 主程式 */
int main() {
   int edge[7][3] = { {1, 2,  2},  /* 加權邊線陣列 */
                      {1, 3,  5},
                      {2, 4, 16},
                      {3, 2,  6},
                      {4, 5,  9},
                      {5, 3, 10},
                      {6, 3, 20}};
   createGraph(7, &edge[0][0]);   /* 建立圖形 */
   printf("圖形G9的鄰接矩陣內容:\n");
   printGraph();  /* 顯示圖形 */
   system("PAUSE");
   return 0; 
}
