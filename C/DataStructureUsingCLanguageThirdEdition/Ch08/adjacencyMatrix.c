/* 程式範例: adjacencyMatrix.c */
#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES   7            /* 最大頂點數加一 */
#define MAX           1000          /* 無窮大 */ 
int graph[MAX_VERTICES][MAX_VERTICES];/* 圖形陣列 */
/* 抽象資料型態的操作函數宣告 */
extern void createGraph(int len, int *edge);
extern void printGraph();
/* 函數: 使用邊線陣列建立圖形 */ 
void createGraph(int len, int *edge) {
   int from, to;                 /* 邊線的起點和終點 */
   int i, j;
   for ( i = 1; i < MAX_VERTICES; i++ )
      for ( j = 1; j < MAX_VERTICES; j++ )
         if ( i != j )
            graph[i][j] = MAX;   /* 矩陣設為無窮大 */
         else
            graph[i][j] = 0;     /* 對角線設為0 */    
   for ( i = 0; i < len; i++ ) { /* 讀取邊線的迴圈 */
      from = edge[i*3];          /* 邊線的起點 */
      to = edge[i*3+1];          /* 邊線的終點 */
      graph[from][to]=edge[i*3+2];/* 存入圖形的邊線 */
   }
}
/* 函數: 顯示圖形 */
void printGraph() {
   int i, j;
   /* 使用迴圈顯示圖形 */
   for ( i = 1; i < MAX_VERTICES; i++ ) {
      for ( j = 1; j < MAX_VERTICES; j++ )
         if ( graph[i][j] == MAX )
            printf("  ∞");
         else
            printf("%4d", graph[i][j]);
      printf("\n");
   }
}
