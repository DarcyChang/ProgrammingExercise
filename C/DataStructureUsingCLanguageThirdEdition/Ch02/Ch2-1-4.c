/* �{���d��: Ch2-1-4.c */ 
#include <stdio.h>
#include <stdlib.h>
/* �D�{�� */
int main() {
   /* �ǥͥ\�Ҫ�, �ϥνҵ{�N�X */
   int courses[6][5]={0, 2, 0, 2, 0,
                      1, 4, 1, 4, 1,
                      5, 0, 5, 0, 5,
                      0, 0, 0, 0, 0,
                      3, 0, 3, 0, 3,
                      0, 0, 0, 0, 0 };
   int sum = 0;   /* �W���`�`�� */
   int i,j;
   for ( i = 0; i < 6; i++ )    /* �G���}�C�����X */
      for ( j = 0; j < 5; j++ )
         if ( courses[i][j] != 0 ) /* �O�_���� */
            sum++;
   /* ��ܤW���`�`�� */
   printf("�W���`�`��: %d\n", sum);
   system("PAUSE");
   return 0; 
}
