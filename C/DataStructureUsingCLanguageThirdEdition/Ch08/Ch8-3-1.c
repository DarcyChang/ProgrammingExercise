/* �{���d��: Ch8-3-1.c */
#include <stdio.h>
#include <stdlib.h>
#include "Ch8-2-2.h"
#include "createGraph.c"
int visited[MAX_VERTICES];        /* ���X�O���}�C */
/* ���: �ϧΪ��`���u���j�M�k */ 
void dfs(int vertex) {
   Graph ptr;
   visited[vertex] = 1;           /* �O���w���X�L */
   printf("[V%d] ", vertex);      /* ��ܨ��X�����I�� */
   ptr = head[vertex].next;       /* ���I���� */
   while ( ptr != NULL ) {        /* ���X�ܦ�C�� */
      if ( visited[ptr->data] == 0 ) /* �O�_���X�L */
         dfs(ptr->data);          /* ���j���X�I�s */
      ptr = ptr->next;            /* �U�@�ӳ��I */
   }
}
/* �D�{�� */
int main() {
   int edge[20][2] = { {1, 2}, {2, 1},  /* ��u�}�C */
                       {1, 3}, {3, 1},
                       {2, 4}, {4, 2},
                       {2, 5}, {5, 2},
                       {3, 6}, {6, 3},
                       {3, 7}, {7, 3},
                       {4, 8}, {8, 4},
                       {5, 8}, {8, 5},
                       {6, 8}, {8, 6},
                       {7, 8}, {8, 7} };
   int i;  /* �]�w���X��� */
   for ( i = 1; i < MAX_VERTICES; i++ ) visited[i] = 0;
   createGraph(20, &edge[0][0]);   /* �إ߹ϧ� */
   printf("�ϧ�G���F���x�}���e:\n");
   printGraph();  /* ��ܹϧ� */
   printf("�ϧΪ��`���u�����X:\n");
   dfs(1);        /* ��ܨ��X�L�{ */
   printf("\n");
   system("PAUSE");
   return 0; 
}
