/* �{���d��: Ch4-3-3.c */
#include <stdio.h>
#include <stdlib.h>
#include "Ch4-3.h"
#include "createList.c"
#include "insertNode.c"
/* �D�{�� */
int main() {
   int temp;  /* �ŧi�ܼ� */
   int data[6]={ 1, 2, 3, 4, 5, 6 };/* �إߦ�C���}�C */
   List ptr;
   createList(6, data);   /* �إߦ�C */
   printf("��Ӫ���C: ");
   printList();  /* ��ܦ�C */ 
   /* 4-3-3: �`�I���J */
   temp = 0;
   insertNode(NULL, 50); /* ���J�Ĥ@�Ӹ`�I */
   printf("���J���C: ");
   printList();          /* ��ܴ��J���C */
   while ( temp != -1 ) {
      printf("�п�J���J��᪺�l�H�s��(-1����) ==> ");
      scanf("%d", &temp);   /* Ū���l�H�s�� */
      if ( temp != -1 ) {
         ptr = searchNode(temp); /* ��M�`�I */
         if ( ptr != NULL ) 
            printf("�п�J�s���l�H�s��(0~100) ==> ");
            scanf("%d", &temp);  /* Ū���s���l�H�s�� */
            insertNode(ptr, temp);
            printf("���J���C: ");
            printList();          /* ��ܴ��J���C */
      } 
   }
   system("PAUSE");
   return 0; 
}
