/* �{���d��: Ch9-4-2.c */
#include <stdio.h>
#include <stdlib.h>
#define MAX_LEN      20    /* �̤j�r����� */
struct Node {              /* �G���𪺸`�I�ŧi */
   char data;              /* �x�s�`�I��� */ 
   struct Node *left;      /* ���V���l�𪺫��� */
   struct Node *right;     /* ���V�k�l�𪺫��� */          
};
typedef struct Node TNode;/* �G����`�I���s���A */
typedef TNode *BSTree;    /* �G���j�M�𪺷s���A */
BSTree head = NULL;       /* �G���j�M��ڸ`�I������ */
/* ���: �ˬd�G���j�M��O�_�O�Ū� */
int isBSTreeEmpty() {
   if ( head == NULL ) return 1;
   else                return 0; 
}
/* ���: �G���j�M�𪺸`�I���J) */
void insertBSTreeNode(char d) {
   BSTree newnode, current; /* �ثe�G����`�I���� */
   int inserted = 0; /* �O�_���J�s�`�I */
   /* �t�m�s�`�I���O���� */
   newnode = (BSTree) malloc(sizeof(TNode));
   newnode->data = d;      /* �إ߸`�I���e */ 
   newnode->left = NULL;
   newnode->right = NULL;
   if ( isBSTreeEmpty() )  /* �O�_�ŤG���� */
      head = newnode;      /* �إ߮ڸ`�I */
   else {  /* �O�d�ثe�G������� */
      current = head; 
      while( !inserted )    /* ����`�I�� */
         if ( current->data > newnode->data ) {
            /* �O�_�O�̥����l�`�I */
            if ( current->left == NULL ) {   
                current->left = newnode; /* �إ��쵲 */
                inserted = 1;
            } else current = current->left;/* ���l�� */
         }
         else {  /* �O�_�O�̥k���l�`�I */
            if ( current->right == NULL ) {
                current->right = newnode; /* �إ��쵲 */
                inserted = 1;
            } else current = current->right;/* �k�l�� */
         }
   }
}
/* ���: �إߤG���j�M�� */
void createBSTree(int len, char *array) {
   int i; 
   /* �ϥΰj��H���J�覡�إ߾𪬵��c */
   for ( i = 0; i < len; i++ ) 
      insertBSTreeNode(array[i]);
}
/* ���: �G���j�M�𪺤��Ǩ��X */
void inOrder(BSTree ptr, char *f) {
   if ( ptr != NULL ) {         /* �פ���� */
      inOrder(ptr->left, f);    /* ���l�� */
      /* ��ܸ`�I���e */
      printf(f, ptr->data); 
      inOrder(ptr->right, f);   /* �k�l�� */
   }
}
/* ���: �G���j�M��ƧǪk */
void BSTreeSort() {
   inOrder(head, "[%c]");  /* �I�s���Ǩ��X��� */
   printf("\n");
}
/* �D�{�� */ 
int main() {
   char data[MAX_LEN];            /* �r��}�C */
   int len;                       /* �r����� */
   printf("��J���ƧǪ��r�� ==> ");
   gets(data);                    /* Ū���r�� */
   len = strlen(data);            /* �p��r����� */
   createBSTree(len, data);       /* �إߤG���j�M�� */ 
   printf("��X�Ƨǵ��G: ");
   BSTreeSort();              /* ����G���j�M��ƧǪk */
   system("PAUSE");
   return 0; 
}
