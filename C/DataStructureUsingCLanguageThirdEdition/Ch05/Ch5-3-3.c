/* 程式範例: Ch5-3-3.c */
#include <stdio.h>
#include <stdlib.h>
#include "stack.c"
/* 是否是運算子 */
int isOperator(char op) {
   switch ( op ) {
      case '(':
      case ')':
      case '+':
      case '-':
      case '*':
      case '/': return 1;      /* 是運算子 */
      default:  return 0;      /* 不是運算子 */
   }
}
/* 運算子的優先權 */
int priority(char op) {
   switch ( op ) {    /* 傳回值愈大, 優先權愈大 */
      case '*':
      case '/': return 3;
      case '+':
      case '-': return 2;
      case '(': return 1;
      default:  return 0;
   }
}
/* 中序轉後序運算式 */
void postfix(char *infix) {
   int op, doit;                  /* 運算子和旗標變數 */
   int pos = 0;                   /* 運算式字串的索引 */
   /* 剖析運算式字串迴圈 */
   while ( infix[pos] != '\0' && infix[pos] != '\n' ) {
      if ( isOperator(infix[pos]) ) { /* 是運算子 */
         if ( isStackEmpty() || 
              infix[pos] == '(' )    /* 將運算子存入堆疊 */
                 push(infix[pos]);
         else if ( infix[pos] == ')' ) { /* 處理括號 */
               doit = 1;
               while ( doit ) {
                  /* 取出運算子直到是'(' */
                  op = pop();
                  if ( op != '(' )
                     printf("%c", op);  /* 顯示運算子 */
                  else 
                  doit = 0;
               }
            }
            else {  /* 比較優先順序 */
               doit = 1;
               while ( doit &&  /* 比較優先順序的迴圈 */
                 !isStackEmpty()) {
                 op = pop();  /* 取出運算子 */
                 if (priority(infix[pos])<=priority(op))
                    printf("%c", op);   /* 顯示運算子 */
                 else {
                    push(op);  /* 存回運算子 */
                    doit = 0;
                 }   
               } /* 將運算子存入堆疊 */
               push(infix[pos]);
            }
      } else  printf("%c", infix[pos]);   /* 顯示運算元 */
      pos++;
   }  /* 取出剩下的運算子 */
   while ( !isStackEmpty() ) 
      printf("%c", pop());    /* 顯示運算子 */
   printf("\n"); 
}
/* 主程式 */
int main() {   
   char exp[100];              /* 運算式的字串變數 */
   printf("請輸入中序運算式 ==> ");
   gets(exp);         /* 讀取運算式 */
   printf("後序運算式: ");
   postfix(exp);      /* 顯示結果 */
   system("PAUSE");
   return 0; 
}
