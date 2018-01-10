/* 程式範例: Ch8-4-2.c */
#include <stdio.h>
#include <stdlib.h>
#include "Ch8-4-2.h"
/* 函數: 建立圖形的邊線串列 */ 
void createEdge(int len, int *edge) {
  EdgeList newnode;           /* 新邊線節點指標 */
  EdgeList last;              /* 最後邊線節點指標 */
  int i;
  for (i = 0; i < len; i++) { /* 建立邊線串列主迴圈 */
     /* 建立新邊線記憶體 */
     newnode = (EdgeList)malloc(sizeof(struct Edge));
     newnode->from = edge[3*i];  /* 邊線的起點 */
     newnode->to = edge[3*i+1];  /* 邊線的終點 */
     newnode->weight = edge[3*i+2]; /* 建立成本內容 */
     newnode->next = NULL;       /* 設定指標初值 */
     if ( first == NULL ) {      /* 串列的第一個節點 */
        first = newnode;         /* 建立串列開始指標 */
        last = first;            /* 保留最後節點指標 */
     } else {
        last->next = newnode;    /* 鏈結至最後節點 */
        last = newnode;          /* 保留最後節點指標 */
     }
  }
}
/* 函數: 新增到同一個集合 */ 
void addSet(int from, int to) {
   int to_root = to;             /* 從終點頂點找 */
   while ( vertice[to_root] > 0 )
      to_root = vertice[to_root];
   vertice[to_root] = from;      /* 結合兩個頂點 */
}
/* 函數: 兩個頂點是否是同一個集合, 擁有同一個根頂點 */ 
int isSameSet(int from, int to) {
   int from_root = from;         /* 從開始頂點找 */
   int to_root = to;             /* 從終點頂點找 */
   while ( vertice[from_root] > 0 ) /* 找尋根頂點 */ 
      from_root = vertice[from_root];
   while ( vertice[to_root] > 0 )   /* 找尋根頂點 */
      to_root = vertice[to_root];
   if ( from_root == to_root )   /* 是否是同一根頂點 */
         return 1;               /* 同一集合 */ 
   else  return 0;               /* 不同集合 */ 
}
/* 函數: 最低成本擴張樹 */ 
void minSpanTree() {
   EdgeList ptr = first;          /* 指向串列的開始 */
   int i, total = 0;
   for ( i=1; i < MAX_VERTICE;i++ )/* 初始頂點陣列 */
      vertice[i] = -1;
   while ( ptr != NULL ) {
      /* 是否是同一個集合, 相同會產生迴圈 */
      if ( !isSameSet(ptr->from,ptr->to) ) {
         /* 加入最低成本擴張樹的邊線 */
         printf("頂點 V%d -> V%d 成本: %d\n",ptr->from,
                  ptr->to,ptr->weight);
         total += ptr->weight;          /* 計算成本 */      
         addSet(ptr->from,ptr->to);     /* 新增至集合 */
      }
      ptr = ptr->next;           /* 下一條邊線 */
   }
   printf("最低成本擴張樹的成本: %d\n", total); 
}
/* 主程式 */
int main() {
   int edge[8][3] = { { 1, 2, 2 }, /* 成本邊線陣列 */
                      { 2, 4, 3 },
                      { 1, 4, 4 },
                      { 3, 5, 5 },
                      { 2, 5, 6 },
                      { 2, 3, 8 },
                      { 3, 4, 10 },
                      { 4, 5, 15 } };
   int i;
   createEdge(8, &edge[0][0]);  /* 建立邊線串列 */
   printf("圖形的最低成本擴張樹:\n");
   minSpanTree();               /* 建立最小成本擴張樹 */
   printf("頂點陣列內容: ");
   for ( i = 1; i < MAX_VERTICE; i++ )
      printf("[%d]", vertice[i]); /* 顯示頂點陣列 */
   printf("\n");
   system("PAUSE");
   return 0; 
}
