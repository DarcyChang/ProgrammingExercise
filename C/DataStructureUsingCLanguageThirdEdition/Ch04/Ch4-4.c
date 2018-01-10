/* �{���d��: Ch4-4.c */
#include <stdio.h>
#include <stdlib.h>
struct Node {         /* Node�`�I���c */
   int data;          /* ���c�ܼƫŧi */ 
   struct Node *next; /* ���V�U�@�Ӹ`�I */
};
typedef struct Node CNode;   /* ������C�`�I���s���A */
typedef CNode *CList;        /* ������C���s���A */
CList first = NULL;          /* ������C���}�Y���� */
/* ���: �إ�������C */
void createCList(int len, int *array) {
   CList last;    /* �̫�@�Ӹ`�I������ */
   CList newnode;
   int i;
   for ( i = 0; i < len; i++ ) {
      /* �t�m�`�I�O���� */
      newnode = (CList) malloc(sizeof(CNode));
      newnode->data = array[i]; /* �إ߸`�I���e */
      if ( i == 0 ) last = newnode; /* ���V�̫�@�Ӹ`�I */
      newnode->next = first;
      first = newnode;
   }
   last->next = first;   /* �s����1�Ӹ`�I, �إ�������C */
}
/* ���: ��ܦ�C��� */
void printCList() {
   CList current = first;  /* �ثe����C���� */
   do {  /* ��ܥD�j�� */
      printf("[%d]", current->data);
      current = current->next;  /* �U�@�Ӹ`�I */
   } while ( current != first );
   printf("\n");
}
/* ���: �ˬd��C�O�_�O�Ū� */
int isCListEmpty() {
   if ( first == NULL ) return 1;
   else                 return 0;
}
/* ���: �j�M�`�I��� */
CList searchCNode(int d) {
   CList current = first;      /* �ثe����C���� */
   do {  /* �j�M�D�j�� */
      if ( current->data == d ) /* �O�_����� */
         return current;        /* ��� */
      current = current->next;  /* �U�@�Ӹ`�I */
   } while ( current != first && first != first->next );
   return NULL;                 /* �S����� */
}
/* ���: ���J�`�I */
void insertCNode(CList ptr, int d) { 
   CList previous, newnode;  
   /* �t�m�`�I�O���� */
   newnode = (CList) malloc(sizeof(CNode));
   newnode->data = d;
   if ( isCListEmpty() ) {        /* ��C�O�Ū� */
       first = newnode;           /* �Ĥ@�Ӹ`�I */
       first->next = newnode;     /* �U�@�ӫ��V�ۤv */
   }
   if ( ptr == NULL ) {
      /* ���p1: ���J�Ĥ@�Ӹ`�I�B������C�}�l */
      newnode->next = first;      /* �s�`�I������C�}�l */
      previous = first;
      /* ��X�̫�@�Ӹ`�I */
      while ( previous->next != first )
         previous = previous->next;/* �U�@�Ӹ`�I */
      previous->next = newnode;    /* ���V�s���Ĥ@�Ӹ`�I */
      first = newnode;             /* �s����C�}�l */
   }
   else {
      /* ���p2: ���b�`�I���� */
      newnode->next = ptr->next;   /* �s�`�I���V�U�@�`�I */
      ptr->next = newnode;         /* �`�Iptr���V�s�`�I */
   }
}
/* ���: �R���`�I */
int deleteCNode(CList ptr) {
   CList previous;                 /* �e�@�`�I���� */
   int value = ptr->data;          /* �`�I�� */
   if ( isCListEmpty() )           /* ��C�O�Ū� */
      return 0;
   previous = first;
   if ( first != first->next )     /* ��C�W�L�@�Ӹ`�I */
      while ( previous->next != ptr ) /* ��ptr�e�@�Ӹ`�I */
        previous = previous->next;    /* �U�@�Ӹ`�I */
   if ( ptr == first ) {              /* �p�G�O�Ĥ@�`�I */
      /* ���p1: �R����1�Ӹ`�I */
      first = first->next;            /* �U�@�Ӹ`�I */
      previous->next = ptr->next;  /* �e�`�I���V�U�@�`�I */
   }
   else
      /* ���p2: �R�������`�I */
      previous->next = ptr->next;  /* �e�`�I���V�U�@�`�I */
   free(ptr);                      /* ���^�`�I�O���� */
   return value;                   /* �Ǧ^�R�����`�I�� */
}
/*/ �D�{�� */
int main() {
   int temp;  /* �ŧi�ܼ� */
   int data[6] = { 4, 5, 6, 7, 8, 9 }; /* �إߦ�C���}�C */
   CList ptr;
   /* �إ�, ���X�P�j�M������C */
   createCList(6, data);   /* �إ�������C */
   printf("��Ӫ���C: ");
   printCList();  /* ��ܦ�C */
   printf("��C�O�_�Ū�: %d\n", isCListEmpty());
   temp = 0; 
   while ( temp != -1 ) {
      printf("�п�J�j�M���l�H�s��(-1����) ==> ");
      scanf("%d", &temp);  /* Ū���`�I�� */
      if ( temp != -1 )    /* �j�M�`�I��� */
         if ( searchCNode(temp) != NULL ) 
            printf("��C�]�t�`�I[%d]\n", temp);
         else
            printf("��C���t�`�I[%d]\n", temp);
   }      
   /* �`�I���J */
   temp = 0;
   insertCNode(NULL, 50); /* ���J�Ĥ@�Ӹ`�I */
   printf("���J���C: ");
   printCList();          /* ��ܴ��J���C */
   while ( temp != -1 ) {
      printf("�п�J���J��᪺�l�H�s��(-1����) ==> ");
      scanf("%d", &temp);   /* Ū���l�H�s�� */
      if ( temp != -1 ) {
         ptr = searchCNode(temp); /* ��M�`�I */
         if ( ptr != NULL ) 
            printf("�п�J�s���l�H�s��(0~100) ==> ");
            scanf("%d", &temp);  /* Ū���s���l�H�s�� */
            insertCNode(ptr, temp);
            printf("���J���C: ");
            printCList();          /* ��ܴ��J���C */
      } 
   }
   /* �`�I�R�� */
   temp = 0; 
   while ( temp != -1 ) {
      printf("�п�J�R�����l�H�s��(-1����) ==> ");
      scanf("%d", &temp);  /* Ū���l�H�s�� */
      if ( temp != -1 ) {  /* �j�M�`�I��� */
         ptr = searchCNode(temp);  /* ��M�`�I */
         if ( ptr != NULL ) {
            temp = deleteCNode(ptr); /* �R���`�I */
            printf("�R���`�I: %d\n", temp); 
            printf("�R�����C: ");
            printCList();        /* ��ܧR�����C */
         }         
      }
   }
   system("PAUSE");
   return 0; 
}
