/* �{���d��: Ch3-5.c */
#include <stdio.h>
#include <stdlib.h>
#include "Ch3-5.h"
#include "String.c"
/* �D�{�� */
int main() {
   /* �ŧi�ܼ� */
   char str[80];
   char str1[80];
   char *ptr;
   int len;
   printf("�п�J�B�z���r��: ");
   gets(str);
   /* ��ܦr�� */ 
   printf("��l�r��: \"%s\"\n", str);
   /* ��ܦr����� */ 
   len = strLen(str);
   printf("�r��\"%s\"�����׬�: %d\n", str, len);
   /* �ƻs�r�� */ 
   printf("�ƻs�r��: \"%s\"\n", strCpy(str1, str));
   printf("�п�J���s�����r��: ");
   gets(str1);
   printf("���s���r��: \"%s\"\n", str1); 
   ptr = strCat(str, str1);       /* �s���r�� */ 
   printf("�s�����G���r��: \"%s\"\n", ptr);
   printf("�п�J��������r��: ");
   gets(str1);
   printf("��������r��: \"%s\"\n", str1);
   /* �r���� */ 
   printf("�r�������G: %d\n", strCmp(str, str1));
   printf("�п�J�j�M�r��: ");
   gets(str1);
   printf("�j�M�r��: \"%s\"\n", str1);    
   ptr = strPos(str, str1);        /* �j�M�r�� */
   if ( ptr != NULL )
      printf("�j�M�r��X�{����}:%p(%c)\n", ptr, *ptr);
   else
      printf("�j�M�r�ꤣ�O�l�r��\n");
   system("PAUSE");
   return 0; 
}
