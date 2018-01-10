/* �{���d��: Ch5-3-3.c */
#include <stdio.h>
#include <stdlib.h>
#include "stack.c"
/* �O�_�O�B��l */
int isOperator(char op) {
   switch ( op ) {
      case '(':
      case ')':
      case '+':
      case '-':
      case '*':
      case '/': return 1;      /* �O�B��l */
      default:  return 0;      /* ���O�B��l */
   }
}
/* �B��l���u���v */
int priority(char op) {
   switch ( op ) {    /* �Ǧ^�ȷU�j, �u���v�U�j */
      case '*':
      case '/': return 3;
      case '+':
      case '-': return 2;
      case '(': return 1;
      default:  return 0;
   }
}
/* �������ǹB�⦡ */
void postfix(char *infix) {
   int op, doit;                  /* �B��l�M�X���ܼ� */
   int pos = 0;                   /* �B�⦡�r�ꪺ���� */
   /* ��R�B�⦡�r��j�� */
   while ( infix[pos] != '\0' && infix[pos] != '\n' ) {
      if ( isOperator(infix[pos]) ) { /* �O�B��l */
         if ( isStackEmpty() || 
              infix[pos] == '(' )    /* �N�B��l�s�J���| */
                 push(infix[pos]);
         else if ( infix[pos] == ')' ) { /* �B�z�A�� */
               doit = 1;
               while ( doit ) {
                  /* ���X�B��l����O'(' */
                  op = pop();
                  if ( op != '(' )
                     printf("%c", op);  /* ��ܹB��l */
                  else 
                  doit = 0;
               }
            }
            else {  /* ����u������ */
               doit = 1;
               while ( doit &&  /* ����u�����Ǫ��j�� */
                 !isStackEmpty()) {
                 op = pop();  /* ���X�B��l */
                 if (priority(infix[pos])<=priority(op))
                    printf("%c", op);   /* ��ܹB��l */
                 else {
                    push(op);  /* �s�^�B��l */
                    doit = 0;
                 }   
               } /* �N�B��l�s�J���| */
               push(infix[pos]);
            }
      } else  printf("%c", infix[pos]);   /* ��ܹB�⤸ */
      pos++;
   }  /* ���X�ѤU���B��l */
   while ( !isStackEmpty() ) 
      printf("%c", pop());    /* ��ܹB��l */
   printf("\n"); 
}
/* �D�{�� */
int main() {   
   char exp[100];              /* �B�⦡���r���ܼ� */
   printf("�п�J���ǹB�⦡ ==> ");
   gets(exp);         /* Ū���B�⦡ */
   printf("��ǹB�⦡: ");
   postfix(exp);      /* ��ܵ��G */
   system("PAUSE");
   return 0; 
}
