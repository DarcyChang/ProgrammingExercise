/* �{���d��: Ch4-3-1.c */
#include <stdio.h>
#include <stdlib.h>
#include "Ch4-3.h"
#include "createList.c"
/* �D�{�� */
int main() {
   int temp;  /* �ŧi�ܼ� */
   int data[6]={ 1, 2, 3, 4, 5, 6 };/* �إߦ�C���}�C */
   List ptr;
   /* 4-3-1: �إ�, ���X�P�j�M��C */ 
   createList(6, data);   /* �إߦ�C */
   printf("��Ӫ���C: ");
   printList();  /* ��ܦ�C */
   printf("��C�O�_�Ū�: %d\n", isListEmpty());
   temp = 0; 
   while ( temp != -1 ) {
      printf("�п�J�j�M���l�H�s��(-1����) ==> ");
      scanf("%d", &temp);  /* Ū���`�I�� */
      if ( temp != -1 )    /* �j�M�`�I��� */
         if ( searchNode(temp) != NULL ) 
            printf("��C�]�t�`�I[%d]\n", temp);
         else
            printf("��C���t�`�I[%d]\n", temp);
   }  
   system("PAUSE");
   return 0; 
}
