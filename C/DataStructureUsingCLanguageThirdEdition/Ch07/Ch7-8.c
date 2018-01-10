/* 程式範例: Ch7-8.c */
#include <stdio.h>
#include <stdlib.h>
#include "Ch7-5.h"
#include "createBSTree.c"
/* 二元樹的陣列表示法轉換成鏈結表示法 */
BSTree transformBSTree(int len, int *array, int pos) {
   BSTree newnode;            /* 新節點指標 */
   if ( array[pos] == 0 || pos >= len )  /* 終止條件 */
      return NULL;
   else  {/* 建立新節點記憶體 */
      newnode = ( BSTree )malloc(sizeof(TNode));
      newnode->data = array[pos]; /* 建立節點內容 */
      /* 建立左子樹的遞迴呼叫 */
      newnode->left=transformBSTree(len,array, 2*pos);
      /* 建立右子樹的遞迴呼叫 */
      newnode->right=transformBSTree(len,array,2*pos+1);
      return newnode;
   }
}
/* 計算二元運算式的結果 */
int cal(int op,int operand1,int operand2) {
   switch ( (char) op ) {
      case '*': return ( operand2 * operand1 ); /* 乘 */
      case '/': return ( operand2 / operand1 ); /* 除 */
      case '+': return ( operand2 + operand1 ); /* 加 */
      case '-': return ( operand2 - operand1 ); /* 減 */
   }
}
/* 計算二元樹運算式的值 */
int eval(BSTree ptr) {
   int operand1 = 0;       /* 第1個運算元變數 */
   int operand2 = 0;       /* 第2個運算元變數 */
   /* 終止條件 */
   if ( ptr->left == NULL && ptr->right == NULL )
      return ptr->data-48; /* 傳回葉節點的值 */ 
   else {
      operand1 = eval(ptr->left);  /* 左子樹 */
      operand2 = eval(ptr->right); /* 右子樹 */
      return cal(ptr->data, operand1, operand2);
   }
}
/* 主程式 */
int main() {
   /* 運算式二元樹節點資料 */
   int data[8] = {' ','+','*','*','5','6','4','3' };
   head = transformBSTree(8, data, 1);/* 轉換二元樹 */
   printf("中序運算式(中序走訪): ");
   inOrder(head, "%c");           /* 中序顯示二元樹 */
   printf("\n前序運算式(前序走訪): ");
   preOrder(head, "%c");          /* 前序顯示二元樹 */
   printf("\n後序運算式(後序走訪): ");
   postOrder(head, "%c");         /* 後序顯示二元樹 */
   printf("\n運算式值= %d\n", eval(head));/* 計算結果 */
   system("PAUSE");
   return 0;    
}
