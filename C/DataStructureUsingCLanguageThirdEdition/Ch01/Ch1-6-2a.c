/* �{���d��: Ch1-6-2a.c */
#include <stdio.h>
#include <stdlib.h>
#define MAX_LEN      11          /* �̤j���}�C�ؤo */
/* ���: �}�C�����M */ 
int sumArray(int *data, int n) {
   int i, total = 0;
   for ( i = 0; i < n; i++ )
      total += data[i];
   return total;
}
/* �D�{�� */
int main() {
   /* �ܼƫŧi */
   int data[MAX_LEN] =        /* �}�C���e */
          {9, 25, 33, 74, 90, 15, 1, 8, 42, 66, 81};
   int i;
   printf("��l�}�C: "); 
   for ( i = 0; i < MAX_LEN; i++ )
      printf("[%d]", data[i]); /* ��ܰ}�C���� */
   printf("\n");
   printf("�}�C�M: %d\n", sumArray(data, MAX_LEN)); 
   system("PAUSE");
   return 0; 
}
