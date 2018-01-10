/* 程式範例: Ch8-5-2.c */
#include <stdio.h>
#include <stdlib.h>
#include "adjacencyMatrix.c"
int dist[MAX_VERTICES][MAX_VERTICES];/* 路徑長度陣列 */
/* 函數: 找尋各頂點到各頂點的最短距離 */ 
void shortestPath(int num) {
   int i, j, k;
   /* 初始陣列的巢狀迴圈 */
   for ( i = 1; i <= num; i++ )
      for ( j = i; j <= num; j++ )
         dist[i][j] = dist[j][i] = graph[i][j];         
   /* 找出最短距離的巢狀迴圈 */         
   for ( k = 1; k <= num; k++ )
      /* 走訪二維陣列計算最短路徑 */ 
      for ( i = 1; i <= num; i++ )
         for ( j = 1; j <= num; j++ )
            if ( dist[i][k] + dist[k][j] < dist[i][j] )
               /* 指定成為較短的距離 */
               dist[i][j] = dist[i][k] + dist[k][j];
   printf("V     1     2     3     4     5     6\n");
   for ( i = 1; i <= num; i++ ) {
      printf("%d ", i); 
      for ( j = 1; j <= num; j++ )
         printf(" %4d ", dist[i][j]); /* 顯示距離陣列 */
      printf("\n");
   } 
}
/* 主程式 */
int main() {
   int edge[7][3] = { {1, 2, 35},  /* 加權邊線陣列 */
                      {1, 3, 90},
                      {2, 3, 45},
                      {2, 4, 30},
                      {3, 5, 25},
                      {4, 5, 45},
                      {5, 6, 200} }; 
   createGraph(7, &edge[0][0]);   /* 建立圖形 */
   printf("圖形G的鄰接矩陣內容:\n");
   printGraph();  /* 顯示圖形 */
   printf("從各頂點到各頂點最近距離的Floyd計算過程:\n");
   shortestPath(6);               /* 找尋最短路徑 */   
   system("PAUSE");
   return 0; 
}
