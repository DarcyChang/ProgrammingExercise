/* �{���d��: Ch10-3-1.c */
#include <stdio.h>
#include <stdlib.h>
#define MAX_LEN      11          /* �̤j���}�C�ؤo */
/* ���: �G���j�M�k */ 
int binary(int *data, int low, int high, int target) {
   int middle;                   /* �ŧi�ܼ� */
   if (low > high)               /* ���j���פ���� */
      return -1;
   else {  /* ���o�������� */
      middle = (low + high) / 2;
      if ( target == data[middle] ) /* ��� */
         return middle;   /* �Ǧ^���ޭ� */
      else if ( target < data[middle] )/* �e�b���� */
              return binary(data,low,middle-1,target);
           else   /* ��b���� */
              return binary(data,middle+1,high,target);
   }
}
/* �D�{�� */ 
int main() {
   int data[MAX_LEN] =          /* �j�M���}�C */
         {1, 8, 9, 15, 25, 33, 42, 66, 74, 81, 90};
   int i, index, target, c;
   printf("��l�}�C: "); 
   for ( i = 0; i < MAX_LEN; i++ )
       printf("[%d]", data[i]); /* ��ܰ}�C���� */
   printf("\n");
   target = 0;
   while ( target != -1 ) {
      printf("�п�J�j�M��(-1����) ==> ");
      scanf("%d", &target);
      /* �I�s�G���j�M�k���j�M��� */ 
      index = binary(data, 0, MAX_LEN-1, target);
      if (index != -1)
          printf("�j�M�����: %d(%d)\n", target, index);
      else
          printf("�S���j�M�����: %d\n", target);
   }
   system("PAUSE");
   return 0;  
}
