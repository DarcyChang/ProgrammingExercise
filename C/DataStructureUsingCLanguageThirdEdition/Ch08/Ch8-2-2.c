/* �{���d��: Ch8-2-2.c */
#include <stdio.h>
#include <stdlib.h>
#include "Ch8-2-2.h"
#include "createGraph.c"
/* �D�{�� */
int main() {
   int edge[12][2] = { {1, 2}, {2, 1},  /* ��u�}�C */
                       {1, 3}, {3, 1},
                       {2, 3}, {3, 2},
                       {2, 4}, {4, 2},
                       {3, 5}, {5, 3},
                       {4, 5}, {5, 4} };
   createGraph(12, &edge[0][0]);   /* �إ߹ϧ� */
   printf("�ϧ�G���F����C���e:\n");
   printGraph();  /* ��ܹϧ� */
   system("PAUSE");
   return 0; 
}
