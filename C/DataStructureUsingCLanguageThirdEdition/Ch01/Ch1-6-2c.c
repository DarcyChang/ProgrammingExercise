/* �{���d��: Ch1-6-2c.c */
#include <stdio.h>
#include <stdlib.h>
/* ���: ��ܶO��ƦC */
void fibonacci(int n) {
   int fn;                        /* F(n)�ܼ� */
   int fn2;                       /* F(n-2)�ܼ� */
   int fn1;                       /* F(n-1)�ܼ� */
   int i;
   if ( n <= 1 )                  /* ���ƬO�_�p��1 */
      printf("F%d=[%d]\n", n, n); /* ��ܶ��� */
   else {
      fn2 = 0;                    /* �]�w F(n-2) */
      fn1 = 1;                    /* �]�w F(n-1) */
      for ( i = 2; i <= n; i++ ) {/* ��ܼƦC���j�� */
         fn = fn2 + fn1;          /* �p��U�@�붵 */
         fn2 = fn1;               /* ���] F(n-2) */
         fn1 = fn;                /* ���] F(n-1) */
      }
      printf("F%d=[%d]\n", n, fn);/* ��ܶ��� */
   }
}
/* �D�{�� */
int main() {
   /* �ܼƫŧi */
   int n;
   printf("�п�J�ƦC���� ==> ");
   scanf("%d",&n);                /* ��J���� */
   fibonacci(n);                  /* �I�s�O��ƦC��� */ 
   system("PAUSE");
   return 0; 
}
