/* �{���d��: Ch2-2-2.c */
#include <stdio.h>
#include <stdlib.h>
#define ROW    6     /* �w�q�C�� */
#define COLUMN 5     /* �w�q��� */
/* �D�{�� */
int main() {
   /* �ǥͥ\�Ҫ�, �ϥνҵ{�N�X */
   int classes[30] = { 0, 1, 5, 0, 3, 0,
                       2, 4, 0, 0, 0, 0,
                       0, 1, 5, 0, 3, 0,
                       2, 4, 0, 0, 0, 0,
                       0, 1, 5, 0, 3, 0 };
   int sum = 0;   /* �W���`�`�� */
   int i, j;
   for ( i = 0; i < 30; i++ )   /* �@���}�C�����X */
      printf("%d:%d ", i, classes[i]); 
   printf("\n");
   for ( j = 0; j < COLUMN; j++ ) /* �G���}�C�����X */
      for ( i = 0; i < ROW; i++ ) 
         if ( classes[j*ROW+i] != 0 ) /* �O�_���� */
            sum++;
   /* ��ܤW���`�`�� */
   printf("�W���`�`��: %d\n", sum);
   system("PAUSE");
   return 0; 
}
