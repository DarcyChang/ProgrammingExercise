/* �{���d��: Ch3-2-2.c */
#include <stdio.h>
#include <stdlib.h>
#define ROWS      4
#define COLS      5
/* �D�{�� */
int main() {
   /* �ŧi�ܼ� */
   int i, j;
   /* �إ�int���G���}�C */
   int tables[ROWS][COLS];
   int *ptr;
   /* ���w�G���}�C�������� */ 
   for ( i=0; i < ROWS; i++)
      for ( j=0; j < COLS; j++)
         tables[i][j] = (i+1)*(j+1);
   /* ��ܤG���}�C�������� */ 
   ptr = &tables[0][0];
   for ( i=0; i < ROWS; i++) {
      for ( j=0; j < COLS; j++)
         printf("%d*%d=%2d ", (i+1), (j+1),
                            *(ptr+(i*COLS)+j));
      printf("\n");
   }
   printf("\n");
   system("PAUSE");
   return 0; 
}
