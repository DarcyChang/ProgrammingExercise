/* �{���d��: Ch9-4-1.c */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "radixQueue.c"
/* ���: ��ܱƧǰ}�C�����e */
void showList(int *data) {
   int i;
   for ( i = 0; i < MAX_LEN; i++ )
      printf("[%3d]", data[i]);   /* ��ܰ}�C���� */
   printf("\n");
}
/* ���: ���X��C���e�^�s��Ƨǰ}�C */
void refillList(int *data, RQueue head[]) {
   int i, j = 0;
   /* ���X��C�}�l���Ъ��}�C */ 
   for ( i = 0; i < DIGIT_SIZE; i++ )
      while ( head[i] != NULL ) {
         /* ���X��C��Ʀs�^�}�C */ 
      	 data[j] = dequeue(head, i);
         j++;
      }
}
/* ���: ��ƱƧǪk */
void radixSort(int *data, RQueue head[]) {
   int i, j, max, nth_d;
   int exp = 0;           
   int max_d = 0;
   max = data[0];     /* ��X�}�C�����̤j�� */ 
   for( i = 0; i < MAX_LEN; i++ )
      if ( data[i] > max ) max = data[i];
   while ( max > 0 ) {/* ��X�̤j�Ȫ���� */
      max_d++;
      max = max / 10;
   }
   for ( i = 0; i < max_d; i++ ) {/* ����U��ƪ��Ƨ� */ 
      exp++;                      /* �ثe����� */ 
      for ( j = 0; j < MAX_LEN; j++) {/* ���X�Ƨǰ}�C */
        /* �p��Ƨǭȫ��w��ƪ��� */ 
        nth_d =  data[j] % (int)pow(10, exp);
        nth_d = nth_d / (int)pow(10,exp-1);
        /* �s�J�U��ƪ���C */
        enqueue(head, nth_d, data[j]);
      }
      refillList(data, head);
      printf("%3d ���: ", (int)pow(10,exp-1));
      showList(data);
   }
}
/* �D�{�� */ 
int main() {
   /* �ƧǪ���ư}�C */ 
   int data[MAX_LEN]={13,219,532,55,422,164,98,422,334};
   RQueue head[DIGIT_SIZE];     /* ��C�}�l���Ъ��}�C */
   int i;
   for( i = 0; i < DIGIT_SIZE; i++)
      head[i] = NULL;           /* ��l�}�l���а}�C */
   printf("�Ƨǫe���e: ");        /* �Ƨǫe�}�C���e */
   showList(data);
   radixSort(data, head);         /* �����ƱƧǪk */
   printf("�Ƨǫᵲ�G: ");        /* �Ƨǫ�}�C���e */
   showList(data);
   system("PAUSE");
   return 0; 
}
