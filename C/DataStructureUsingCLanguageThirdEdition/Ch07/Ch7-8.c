/* �{���d��: Ch7-8.c */
#include <stdio.h>
#include <stdlib.h>
#include "Ch7-5.h"
#include "createBSTree.c"
/* �G���𪺰}�C��ܪk�ഫ���쵲��ܪk */
BSTree transformBSTree(int len, int *array, int pos) {
   BSTree newnode;            /* �s�`�I���� */
   if ( array[pos] == 0 || pos >= len )  /* �פ���� */
      return NULL;
   else  {/* �إ߷s�`�I�O���� */
      newnode = ( BSTree )malloc(sizeof(TNode));
      newnode->data = array[pos]; /* �إ߸`�I���e */
      /* �إߥ��l�𪺻��j�I�s */
      newnode->left=transformBSTree(len,array, 2*pos);
      /* �إߥk�l�𪺻��j�I�s */
      newnode->right=transformBSTree(len,array,2*pos+1);
      return newnode;
   }
}
/* �p��G���B�⦡�����G */
int cal(int op,int operand1,int operand2) {
   switch ( (char) op ) {
      case '*': return ( operand2 * operand1 ); /* �� */
      case '/': return ( operand2 / operand1 ); /* �� */
      case '+': return ( operand2 + operand1 ); /* �[ */
      case '-': return ( operand2 - operand1 ); /* �� */
   }
}
/* �p��G����B�⦡���� */
int eval(BSTree ptr) {
   int operand1 = 0;       /* ��1�ӹB�⤸�ܼ� */
   int operand2 = 0;       /* ��2�ӹB�⤸�ܼ� */
   /* �פ���� */
   if ( ptr->left == NULL && ptr->right == NULL )
      return ptr->data-48; /* �Ǧ^���`�I���� */ 
   else {
      operand1 = eval(ptr->left);  /* ���l�� */
      operand2 = eval(ptr->right); /* �k�l�� */
      return cal(ptr->data, operand1, operand2);
   }
}
/* �D�{�� */
int main() {
   /* �B�⦡�G����`�I��� */
   int data[8] = {' ','+','*','*','5','6','4','3' };
   head = transformBSTree(8, data, 1);/* �ഫ�G���� */
   printf("���ǹB�⦡(���Ǩ��X): ");
   inOrder(head, "%c");           /* ������ܤG���� */
   printf("\n�e�ǹB�⦡(�e�Ǩ��X): ");
   preOrder(head, "%c");          /* �e����ܤG���� */
   printf("\n��ǹB�⦡(��Ǩ��X): ");
   postOrder(head, "%c");         /* �����ܤG���� */
   printf("\n�B�⦡��= %d\n", eval(head));/* �p�⵲�G */
   system("PAUSE");
   return 0;    
}
