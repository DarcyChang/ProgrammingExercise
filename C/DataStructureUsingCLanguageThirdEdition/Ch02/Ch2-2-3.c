/* �{���d��: Ch2-2-3.c */
#include <stdio.h>
#include <stdlib.h>
#define ROW    6     /* �w�q�C�� */
#define COLUMN 5     /* �w�q��� */
/* �D�{�� */
int main() {
   /* �ǥͥ\�Ҫ�, �ϥνҵ{�N�X */
   int data[25] = {0, 2, 0, 2, 0,
                   1, 4, 1, 4, 1,
                   5, 0, 5, 0, 5,
                   3, 0, 3, 0, 3,
                   0, 0, 0, 0, 0 };
   /* ���а}�C */
   int pointer[6] = { 0, 10, 5, 20, 15, 20 };
   int sum = 0;   /* �W���`�`�� */
   int i, j;
   for ( i = 0; i < 25; i++ )   /* �@���}�C�����X */
      printf("%d:%d ", i, data[i]); 
   printf("\n");
   for ( i = 0; i < ROW; i++ )    /* �G���}�C�����X */
      for ( j = 0; j < COLUMN; j++ )
         if ( data[pointer[i]+j] != 0 ) /* �O�_���� */
            sum++;
   /* ��ܤW���`�`�� */
   printf("�W���`�`��: %d\n", sum);
   system("PAUSE");
   return 0; 
}
