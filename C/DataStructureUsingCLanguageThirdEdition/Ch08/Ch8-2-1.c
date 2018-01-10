/* �{���d��: Ch8-2-1.c */
#include <stdio.h>
#include <stdlib.h>
#include "Ch8-2-1.h"
/* ���: �ϥ���u�}�C�إ߹ϧ� */ 
void createGraph(int len, int *edge) {
   int from, to;                 /* ��u���_�I�M���I */
   int i, j;
   for ( i = 1; i < MAX_VERTICES; i++ )
      for ( j = 1; j < MAX_VERTICES; j++ )
         graph[i][j] = 0;        /* �M���F���x�} */
   for ( i = 0; i < len; i++ ) { /* Ū����u���j�� */
      from = edge[i*2];          /* ��u���_�I */
      to = edge[i*2+1];          /* ��u�����I */
      graph[from][to] = 1;       /* �s�J�ϧΪ���u */
   }
}
/* ���: ��ܹϧ� */
void printGraph() {
   int i, j;
   /* �ϥΰj����ܹϧ� */
   for ( i = 1; i < MAX_VERTICES; i++ ) {
      for ( j = 1; j < MAX_VERTICES; j++ )
         printf(" %d ", graph[i][j]);
      printf("\n");
   }
}
/* �D�{�� */
int main() {
   int edge[12][2] = { {1, 2}, {2, 1},  /* ��u�}�C */
                       {1, 3}, {3, 1},
                       {2, 3}, {3, 2},
                       {2, 4}, {4, 2},
                       {3, 5}, {5, 3},
                       {4, 5}, {5, 4} };
   createGraph(12, &edge[0][0]);   /* �إ߹ϧ� */
   printf("�ϧ�G���F���x�}���e:\n");
   printGraph();  /* ��ܹϧ� */
   system("PAUSE");
   return 0; 
}
