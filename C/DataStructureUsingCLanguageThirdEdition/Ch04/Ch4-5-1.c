/* �{���d��: Ch4-5-1.c */
#include <stdio.h>
#include <stdlib.h>
#include "Ch4-5.h"
#include "createDList.c"
/* �D�{�� */
int main() {
   int temp = 1;  /* �ŧi�ܼ� */
   int data[6]={ 1, 2, 3, 4, 5, 6 };/* �إߦ�C���}�C */
   /* 4-5-1: �إ߻P���X���V��C */
   createDList(6, data);   /* �إ����V��C */
   while ( temp != 5 ) {
      printf("��Ӫ���C: ");
      printDList();  /* ������V��C */ 
      printf("[1]���U���� [2]���e���� ");
      printf("[3]���] [4]�`�I�� [5]���} ==> ");
      scanf("%d", &temp);        /* Ū�J�ﶵ */
      switch ( temp ) {
         case 1: nextNode();     /* ���U���� */
            break;
         case 2: previousNode(); /* ���e���� */ 
            break;
         case 3: resetNode();    /* ���]���� */ 
            break;
         case 4: /* Ū���`�I�� */
            printf("�`�I��: %d\n", readNode()->data); 
            break;
      }
   }      
   system("PAUSE");
   return 0; 
}
