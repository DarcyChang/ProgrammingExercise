/* 程式範例: Ch6-2-2.c */
#include <stdio.h>
#include <stdlib.h> 
#include "Ch6-2-2.h"
/* 函數: 檢查佇列是否是空的 */
int isQueueEmpty() {
   if ( front == NULL ) return 1;
   else                 return 0;
}
/* 函數: 將資料存入佇列 */
void enqueue(int d) {
   LQueue new_node;
   /* 配置節點記憶體 */
   new_node = (LQueue)malloc(sizeof(QNode));
   new_node->data = d;      /* 存入佇列節點 */
   new_node->next = NULL;   /* 設定初值 */
   if ( rear == NULL )      /* 是否是第一次存入 */
      front = new_node;     /* front指向new_node */
   else
      rear->next = new_node;/* 插入rear之後 */
   rear = new_node;         /* rear指向new_node */
}
/* 函數: 從佇列取出資料 */
int dequeue() {
   LQueue ptr;
   int temp;
   if ( !isQueueEmpty() ) {   /* 佇列是否是空的 */
      if ( front == rear )    /* 如果是最後一個節點 */
         rear = NULL;         
      ptr = front;            /* ptr指向front */
      front = front->next;    /* 刪除第1個節點 */
      temp = ptr->data;       /* 取得資料 */
      free(ptr);              /* 釋回記憶體 */
      return temp;            /* 傳回取出的資料 */
   }
   else return -1;            /* 佇列是空的 */
}
/* 主程式 */
int main() {   
   int input[100], output[100]; /* 儲存輸入和取出元素 */
   int select = 1;              /* 選項 */
   int numOfInput  = 0;         /* 陣列的元素數 */
   int numOfOutput = 0;
   int i, temp;
   printf("鏈結串列的佇列處理......\n");                 
   while ( select != 3 ) {       /* 主迴圈 */
      printf("[1]存入 [2]取出 [3]顯示全部內容 ==> ");
      scanf("%d", &select);      /* 取得選項 */
      switch ( select ) {
         case 1: /* 將輸入值存入佇列 */
            printf("請輸入存入值(%d) ==> ", numOfInput);
            scanf("%d", &temp);  /* 取得存入值 */
            enqueue(temp); 
            input[numOfInput++] = temp;
            break;
         case 2: /* 取出佇列的內容 */
            if ( !isQueueEmpty() ) {
               temp = dequeue();
               printf("取出佇列元素: %d\n", temp);
               output[numOfOutput++] = temp;
            }
            break;
      }
   }
   printf("輸入佇列的元素: ");    /* 輸入元素 */
   for ( i = 0; i < numOfInput; i++ )
      printf("[%d]", input[i]);
   printf("\n取出佇列的元素: ");  /* 輸出元素 */
   for ( i = 0; i < numOfOutput; i++ )
      printf("[%d]", output[i]);
   printf("\n剩下佇列的元素: ");  /* 取出剩下佇列元素 */
   while ( !isQueueEmpty() )
      printf("[%d]", dequeue()); 
   printf("\n");
   system("PAUSE");
   return 0; 
}
