/* �{���d��: Ch8-5-1.c */
#include <stdio.h>
#include <stdlib.h>
#include "adjacencyMatrix.c"
int dist[MAX_VERTICES];           /* ���|���װ}�C */
int pi[MAX_VERTICES];             /* �e�@���I�}�C */
/* ���: ��M�Y�@���I�ܦU���I���̵u�Z�� */ 
void shortestPath(int source, int num) {
   int selected[MAX_VERTICES];    /* ��ܪ����I�}�C */    
   int min_len;                   /* �̵u�Z�� */
   int min_vertex = 1;            /* �̵u�Z�������I */
   int i,j;
   for ( i = 1; i <= num; i++ ) { /* ��l�}�C�j�� */
      selected[i] = 0;            /* �M���}�C���e */
      pi[i] = 0;                  /* �M���}�C���e */
      dist[i] = graph[source][i]; /* ��l�Z�� */
   }
   selected[source] = 1;          /* �}�l���I�[�J���X */
   dist[source] = 0;              /* �]�w�}�l���I�Z�� */
   printf("V   1   2   3   4   5   6\n");
   for ( j = 1; j <= num; j++ ) { /* ���dist[]�}�C���e */
      if ( j == 1 ) printf("%d", source); /* ��ܳ��I */ 
      if ( dist[j] == MAX ) printf("  ��");
      else printf("%4d", dist[j]);  /* ��ܶZ�� */
   }
   printf("\n");
   /* �@�@���泻�I��-1�����j�� */ 
   for ( i = 1; i <= num-1; i++ ) {      
      min_len = MAX;              /* ���]���L�a�j */      
      /* ��X�̵u�Z�����I���j�� */
      for ( j = 1; j <= num; j++ )
         /* �q���ݩ󶰦X�����I�}�C��M�̪�Z�����I s */
         if ( min_len > dist[j] && selected[j] == 0 ) {
            min_vertex = j;       /* �ثe�̵u�����I */
            min_len = dist[j];    /* �O���̵u�Z�� */
         }
      selected[min_vertex] = 1;   /* �N���I�[�J���X */
      printf("%d", min_vertex);   /* ��ܿ�ܪ������I */
      if ( i == 1 ) pi[min_vertex] = 1;/* �e���I */
      /* �p��}�l���I��U���I�̵u�Z���}�C���j�� */
      for ( j = 1; j <= num; j++ ) {
        if ( selected[j] == 0 &&  /* �O�_�Z������u */
        dist[min_vertex]+graph[min_vertex][j]<dist[j]) {
          /* ���w�����u���Z�� */
          dist[j]=dist[min_vertex]+graph[min_vertex][j];
          pi[j] = min_vertex;     /* �O���e�@�ӳ��I */
        }       
        if ( dist[j] == MAX ) printf("  ��");
        else printf("%4d", dist[j]);/* ��̵ܳu�Z�� */
      }
      printf("\n");
   }
   printf("�e�@���I�}�C: \n");  
   printf("V  1   2   3   4   5   6\n");
   for ( j = 1; j <= num; j++ ) { 
      printf("%4d", pi[j]);        /* ��ܫe�@�ӳ��I */ 
   }
   printf("\n");
}
/* �D�{�� */
int main() {
   int edge[7][3] = { {1, 2, 35},  /* �[�v��u�}�C */
                      {1, 3, 90},
                      {2, 3, 45},
                      {2, 4, 30},
                      {3, 5, 25},
                      {4, 5, 45},
                      {5, 6, 200} }; 
   createGraph(7, &edge[0][0]);   /* �إ߹ϧ� */
   printf("�ϧ�G���F���x�}���e:\n");
   printGraph();  /* ��ܹϧ� */
   printf("�q���I1��U���I�̪�Z����Dijkstra�p��L�{:\n");
   shortestPath(1,6);             /* ��M�̵u���| */
   system("PAUSE");
   return 0; 
}
