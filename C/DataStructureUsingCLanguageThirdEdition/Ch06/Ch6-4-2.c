/* 程式範例: Ch6-4-2.c */
#include <stdio.h>
#include <stdlib.h> 
#include "Ch6-4-2.h" 
/* 函數: 檢查佇列是否是空的 */
int isDequeEmpty() {
   if ( front == NULL ) return 1;
   else                 return 0;
}
/* 函數: 將資料存入佇列 (從尾端) */
void endeque_rear(int d) {
   LDeque new_node;
   /* 配置節點記憶體 */
   new_node = (LDeque)malloc(sizeof(QNode));
   new_node->data = d;      /* 存入佇列節點 */
   new_node->next = NULL;   /* 設定初值 */
   if ( rear == NULL )      /* 是否是第一次存入 */
      front = new_node;     /* front指向new_node */
   else
      rear->next = new_node;/* 插入rear之後 */
   rear = new_node;         /* rear指向new_node */
}
/* 函數: 將資料存入佇列 (從前端) */
void endeque_front(int d) {
   LDeque new_node;
   /* 配置節點記憶體 */
   new_node = (LDeque)malloc(sizeof(QNode));
   new_node->data = d;       /* 存入佇列節點 */
   if ( front == NULL ) {    /* 是否是第一次存入 */
      new_node->next = NULL; /* 設定初值 */
      rear = new_node;       /* rear指向new_node */
   } else
      new_node->next = front;/* 插入front之前 */
   front = new_node;         /* front指向new_node */
}
/* 函數: 從佇列取出資料 */
int dedeque() {
   LDeque ptr;
   int temp;
   if ( !isDequeEmpty() ) {   /* 佇列是否是空的 */
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
   int input[6] =  { 1, 2, 3, 4, 5, 6 }; /* 輸入元素 */
   int i, select;                        /* 選擇項 */
   for ( i = 0; i < 6; i++ ) {    /* 存入佇列 */
      printf("[1]從後存入 [2]從前存入 ==> ");
      scanf("%d", &select);       /* 讀入選項 */
      switch ( select ) {
         case 1: /* 從尾端存入佇列內容 */
            endeque_rear(input[i]);
            break;
         case 2: /* 從前端存入佇列內容 */
            endeque_front(input[i]);
            break;
      }
   }
   printf("存入的元素順序: ");  /* 顯示輸入陣列內容 */
   for ( i = 0; i < 6; i++ )
      printf("[%d]", input[i]);
   printf("\n佇列取出的順序: ");
   while ( !isDequeEmpty() )    /* 取出剩下的佇列元素 */
      printf("[%d]", dedeque());
   printf("\n");
   system("PAUSE");
   return 0; 
}
