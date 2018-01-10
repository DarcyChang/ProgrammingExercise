/* �{���d��: Ch10-3-3.c */
#include <stdio.h>
#include <stdlib.h>
#define MAX_LEN      11          /* �̤j���}�C�ؤo */
/* ���: ���ɷj�M�k�����j��� */ 
int interSearch(int *data,int key,int left,int right) {
   int nextGuess;                /* �U�@�ӥi����� */
   int offset;                   /* ���ަ첾 */
   int range;                    /* ��Ƚd�� */
   int index_range;              /* ���޽d�� */
   int temp;
   if ( data[left] == key )      /* ���F */
      return left;
   else if ( left == right ||    /* �S����� */
           data[left] == data[right] )
         return -1;
      else {
        index_range = right - left;/* �p����޽d�� */
        /* �p����Ƚd�� */
        range = data[right] - data[left];
        offset = key - data[left]; /* �p����Ȧ첾 */
        temp = ( offset * index_range ) / range;
        nextGuess = left + temp;   /* �U�@�ӥi����� */
        if ( nextGuess == left )   /* �O�_�v�չL */
          nextGuess++;
        if ( key < data[nextGuess] )
          /* ���䳡�����j�I�s���ɷj�M */
          return interSearch(data,key,left,nextGuess-1);
        else
          /* �k�䳡�����j�I�s���ɷj�M */
          return interSearch(data,key,nextGuess,right);
      }
}
/* ���: ���ɷj�M�k */
int interpolation(int *data, int n, int key) {
   if ( key < data[0] || key > data[n-1] )
      return -1;                       /* �S����� */
   else
      return interSearch(data, key, 0, n-1); /* ���j�I�s */
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
      /* �I�s���ɷj�M�k���j�M��� */ 
      index = interpolation(data, MAX_LEN, target);
      if (index != -1)
          printf("�j�M�����: %d(%d)\n", target, index);
      else
          printf("�S���j�M�����: %d\n", target);
   }
   system("PAUSE");
   return 0;  
}
