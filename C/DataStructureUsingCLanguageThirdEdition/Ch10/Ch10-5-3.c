/* 程式範例: Ch10-5-3.c */
#include <stdio.h>
#include <stdlib.h>
#include "Ch10-5-3.h"
/* 函數: 雜湊函數 */
int hashFunc(int key) { return key % 10; }  /* 餘數 */
/* 函數: 建立雜湊表 */
void createHashTable(int len, int *array) {
   Table ptr;               /* 開始指標 */
   Table newnode;           /* 新節點指標 */
   int pos;                 /* 索引位置變數 */
   int i;
   for ( i = 0; i < MAX_LEN; i++ )
      hashTable[i].next = NULL;    /* 清除雜湊表 */
   /* 使用迴圈建立雜湊表 */
   for ( i = 0; i < len; i++ ) {
      /* 建立節點, 配置記憶體 */
      newnode = ( Table ) malloc(sizeof(struct Node));
      newnode->data = array[i];    /* 雜湊表鍵值 */
      newnode->next = NULL;        /* 指標的初值 */
      /* 呼叫雜湊函數計算索引位置 */
      pos = hashFunc(array[i]);
      ptr = hashTable[pos].next;   /* 取得開始指標 */
      if ( ptr != NULL ) {         /* 是否是第1個節點 */
         while ( ptr->next!=NULL ) /* 找出最後1個節點 */
            ptr= ptr->next;        /* 下一個節點 */
         ptr->next = newnode; /* 鏈結節點 */
      } else
         hashTable[pos].next = newnode; /* 第1個節點 */      
   }   
}
/* 函數: 鏈結法的雜湊搜尋 */
int chainHashSearch(int key) {
   Table ptr;               /* 開始指標 */
   int pos;                 /* 位置變數 */
   /* 呼叫雜湊函數計算位置 */
   pos = hashFunc(key);
   ptr = hashTable[pos].next;   /* 取得開始指標 */
   while ( ptr != NULL )        /* 鏈結法的搜尋迴圈 */
      if ( ptr->data == key )   /* 是否找到了 */
         return 1;
      else
         ptr = ptr->next;       /* 下一個節點 */
   return 0;
}
/* 函數: 顯示雜湊表的內容 */
void printHashTable() {
   Table ptr;               /* 開始指標 */
   int i;
   printf("雜湊表內容: ");
   for ( i = 0; i < MAX_LEN; i++ ) { 
      printf("\n%2d ==> ",i);
      ptr = hashTable[i].next;  /* 取得開始指標 */
      while ( ptr != NULL ) {   /* 顯示串列的迴圈 */
         printf("[%2d]", ptr->data);  /* 顯示鍵值 */
         ptr = ptr->next;       /* 下一個節點 */
      }
   }
   printf("\n"); 
}
/* 主程式 */ 
int main() {
   /* 搜尋的鍵值資料 */
   int data[8]={37, 25, 11, 29, 34, 46, 44, 35};
   int target;
   createHashTable(8, data);  /* 建立雜湊表 */ 
   printHashTable();          /* 顯示雜湊表 */
   target = 0;
   while ( target != -1 ) {
      printf("請輸入搜尋值(-1結束) ==> ");
      scanf("%d", &target);
      /* 呼叫鏈結法的雜湊搜尋函數 */
      if ( chainHashSearch(target) )
          printf("搜尋到鍵值: %d\n", target);
      else
          printf("沒有搜尋到鍵值: %d\n", target);
   }
   system("PAUSE");
   return 0; 
}
