/* 程式範例: Ch10-5-1.c */
#include <stdio.h>
#include <stdlib.h>
#include "Ch10-5-1.h"
/* 函數: 雜湊函數 */
int hashFunc(int key) { return key % 10; }  /* 餘數 */
/* 函數: 建立雜湊表 */
void createHashTable(int len, int *array) {
   int pos;                 /* 索引位置變數 */
   int temp, i;
   for ( i = 0; i < MAX_LEN; i++ )
      hashTable[i] = -1;    /* 清除雜湊表 */
   /* 使用迴圈建立雜湊表 */
   for ( i = 0; i < len; i++ ) {
      /* 呼叫雜湊函數計算索引位置 */
      pos = hashFunc(array[i]);
      temp = pos;           /* 保留開始的索引位置 */
      while ( hashTable[temp] != -1 ) { /* 找尋位置 */
         temp = ( temp + 1 ) % MAX_LEN; /* 下一個位置 */
         if ( pos == temp ) {       /* 雜湊表是否己滿 */
            printf("雜湊表己滿!\n");
            return;
         }
      }
      hashTable[temp] = array[i];   /* 存入雜湊表 */
   }   
}
/* 函數: 線性探測法的雜湊搜尋 */
int lineHashSearch(int key) {
   int pos;                 /* 位置變數 */
   int temp;
   /* 呼叫雜湊函數計算位置 */
   pos = hashFunc(key);
   temp = pos;              /* 保留開始的索引位置 */
   while ( hashTable[temp] != key && /* 線性探測迴圈 */
           hashTable[temp] != -1 ) {
      /* 使用餘數將陣列變為環狀 */
      temp = ( temp + 1 ) % MAX_LEN;/* 下一個位置 */
      if ( pos == temp )            /* 查詢結束 */
         return -1;                 /* 已滿沒有找到 */
   }
   if ( hashTable[temp] == -1 )  /* 是否是空白 */
      return -1;                 /* 沒有找到 */
   else
      return temp;               /* 找到了 */
}
/* 函數: 顯示雜湊表的內容 */
void printHashTable() {
   int i;
   for ( i = 0; i < MAX_LEN; i++ )  /* 顯示雜湊表 */
       printf("[%2d]", hashTable[i]);
   printf("\n");
}
/* 主程式 */ 
int main() {
   /* 搜尋的鍵值資料 */
   int data[8]={37, 25, 11, 29, 34, 46, 44, 35};
   int target, index;
   createHashTable(8, data);  /* 建立雜湊表 */ 
   printf("雜湊表內容: ");
   printHashTable();          /* 顯示雜湊表 */
   target = 0;
   while ( target != -1 ) {
      printf("請輸入搜尋值(-1結束) ==> ");
      scanf("%d", &target);
      /* 呼叫線性探測法的雜湊搜尋函數 */
      index = lineHashSearch(target);
      if (index != -1)
          printf("搜尋到鍵值: %d(%d)\n", target, index);
      else
          printf("沒有搜尋到鍵值: %d\n", target);
   }
   system("PAUSE");
   return 0; 
}
