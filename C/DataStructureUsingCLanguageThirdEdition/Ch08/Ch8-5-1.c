/* 程式範例: Ch8-5-1.c */
#include <stdio.h>
#include <stdlib.h>
#include "adjacencyMatrix.c"
int dist[MAX_VERTICES];           /* 路徑長度陣列 */
int pi[MAX_VERTICES];             /* 前一頂點陣列 */
/* 函數: 找尋某一頂點至各頂點的最短距離 */ 
void shortestPath(int source, int num) {
   int selected[MAX_VERTICES];    /* 選擇的頂點陣列 */    
   int min_len;                   /* 最短距離 */
   int min_vertex = 1;            /* 最短距離的頂點 */
   int i,j;
   for ( i = 1; i <= num; i++ ) { /* 初始陣列迴圈 */
      selected[i] = 0;            /* 清除陣列內容 */
      pi[i] = 0;                  /* 清除陣列內容 */
      dist[i] = graph[source][i]; /* 初始距離 */
   }
   selected[source] = 1;          /* 開始頂點加入集合 */
   dist[source] = 0;              /* 設定開始頂點距離 */
   printf("V   1   2   3   4   5   6\n");
   for ( j = 1; j <= num; j++ ) { /* 顯示dist[]陣列內容 */
      if ( j == 1 ) printf("%d", source); /* 選擇頂點 */ 
      if ( dist[j] == MAX ) printf("  ∞");
      else printf("%4d", dist[j]);  /* 顯示距離 */
   }
   printf("\n");
   /* 一共執行頂點數-1次的迴圈 */ 
   for ( i = 1; i <= num-1; i++ ) {      
      min_len = MAX;              /* 先設為無窮大 */      
      /* 找出最短距離頂點的迴圈 */
      for ( j = 1; j <= num; j++ )
         /* 從不屬於集合的頂點陣列找尋最近距離頂點 s */
         if ( min_len > dist[j] && selected[j] == 0 ) {
            min_vertex = j;       /* 目前最短的頂點 */
            min_len = dist[j];    /* 記錄最短距離 */
         }
      selected[min_vertex] = 1;   /* 將頂點加入集合 */
      printf("%d", min_vertex);   /* 顯示選擇的的頂點 */
      if ( i == 1 ) pi[min_vertex] = 1;/* 前頂點 */
      /* 計算開始頂點到各頂點最短距離陣列的迴圈 */
      for ( j = 1; j <= num; j++ ) {
        if ( selected[j] == 0 &&  /* 是否距離比較短 */
        dist[min_vertex]+graph[min_vertex][j]<dist[j]) {
          /* 指定成較短的距離 */
          dist[j]=dist[min_vertex]+graph[min_vertex][j];
          pi[j] = min_vertex;     /* 記錄前一個頂點 */
        }       
        if ( dist[j] == MAX ) printf("  ∞");
        else printf("%4d", dist[j]);/* 顯示最短距離 */
      }
      printf("\n");
   }
   printf("前一頂點陣列: \n");  
   printf("V  1   2   3   4   5   6\n");
   for ( j = 1; j <= num; j++ ) { 
      printf("%4d", pi[j]);        /* 顯示前一個頂點 */ 
   }
   printf("\n");
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
   printf("從頂點1到各頂點最近距離的Dijkstra計算過程:\n");
   shortestPath(1,6);             /* 找尋最短路徑 */
   system("PAUSE");
   return 0; 
}
