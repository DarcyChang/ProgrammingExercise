/* �{���d��: Ch9-2-2.c */
#include <stdio.h>
#include <stdlib.h>
#define MAX_LEN      20            /* �̤j�}�C�ؤo */
/* ���: ��ܱƧǪk */ 
void selectSort(int *data, int count) {
   int i, j, k, pos, temp;         /* pos�̤p��Ư��� */
   for ( i = 0; i < count - 1; i++ ) { /* �Ĥ@�h�j�� */
      pos = i;
      temp = data[pos];
      /* ��M�̤p����� */
      for ( j = i + 1; j < count; j++ )/* �ĤG�h�j�� */
         if ( data[j] < temp ) {       /* �O�_��p */
            pos = j;                   /* ���̤p��� */
            temp = data[j];
         }
      data[pos] = data[i];             /* �洫��Ӿ�� */
      data[i] = temp;
      /* ��ܲĤ@�h�j������洫���}�C���� */
      printf("%d: ", i+1);
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
   selectSort(data, len);         /* �����ܱƧǪk */
   /* ��ܱƧǫ᪺��Ƴ��C */
   printf("\n��X�Ƨǵ��G: ");
   for ( i = 0; i < len; i++ )
      printf("[%d]", data[i]);
   printf("\n");
   system("PAUSE");
   return 0; 
}
