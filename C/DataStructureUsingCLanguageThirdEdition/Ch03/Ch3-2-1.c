/* �{���d��: Ch3-2-1.c */
#include <stdio.h>
#include <stdlib.h>
#define LEN       6
/* �D�{�� */
int main() {
   /* �ŧi�ܼ� */
   int i;
   /* �إ�int�}�C�B���w��� */
   int array[LEN] = { 1, 23, 33, 17, -40, 100 };
   int *ptr = array;  /* �Ĥ@�Ӥ��� */ 
   /* ��ܰ}�C�������� */ 
   for ( i = 0; i < LEN; i++ )
      printf("array[%d]=%d ",i,array[i]);
   printf("\n");
   ptr = array;  /* �Ĥ@�Ӥ��� */ 
   for ( i = 0; i < LEN; i++ )
      printf("ptr+%d=%d ", i, *(ptr+i));
   printf("\n");
   ptr = &array[0];  /* �Ĥ@�Ӥ��� */ 
   for ( i = 0; i < LEN; i++ )
      printf("ptr+%d=%d ", i, *ptr++);
   printf("\n");
   ptr = &array[LEN-1];  /* �̫�@�Ӥ��� */ 
   for ( i = 0; i < LEN; i++ )
      printf("ptr-%d=%d ", i, *ptr--);
   printf("\n");
   system("PAUSE");
   return 0; 
}
