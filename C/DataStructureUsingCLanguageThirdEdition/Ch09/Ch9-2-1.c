/* �{���d��: Ch9-2-1.c */
#include <stdio.h>
#include <stdlib.h>
#define MAX_LEN      20            /* �̤j�}�C�ؤo */
/* ���: �w�j�ƧǪk */ 
void bubbleSort(int *data, int count) {
   int i, j, k;                    /* �ܼƫŧi */ 
   int temp;
   for ( j = count; j > 1; j-- ) { /* �Ĥ@�h�j�� */
      for ( i = 0; i < j - 1; i++ )/* �ĤG�h�j�� */
         /* ����۾F���}�C���� */
         if ( data[i+1] < data[i] ) {
            temp = data[i+1];      /* �洫�}�C���� */
            data[i+1] = data[i];
            data[i] = temp;
         }
      /* ��ܲĤ@�h�j������洫���}�C���� */
      printf("%d: ", count-j+1);
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
   bubbleSort(data, len);         /* ����w�j�ƧǪk */
   /* ��ܱƧǫ᪺��Ƴ��C */
   printf("\n��X�Ƨǵ��G: ");
   for ( i = 0; i < len; i++ )
      printf("[%d]", data[i]);
   printf("\n");
   system("PAUSE");
   return 0; 
}
