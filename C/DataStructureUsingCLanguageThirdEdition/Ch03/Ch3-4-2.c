/* �{���d��: Ch3-4-2.c */
#include <stdio.h>
#include <stdlib.h>
#define ROWS      4
#define COLUMNS  10
/* �D�{�� */
int main() {
   /* �ŧi�ܼ� */
   int i, j;
   /* �إߤG�����r���}�C�B���w��� */
   char names[ROWS][COLUMNS] = { "���|�w", "���p��",
                                 "�i�L��", "���L" };
   /* ���а}�C */ 
   char *name[ROWS] = { "���|�w", "���p��",
                        "�i�L��", "���L" };
   char *ptr;
   /* ��ܤG���}�C�������� */
   printf("��ܤG���r���}�C�����e: \n"); 
   for ( i = 0; i < ROWS; i++ ) {
      printf("names[%d]=[", i);
      ptr = names[i]; 
      for ( j = 0; j < COLUMNS; j++)
         printf("%c", *(ptr+j));
      printf("]\n");
   }
   /* ��ܫ��а}�C�������� */
   printf("��ܫ��а}�C�����e: \n");
   for ( i = 0; i < ROWS; i++ ) {
      printf("name[%d] =[", i);
      ptr = name[i];  /* ���o�C�@�ӫ��� */ 
      for ( j = 0; *(ptr+j) != '\0'; j++)
         printf("%c", *(ptr+j));
      printf("]\n");
   }
   system("PAUSE");
   return 0; 
}
