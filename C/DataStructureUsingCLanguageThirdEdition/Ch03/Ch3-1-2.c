/* �{���d��: Ch3-1-2.c */
#include <stdio.h>
#include <stdlib.h>
/* �D�{�� */
int main() {
   /* �ŧi�ܼ� */
   int i, j;
   int *ptr = NULL;
   int *ptr1 = &i;  /* �����ܼƪ���� */ 
   i = 1;
   j = 2; 
   /* ���o�����ܼƪ��� */
   ptr = &j;
   printf("i   =%8d ��}=%p\n", i, &i);
   printf("j   =%8d ��}=%p\n", j, &j);
   printf("ptr =%p ��}=%p\n", ptr, &ptr);
   printf("*ptr :��}%p����=%d\n", ptr, *ptr);
   printf("ptr1=%p ��}=%p\n", ptr1, &ptr1);
   printf("*ptr1:��}%p����=%d\n", ptr1, *ptr1);
   system("PAUSE");
   return 0; 
}
