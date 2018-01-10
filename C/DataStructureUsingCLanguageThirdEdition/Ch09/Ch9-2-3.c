/* �{���d��: Ch9-2-3.c */
#include <stdio.h>
#include <stdlib.h>
#define MAX_LEN      20            /* �̤j�}�C�ؤo */
/* ���: ���J�ƧǪk */ 
void insertSort(int *data, int count) {
   int i, j, k, temp;
   for ( i = 1; i < count; i++ ) { /* �Ĥ@�h�j�� */
      temp = data[i];              /* �إߪ�� */
      j = i - 1;                   /* �}�l���� */
      /* �ťX�@�Ӵ��J��m */
      while ( j >= 0 && temp < data[j] ) {
         data[j+1] = data[j];
         j--;
      }
      data[j+1] = temp;            /* ���J��� */
      /* ��ܲĤ@�h�j������洫���}�C���� */
      printf("%d: ", i);
      for ( k = 0; k < count; k++ )
         printf("[%d]", data[k]);
      printf("\n");       
   }
}
/* �D�{�� */ 
int main() {
   int data[MAX_LEN];             /* ��ư}�C */
   int i, key = 1, len = 0;       /* �}�C�ؤo */
   while ( key != -1 ) {
      printf("��J���ƧǪ���� ==> ");
      scanf("%d", &key);          /* Ū����� */
      if ( key > 0 ) {            /* �u�x�s����� */ 
         data[len++] = key;       /* ��s�}�C���� */
      }
   }
   insertSort(data, len);         /* ���洡�J�ƧǪk */
   /* ��ܱƧǫ᪺��Ƴ��C */
   printf("\n��X�Ƨǵ��G: ");
   for ( i = 0; i < len; i++ )
      printf("[%d]", data[i]);
   printf("\n");
   system("PAUSE");
   return 0; 
}
