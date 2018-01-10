/* �{���d��: Ch5-3-2.c */
#include <stdio.h>
#include <stdlib.h>
#include "stack.c"
/* �O�_�O�B��l */
int isOperator(char op) {
   switch ( op ) {
      case '+':
      case '-':
      case '*':
      case '/': return 1;      /* �O�B��l */
      default:  return 0;      /* ���O�B��l */
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
/* ��ǹB�⦡���p�� */
int postfixEval(char *exp) {
   int operand1 = 0;              /* ��1�ӹB�⤸�ܼ� */
   int operand2 = 0;              /* ��2�ӹB�⤸�ܼ� */
   int pos = 0;                   /* �B�⦡�r����� */
   /* ��R�B�⦡�r��j�� */
   while ( exp[pos] != '\0' && exp[pos] != '\n' ) {
      if ( isOperator(exp[pos]) ) {  /* �O���O�B��l */
         /* �q���|���X��ӹB�⤸ */
         operand1 = pop();
         operand2 = pop();
         /* �p�⵲�G�s�^���| */
         push(cal(exp[pos],operand2,operand1));
      }
      else  /* �o�O�B�⤸, �s�J�B�⤸���| */
         push(exp[pos]-48);
      pos++;               /* �U�@�Ӧr�� */
   } 
   return pop();   /* �Ǧ^��ǹB�⦡�����G */
}
/* �D�{�� */
int main() {   
   char exp[100];                 /* �B�⦡���r���ܼ� */
   printf("�п�J��ǹB�⦡ ==> ");
   gets(exp);     /* Ū���B�⦡ */
   printf("�B�⦡: %s = %d\n", exp, postfixEval(exp));
   system("PAUSE");
   return 0; 
}
