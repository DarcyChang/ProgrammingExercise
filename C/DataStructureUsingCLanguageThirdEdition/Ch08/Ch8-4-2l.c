/* �{���d��: Ch8-4-2l.c */
#include <stdio.h>
#include <stdlib.h>
#include "adjacencyList.c"
/* �D�{�� */
int main() {
   struct Vertex head[MAX_VERTICES]; /* ���I���c�}�C */
   struct Vertex head1[MAX_VERTICES]; /* ���I���c�}�C */
   int edge[9][3] = { {1, 2,  2},     /* �[�v��u�}�C */
                      {1, 3,  5},
                      {2, 4, 16},
                      {3, 2,  6},
                      {4, 5,  9},
                      {5, 3, 10},
                      {6, 3, 20},
                      {7, 2,  4},
                      {7, 5, 14}};
   createGraph(head, 7, &edge[0][0]);   /* �إ߹ϧ� */
   printf("�ϧ�G9���F����C���e:\n");
   printGraph(head);  /* ��ܹϧ� */
   createGraph(head1, 9, &edge[0][0]);  /* �إ߹ϧ� */
   printf("�ϧ�G9+2���F����C���e:\n");
   printGraph(head1);  /* ��ܹϧ� */
   system("PAUSE");
   return 0; 
}
