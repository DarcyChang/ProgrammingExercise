/* �{���d��: Ch1-5-2.c */
#include <stdio.h>
#include <stdlib.h>
/* ���: �p��n!���� */
long factorial(int n) {
   if ( n == 1 )                  /* �פ���� */
      return 1;
   else
      return n * factorial(n-1);
}
/* �D�{�� */
int main() {
   /* �ܼƫŧi */
   int no = 0;
   char c;
   while( no != -1 ) {
      printf("�п�J���h��(-1����)==> ");
      scanf("%d", &no);
      if ( no > 0 )
         /* ��ƪ��I�s */
         printf("%d!��ƪ���: %ld\n",no,factorial(no));
   }
   system("PAUSE");
   return 0; 
}
