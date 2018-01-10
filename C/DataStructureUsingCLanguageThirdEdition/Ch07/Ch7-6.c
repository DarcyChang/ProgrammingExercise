/* �{���d��: Ch7-6.c */
#include <stdio.h>
#include <stdlib.h>
struct TNode {            /* �޽u�G���𪺸`�I�ŧi */
   int data;              /* �x�s�`�I��� */ 
   struct TNode *left;    /* ���V���l�𪺫��� */
   struct TNode *right;   /* ���V�k�l�𪺫��� */
   int isThread;          /* �k���ЬO�_�O�޽u */
};
typedef struct TNode RTNode;/* �޽u�G����`�I�s���A */
typedef RTNode *RTBTree;    /* �޽u�G���𪺷s���A */
RTBTree head = NULL;        /* �޽u�G����ڸ`�I������ */
/* ���: �޽u�G���𪺸`�I���J�����j��� */
void insertRTNode(RTBTree parent, int d) {
   RTBTree newnode;   
   if ( d < parent->data ) { /* ���� */
      if ( parent->left == NULL ) {
         /* �إߥ��l�`�I, �t�m�s�`�I���O���� */
         parent->left = (RTBTree) malloc(sizeof(RTNode));
         parent->left->data = d;   /* �إ߸`�I���e */ 
         parent->left->left = NULL;
         parent->left->right = parent;
         parent->left->isThread = 1;  /* �O�޽u */
      }     /* ���j�����U�@�h */
      else  insertRTNode(parent->left, d);
   }
   else { /* ���k */
      if ( parent->isThread == 1 ) { /* �O�_�O�޽u */
         /* �إߥk�l�`�I, �t�m�s�`�I���O���� */
         newnode = (RTBTree) malloc(sizeof(RTNode));
         newnode->data = d;     /* �إ߸`�I���e */ 
         newnode->left = NULL;
         newnode->right = parent->right;
         newnode->isThread = 1; /* �O�޽u */
         parent->right = newnode;
         parent->isThread = 0;  /* ���O�޽u */
      }    /* ���j���k�U�@�h */
      else insertRTNode(parent->right, d);
   } 
}
/* ���: �إߤ޽u�G���� */
void createRTBTree(int len, int *array) {
   int i; 
   /* �إ߮ڸ`�I */ 
   head = (RTBTree) malloc(sizeof(RTNode));
   head->data = array[0];      
   head->left = NULL;
   head->right = NULL;
   head->isThread = 1;
   /* �ϥΰj��إ߾𪬵��c */
   for ( i = 1; i < len; i++ )
      insertRTNode(head, array[i]); /* ���J�`�I */
}
/* ���: ���Ǩ��X�޽u�G���� */
void printRTBTree() {
   RTBTree ptr = NULL;
   int haveNext = 1;
   while ( haveNext ) {  /* ���Ǩ��X�j�� */
      if ( ptr == NULL ) {
         ptr = head;    /* ���V�ڸ`�I */
         while ( ptr->left != NULL )  /* �����l�� */
            ptr = ptr->left;
      }
      else {
         if ( ptr->isThread == 1 )  /* �O�_�O�޽u */
            ptr = ptr->right;       /* ���k�l�� */
         else {
            ptr = ptr->right;       /* ����k�l�`�I */
            while ( ptr->left != NULL )  /* �����l�� */
               ptr = ptr->left;         
         }
      }
      if ( ptr == NULL ) haveNext = 0;
      else printf("[%d]",ptr->data);  /* ��ܸ`�I */
   }
   printf("\n");
}
/* �D�{�� */
int main() {
   /* �G���𪺸`�I��� */
   int data[9] = { 5, 6, 4, 8, 2, 3, 7, 1, 9 };
   createRTBTree(9, data);     /* �إߤ޽u�G���� */
   printf("�k�޽u�G���𪺤��Ǩ��X: \n");
   printRTBTree();   
   system("PAUSE");
   return 0; 
}
