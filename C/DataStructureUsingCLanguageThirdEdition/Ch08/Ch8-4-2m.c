/* �{���d��: Ch8-4-2m.c */
#include <stdio.h>
#include <stdlib.h>
#include "adjacencyMatrix.c"
/* �D�{�� */
int main() {
   int edge[7][3] = { {1, 2,  2},  /* �[�v��u�}�C */
                      {1, 3,  5},
                      {2, 4, 16},
                      {3, 2,  6},
                      {4, 5,  9},
                      {5, 3, 10},
                      {6, 3, 20}};
   createGraph(7, &edge[0][0]);   /* �إ߹ϧ� */
   printf("�ϧ�G9���F���x�}���e:\n");
   printGraph();  /* ��ܹϧ� */
   system("PAUSE");
   return 0; 
}
