/* 程式範例: Ch5-2-2.c */
#include <stdio.h>
#include <stdlib.h>
#include "Ch5-2-2.h"
/* 函數: 檢查堆疊是否是空的 */
int isStackEmpty() {
   if ( top == NULL ) return 1;
   else               return 0;
}
/* 函數: 將資料存入堆疊 */
void push(int d) {
   LStack new_node;            /* 新節點指標 */
   /* 配置節點記憶體 */
   new_node = (LStack)malloc(sizeof(SNode));
   new_node->data = d;         /* 建立節點內容 */
   new_node->next = top;       /* 新節點指向原開始 */
   top = new_node;             /* 新節點成為堆疊開始 */   
}
/* 函數: 從堆疊取出資料 */
int pop() {
   LStack ptr;                 /* 指向堆疊頂端 */
   int temp;
   if ( !isStackEmpty()  ) {   /* 堆疊是否是空的 */
      ptr = top;               /* 指向堆疊頂端 */
      top = top->next;         /* 堆疊指標指向下節點 */
      temp = ptr->data;        /* 取出資料 */
      free(ptr);               /* 釋回節點記憶體 */
      return temp;             /* 堆疊取出 */
   }
   else return -1;
}
/* 主程式 */
int main() {   
   int input[100], output[100]; /* 儲存輸入和取出元素 */
   int select = 1;              /* 選項 */
   int numOfInput  = 0;         /* 陣列的元素數 */
   int numOfOutput = 0;
   int i , temp;
   printf("鏈結串列的堆疊處理......\n");                
   while ( select != 3 ) {      /* 主迴圈 */
      printf("[1]存入 [2]取出 [3]顯示全部內容 ==> ");
      scanf("%d", &select);     /* 取得選項 */
      switch ( select ) {
         case 1: /* 將輸入值存入堆疊 */
            printf("請輸入存入值(%d) ==> ", numOfInput);
            scanf("%d", &temp); /* 取得存入值 */
            push(temp);
            input[numOfInput++] = temp;
            break;
         case 2: /* 取出堆疊的內容 */
            if ( !isStackEmpty() ) {
               temp = pop();
               printf("取出堆疊元素: %d\n", temp);
               output[numOfOutput++] = temp;
            }   
            break;
      }
   }
   printf("輸入堆疊的元素: ");    /* 輸入元素 */
   for ( i = 0; i < numOfInput; i++ )
      printf("[%d]", input[i]);
   printf("\n取出堆疊的元素: ");  /* 輸出元素 */
   for ( i = 0; i < numOfOutput; i++ )
      printf("[%d]", output[i]);
   printf("\n剩下堆疊的元素: ");  /* 取出剩下堆疊元素 */
   while ( !isStackEmpty() ) 
      printf("[%d]", pop()); 
   printf("\n");
   system("PAUSE");
   return 0; 
}
