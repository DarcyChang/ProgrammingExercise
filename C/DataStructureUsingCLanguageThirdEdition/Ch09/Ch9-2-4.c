/* �{���d��: Ch9-2-4.c */
#include <stdio.h>
#include <stdlib.h>
#define MAX_LEN      20           /* �̤j�}�C�ؤo */
#define H_LEN         3           /* h��C���̤j�� */ 
/* ���: �¦ձƧǪk */
void shellSort(int *data, int count) {
   int incs[H_LEN]={ 4, 2, 1 };   /* �]�wh�ǦC���W�q */
   int pos;                       /* �B�z���ثe���� */
   int h;                         /* h�ǦC���첾�q */
   int i, j, k, temp;
   for ( i = 0; i < H_LEN ; i++ ) {/* �B�zh�ǦC���j�� */
      h = incs[i];                /* ���oh�첾�q */
      for ( j = h; j < count; j++ ) { /* �洫�j�� */
         temp = data[j];          /* �O�d�� */
         pos = j - h;             /* �p����� */
         while ( temp < data[pos] &&    /* ��� */
                 pos >= 0 && j <= count) {
            data[pos + h] = data[pos];  /* �洫 */
            pos = pos - h;        /* �U�@�ӳB�z���� */
         }
         data[pos + h] = temp;    /* �P�̫ᤸ���洫 */
      }
      /* ��ܳB�z�᪺�}�C���e */
      printf("h�ǦC %d: ", h);
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
   shellSort(data, len);          /* �����¦ձƧǪk */
   /* ��ܱƧǫ᪺��Ƴ��C */
   printf("\n��X�Ƨǵ��G: ");
   for ( i = 0; i < len; i++ )
      printf("[%d]", data[i]);
   printf("\n");
   system("PAUSE");
   return 0; 
}
