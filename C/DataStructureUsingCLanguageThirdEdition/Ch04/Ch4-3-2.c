/* �{���d��: Ch4-3-2.c */
#include <stdio.h>
#include <stdlib.h>
#include "Ch4-3.h"
#include "createList.c"
#include "deleteNode.c"
/* �D�{�� */
int main() {
   int temp;  /* �ŧi�ܼ� */
   int data[6]={ 1, 2, 3, 4, 5, 6 };/* �إߦ�C���}�C */
   List ptr;
   createList(6, data);   /* �إߦ�C */
   printf("��Ӫ���C: ");
   printList();  /* ��ܦ�C */ 
   /* 4-3-2: �`�I�R�� */
   temp = 0; 
   while ( temp != -1 ) {
      printf("�п�J�R�����l�H�s��(-1����) ==> ");
      scanf("%d", &temp);  /* Ū���l�H�s�� */
      if ( temp != -1 ) {  /* �j�M�`�I��� */
         ptr = searchNode(temp);  /* ��M�`�I */
         if ( ptr != NULL ) {
            temp = deleteNode(ptr); /* �R���`�I */
            printf("�R���`�I: %d\n", temp); 
            printf("�R�����C: ");
            printList();        /* ��ܧR�����C */
         }         
      }
   }
   system("PAUSE");
   return 0; 
}
