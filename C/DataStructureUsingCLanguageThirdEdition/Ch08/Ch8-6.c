/* �{���d��: Ch8-6.c */
#include <stdio.h>
#include <stdlib.h>
#include "queue.c"
#include "adjacencyList.c"
/* ���: �ϧΪ��ݾ�Ƨ� */ 
int topoSort(Graph head, int num) {
   Graph ptr;
   int i, vertex;
   /* �N������׬��s�������I�s�J��C���j�� */
   for ( i = 1; i <= num; i++ )
      if ( head[i].data == 0 )  /* �p�G����׬O�s */
         enqueue(i);            /* �N���I�s�J��C */
   while ( !isQueueEmpty() ) {  /* ��C�O�_�w�� */
      vertex = dequeue();       /* �N���I�q��C���X */    
      printf(" %d ", vertex);   /* ��ܩݾ�ƧǪ����I */
      ptr = head[vertex].next;  /* ���I���� */
      while ( ptr != NULL ) {   /* ���X�ܦ�C�� */
         vertex = ptr->data;    /* ���o���I�� */
         head[vertex].data--;   /* ���I������״�@ */
         /* �p�G������׬O�s */
         if ( head[vertex].data == 0  )
            enqueue(vertex);    /* �N���I�s�J��C */
         ptr = ptr->next;       /* �U�@�ӳ��I */
      }
   }
   printf("\n");
   for ( i = 1; i <= num; i++ ) /* �ˬd�O�_���j�� */
      if ( head[i].data != 0 )  /* ������פ��O�s */
         return 1;              /* ���j�� */
   return 0;                    /* �S���j�� */
}
/* �D�{�� */
int main() {
   struct Vertex head1[MAX_VERTICES]; /* ���I���c�}�C */
   struct Vertex head2[MAX_VERTICES]; /* ���I���c�}�C */
   int edge[10][3] = { {3, 2, 1},     /* ��u�}�C */
                       {2, 1, 1},
                       {2, 5, 1},
                       {2, 6, 1},
                       {1, 4, 1},
                       {5, 4, 1},
                       {7, 4, 1},
                       {6, 7, 1},
                       {5, 6, 1},
                       {7, 5, 1} };
   createGraph(head1,8,&edge[0][0]);  /* �إ߹ϧ�1 */
   printf("�ϧ�1���F����C���e================== \n");
   printGraph(head1);  /* ��ܹϧ�1 */
   printf("�ϧ�1�ݾ�ƧǪ����e:\n");
   if ( topoSort(head1, 7) )          /* �ݾ�Ƨ� */
      printf("�ϧ�1���j��\n");
   else
      printf("�ϧ�1�S���j��\n");
   front = rear = NULL;               /* �M����C */
   createGraph(head2,10,&edge[0][0]); /* �إ߹ϧ�2 */
   printf("�ϧ�2���F����C���e================== \n");
   printGraph(head2);  /* ��ܹϧ�2 */
   printf("�ϧ�2�ݾ�ƧǪ����e:\n");
   if ( topoSort(head2, 7) )          /* �ݾ�Ƨ� */
      printf("�ϧ�2���j��\n");
   else
      printf("�ϧ�2�S���j��\n");
   system("PAUSE");
   return 0; 
}
