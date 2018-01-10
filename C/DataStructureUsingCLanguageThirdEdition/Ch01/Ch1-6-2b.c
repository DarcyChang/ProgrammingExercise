/* �{���d��: Ch1-6-2b.c */
#include <stdio.h>
#include <stdlib.h>
#define MAX_LEN      11          /* �̤j���}�C�ؤo */
/* ���: �`�Ƿj�M�k */ 
int sequential(int *data, int n, int target) {
   int i;                        /* �ܼƫŧi */ 
   for ( i = 0; i < n; i++ )     /* �j�M�j�� */
      /* ����O�_�O��� */
      if ( data[i] == target )
         return i;
   return -1;      
}
/* �D�{�� */ 
int main() {
   int data[MAX_LEN] =          /* �j�M���}�C */
         {9, 25, 33, 74, 90, 15, 1, 8, 42, 66, 81};
   int i, index, target, c;
   printf("��l�}�C: "); 
   for ( i = 0; i < MAX_LEN; i++ )
       printf("[%d]", data[i]); /* ��ܰ}�C���� */
   printf("\n");
   target = 0;
   while ( target != -1 ) {
      printf("�п�J�j�M��(-1����) ==> ");
      scanf("%d", &target);
      /* �I�s�`�Ƿj�M�k���j�M��� */ 
      index = sequential(data, MAX_LEN, target);
      if (index != -1)
         printf("�j�M�����: %d(%d)\n", target, index);
      else
         printf("�S���j�M�����: %d\n", target);
   }
   system("PAUSE");
   return 0;
}
