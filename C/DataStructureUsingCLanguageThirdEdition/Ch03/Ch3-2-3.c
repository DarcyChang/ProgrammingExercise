/* �{���d��: Ch3-2-3.c */
#include <stdio.h>
#include <stdlib.h>
#define ROWS      4
/* �D�{�� */
int main() {
   /* �ŧi�ܼ� */
   int i;
   int values[ROWS] = { 10, 4, 5, 19 };
   /* �إ�int�����а}�C */
   int *tables[ROWS];   
   /* ���w���а}�C�������� */ 
   for ( i=0; i < ROWS; i++)
      tables[i] = &values[i];  /* ���o�}�C������} */ 
   /* ��ܫ��а}�C�������� */
   for ( i=0; i < ROWS; i++ ) {
      printf("*tables[%d]=%2d ", i, *tables[i]);      
      printf("��}=%p\n", tables[i]);
   }
   system("PAUSE");
   return 0; 
}
