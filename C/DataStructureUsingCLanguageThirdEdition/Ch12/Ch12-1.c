/* �{���d��: Ch12-1.c */
#include <stdio.h>
#include <stdlib.h>
#define MAX_LEN      9     /* �̤j�}�C�ؤo */
struct Node {              /* �G���𪺸`�I�ŧi */
   int data;              /* �x�s�`�I��� */ 
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
void insertBSTreeNode(int d) {
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
void createBSTree(int len, int *array) {
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
   inOrder(head, "[%d]");  /* �I�s���Ǩ��X��� */
   printf("\n");
}
/* ���: �G���j�M��j�M�k */
int BSTreeSearch(BSTree ptr, int d) {
   if ( ptr != NULL ) {           /* �פ���� */
      if ( ptr->data == d )       /* ���F */
         return 1;
      else if ( ptr->data > d )   /* �����l��� */
            return BSTreeSearch(ptr->left, d);
         else                     /* ���k�l��� */
            return BSTreeSearch(ptr->right, d);
   } else return 0;               /* �S����� */
}
/* �D�{�� */ 
int main() {
   /* �G����`�I��� */
   int data[MAX_LEN]={55,61,41,87,24,35,79,11,99};
   int target;
   createBSTree(MAX_LEN, data);   /* �إߤG���j�M�� */ 
   printf("��X�Ƨǵ��G: ");
   BSTreeSort();              /* ����G���j�M��ƧǪk */
   target = 0;
   while ( target != -1 ) {
      printf("�п�J�j�M��(-1����) ==> ");
      scanf("%d", &target);
      /* �I�s�G���j�M��j�M�k���j�M��� */ 
      if ( BSTreeSearch(head, target))
          printf("�j�M�����: %d\n", target);
      else
          printf("�S���j�M�����: %d\n", target);
   }
   system("PAUSE");
   return 0; 
}
