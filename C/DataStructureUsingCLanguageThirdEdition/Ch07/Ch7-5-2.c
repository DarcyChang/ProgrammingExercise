/* �{���d��: Ch7-5-2.c */
#include <stdio.h>
#include <stdlib.h>
#include "Ch7-5.h"
#include "createBSTree.c"
/* ���: �G���j�M�𪺸`�I�R�� */
void deleteBSTreeNode(int d) {
   BSTree parent;      /* ���`�I���� */
   BSTree ptr;         /* �R���`�I���� */
   BSTree child;       /* �l�`�I���� */
   int isfound = 0;    /* �O�_���R���`�I */ 
   /* ��M�R���`�I�M����`�I���� */
   parent = ptr = head;
   while ( ptr != NULL && !isfound ) { /* �D�j�� */
      if ( ptr->data == d )   
         isfound = 1;         /* ���R���`�I */
      else {
         parent = ptr;        /* �O�d���`�I���� */
         if ( ptr->data > d ) /* ������ */
             ptr = ptr->left; /* ���l�� */
         else
             ptr = ptr->right;/* �k�l�� */
      }       
   }
   if ( ptr == NULL ) return;  /* �S�����R���`�I */
   /* �R���G���j�M�𪺸`�I, ���p1: ���`�I */
   if ( ptr->left == NULL && ptr->right == NULL ) {
      if ( parent->left == ptr )
         parent->left = NULL; /* ���l�`�I */
      else
         parent->right = NULL; /* �k�l�`�I */ 
      free(ptr);               /* ���^�`�I�O����     */
      return;
   }
   /* ���p2: �S�����l�� */
   if ( ptr->left == NULL ) {
      if ( parent != ptr )     /* �۵��O�ڸ`�I */
         if ( parent->left == ptr )
            parent->left = ptr->right; /* ���l�`�I */ 
         else parent->right = ptr->right; /* �k�l�`�I */ 
      else head = head->right;/* �ڸ`�I���V�k�l�`�I */
      free(ptr);               /* ���^�`�I�O����     */
      return;
   } /* ���p3: �S���k�l�� */
   if ( ptr->right == NULL ) {
      if ( parent != ptr )     /* �۵��O�ڸ`�I */
         if ( parent->right == ptr )
             parent->right = ptr->left;/* �k�l�`�I */ 
         else parent->left = ptr->left;/* ���l�`�I */ 
      else head = head->left;  /* �ڸ`�I���V���l�`�I */
      free(ptr);               /* ���^�`�I�O����     */
      return;
   } /* ���p4: �����l��M�k�l�� */
   parent = ptr;                /* ���`�I���V�R���`�I */
   child = ptr->left;             /* �]�w�����l�`�I */
   while ( child->right!=NULL ) { /* ���̥k�����`�I */
      parent = child;             /* �O�d���`�I���� */
      child = child->right;       /* ���k�l�� */
   }
   ptr->data = child->data;       /* �]�w�����`�I��� */
   if ( parent->left == child )   /* �l�`�I�S���k�l�� */
      parent->left = NULL;       
   else parent->right = child->left;/* �s�����中�`�I */
   free(child);                   /* ���^�`�I�O���� */
   return;
}
/* �D�{�� */
int main() {
   int temp = 0;
   /* �G���j�M�𪺸`�I��� */
   int data[9] = { 5, 6, 4, 8, 2, 3, 7, 1, 9 };
   createBSTree(9, data);     /* �إߤG���j�M�� */
   printf("�R���e���`�I���e: ");
   printBSTree();             /* ��ܤG���j�M�� */
   while ( temp != -1 ) {
      printf("�п�J�R�����`�I���1~9(-1����) ==> ");
      scanf("%d", &temp);  /* Ū���`�I�� */
      if ( temp != -1 ) {  /* �R���`�I��� */
         deleteBSTreeNode(temp); /* �R���`�I */
         printf("�R���᪺�`�I���e: ");
         printBSTree();          /* ��ܤG���j�M�� */
      }   
   }  
   system("PAUSE");
   return 0;    
}
