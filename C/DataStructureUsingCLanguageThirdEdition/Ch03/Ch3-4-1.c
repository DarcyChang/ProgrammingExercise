/* �{���d��: Ch3-4-1.c */
#include <stdio.h>
#include <stdlib.h>
#define LEN       16
/* �D�{�� */
int main() {
   /* �r���}�C�ŧi */
   char str[LEN] = "This is a book.";
   char str1[LEN];
   /* �r������ */
   char *ptr  = str;
   char *ptr1;
   int i; 
   /* ��ܦr�ꤺ�e */
   ptr1 = "This is a pen.";
   printf("str = %s\n", str);
   printf("ptr = %s\n", ptr);
   printf("ptr1 = %s\n", ptr1);
   /* �r��ƻs���j�� */
   printf("�N�r��str�ƻs��str1: \n"); 
   i = 0;
   ptr1 = str1;
   while ( *ptr != '\0' ) {
      *(ptr1+i) = *ptr++;
      i++;
   }
   *(ptr1+i) = '\0';
   printf("str1 = %s\n", str1);
   printf("ptr1 = %s\n", ptr1);
   system("PAUSE");
   return 0; 
}
