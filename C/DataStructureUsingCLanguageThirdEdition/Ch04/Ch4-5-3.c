/* �{���d��: Ch4-5-3.c */
#include <stdio.h>
#include <stdlib.h>
#include "Ch4-5.h"
#include "createDList.c"
#include "deleteDNode.c"
/* �D�{�� */
int main() {
   int temp = 1;  /* �ŧi�ܼ� */
   int data[6]={ 1, 2, 3, 4, 5, 6 };/* �إߦ�C���}�C */
   createDList(6, data);   /* �إ����V��C */ 
   while ( temp != 4 ) { 
      printf("��Ӫ���C: ");
      printDList();           /* ��ܦ�C */
      printf("[1]���U���� [2]���e���� ");
      printf("[3]�R���`�I [4]���} ==> ");
      scanf("%d", &temp);        /* Ū�J�ﶵ */
      switch ( temp ) {
         case 1: nextNode();     /* ���U���� */
            break;
         case 2: previousNode(); /* ���e���� */ 
            break;
         case 3: /* �R���`�I */
            deleteDNode(readNode());
            resetNode();         /* ���]�ثe���� */ 
            break;
      }
   }      
   system("PAUSE");
   return 0; 
}
