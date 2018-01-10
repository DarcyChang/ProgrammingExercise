/* �{���d��: Ch9-3-2.c */
#include <stdio.h>
#include <stdlib.h>
#define MAX_LEN      20           /* �̤j�}�C�ؤo */
/* ���: �ֳt�ƧǪk�����j��� */
void q_sort(int *data, int left, int right) {
   int partition;                /* ���Ϊ���� */
   int temp, i, j, k;
   if ( left < right ) {/* ���j�������, �O�_�~����� */
      i = left;                   /* ���Ϊ��̥����� */
      j = right + 1;              /* ���Ϊ��̥k���� */
      partition = data[left];     /* ���Ĥ@�Ӥ��� */
      do {  /* �D�j����O�q��Ӥ�V��M�洫���� */ 
         do {                     /* �q�����k�� */
            i++;
         } while( data[i] < partition );
         do {                     /* �q�k������ */
            j--;
         } while( data[j] > partition );
         if ( i < j ) {
            temp = data[i];       /* �洫��� */
            data[i] = data[j];
            data[j] = temp;
         }
      } while( i < j );
      temp = data[left];          /* �洫��� */
      data[left] = data[j];
      data[j] = temp;
      printf("��X���G: ");  /* ��ܳB�z�����r�� */
      for ( k = left; k <= right; k++)
         printf("%d", data[k]);
      printf("\n");               /* ���� */
      q_sort(data, left, j-1);    /* �ֳt�Ƨǻ��j�I�s */
      q_sort(data, j+1, right);   /* �ֳt�Ƨǻ��j�I�s */
   }
}
/* ���: �ֳt�ƧǪk */
void quickSort(int *data, int count) {
   q_sort(data, 0, count-1);
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
   quickSort(data, len);          /* ����ֳt�ƧǪk */
   /* ��ܱƧǫ᪺��Ƴ��C */
   printf("\n��X�Ƨǵ��G: ");
   for ( i = 0; i < len; i++ )
      printf("[%d]", data[i]);
   printf("\n");
   system("PAUSE");
   return 0; 
}
