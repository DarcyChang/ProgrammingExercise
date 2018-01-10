/* �{���d��: Ch8-5-2.c */
#include <stdio.h>
#include <stdlib.h>
#include "adjacencyMatrix.c"
int dist[MAX_VERTICES][MAX_VERTICES];/* ���|���װ}�C */
/* ���: ��M�U���I��U���I���̵u�Z�� */ 
void shortestPath(int num) {
   int i, j, k;
   /* ��l�}�C���_���j�� */
   for ( i = 1; i <= num; i++ )
      for ( j = i; j <= num; j++ )
         dist[i][j] = dist[j][i] = graph[i][j];         
   /* ��X�̵u�Z�����_���j�� */         
   for ( k = 1; k <= num; k++ )
      /* ���X�G���}�C�p��̵u���| */ 
      for ( i = 1; i <= num; i++ )
         for ( j = 1; j <= num; j++ )
            if ( dist[i][k] + dist[k][j] < dist[i][j] )
               /* ���w�������u���Z�� */
               dist[i][j] = dist[i][k] + dist[k][j];
   printf("V     1     2     3     4     5     6\n");
   for ( i = 1; i <= num; i++ ) {
      printf("%d ", i); 
      for ( j = 1; j <= num; j++ )
         printf(" %4d ", dist[i][j]); /* ��ܶZ���}�C */
      printf("\n");
   } 
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
   printf("�q�U���I��U���I�̪�Z����Floyd�p��L�{:\n");
   shortestPath(6);               /* ��M�̵u���| */   
   system("PAUSE");
   return 0; 
}
