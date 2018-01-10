/* �{���d��: Ch10-3-2.c */
#include <stdio.h>
#include <stdlib.h>
#define MAX_LEN      12          /* �̤j���}�C�ؤo */
/*  ���: �p��O��� */
int fib(int n) {
   if ( n <= 1 )                 /* N �O�_�p��� */
      if ( n == 0 ) return 0;    /* �Ǧ^0 */
      else          return 1;    /* �Ǧ^1 */
   else
      return fib(n-2) + fib(n-1);/* ���j�p��O��� */
}
/* ���: �p��O��ƦC�� k �ȷ� Fk+1 >= n + 1 */
int fibindex(int n, int *m) {
   int k = 0;                    /* ���wk�� */
   while ( fib(k) < n + 1 )      /* ����j�� */
      k++;                       /* �p�G����k�[�@ */
   if ( fib(k) != n + 1 )        /* ���O�O��� */ 
      *m = fib(k)-(n+1);         /* �p��m�� */ 
   return k - 1;                 /* �Ǧ^k */
}
/* ���: �O��j�M�k */
int fibsearch(int *data, int n, int key) {
   int k, m = 0;                 /* ���h��k�Pm */
   int mid;                      /* �O���ڸ`�I */
   int fn1, fn2, temp;
   k = fibindex(n, &m);          /* �p��k�Pm�� */
   mid = fib(k);                 /* �ڸ`�I���O��� */
   fn1 = fib(k - 1);             /* �e�@�ӶO��� */
   fn2 = fib(k - 2);             /* �e�G�ӶO��� */
   while ( mid != 0 ) {          /* �O��j�M�D�j�� */
      if ( key < data[mid-1-m] ) /* ����p */
         if ( fn2 <= 0 ) mid = 0;/* �S����� */
         else {
            mid = mid - fn2;     /* ���l�𪺷s�O��� */
            temp = fn1;          /* �p��k-1���t��fn2 */
            fn1 = fn2;           
            fn2 = temp - fn2;    
         }
         else if ( key > data[mid-1-m] ) /* ����j */
            if ( fn1 <= 0 ) mid = 0; /* �S����� */
            else {
               mid = mid + fn2;  /* �k�l�𪺷s�O��� */
               fn1 = fn1 - fn2;  /* �p��k-2���t��fn2 */
               fn2 = fn2 - fn1;  
            }
            else
               return mid-1-m;   /* ���F */
   }
   return -1;                    /* �S����� */
}
/* �D�{�� */ 
int main() {
   int data[MAX_LEN] = {         /* �j�M���}�C */
        12,   15,  17,  19,  27,  31,
        35,   43,  46,  77,  80,  95 };
   int i, index, target, c;
   printf("��l�}�C: "); 
   for ( i = 0; i < MAX_LEN; i++ )
       printf("[%d]", data[i]); /* ��ܰ}�C���� */
   printf("\n");
   target = 0;
   while ( target != -1 ) {
      printf("�п�J�j�M��(-1����) ==> ");
      scanf("%d", &target);
      /* �I�s�O��j�M�k���j�M��� */ 
      index = fibsearch(data, MAX_LEN, target);
      if (index != -1)
          printf("�j�M�����: %d(%d)\n", target, index);
      else
          printf("�S���j�M�����: %d\n", target);
   }
   system("PAUSE");
   return 0;  
}
