/* �{���d��: adjacencyMatrix.c */
#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES   7            /* �̤j���I�ƥ[�@ */
#define MAX           1000          /* �L�a�j */ 
int graph[MAX_VERTICES][MAX_VERTICES];/* �ϧΰ}�C */
/* ��H��ƫ��A���ާ@��ƫŧi */
extern void createGraph(int len, int *edge);
extern void printGraph();
/* ���: �ϥ���u�}�C�إ߹ϧ� */ 
void createGraph(int len, int *edge) {
   int from, to;                 /* ��u���_�I�M���I */
   int i, j;
   for ( i = 1; i < MAX_VERTICES; i++ )
      for ( j = 1; j < MAX_VERTICES; j++ )
         if ( i != j )
            graph[i][j] = MAX;   /* �x�}�]���L�a�j */
         else
            graph[i][j] = 0;     /* �﨤�u�]��0 */    
   for ( i = 0; i < len; i++ ) { /* Ū����u���j�� */
      from = edge[i*3];          /* ��u���_�I */
      to = edge[i*3+1];          /* ��u�����I */
      graph[from][to]=edge[i*3+2];/* �s�J�ϧΪ���u */
   }
}
/* ���: ��ܹϧ� */
void printGraph() {
   int i, j;
   /* �ϥΰj����ܹϧ� */
   for ( i = 1; i < MAX_VERTICES; i++ ) {
      for ( j = 1; j < MAX_VERTICES; j++ )
         if ( graph[i][j] == MAX )
            printf("  ��");
         else
            printf("%4d", graph[i][j]);
      printf("\n");
   }
}
