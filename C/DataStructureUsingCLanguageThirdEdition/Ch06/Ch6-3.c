/* 程式範例: Ch6-3.c */
#include <stdio.h>
#include <stdlib.h>
#include "Ch6-3.h"
/* 函數: 檢查佇列是否是空的 */
int isQueueEmpty() {
   if ( front == rear ) return 1;
   else                 return 0;
}
/* 函數: 檢查佇列是否已滿 */
int isQueueFull() {
   int pos;
   pos = (rear+1) % MAXQUEUE;
   if ( front == pos ) return 1;
   else                return 0;
}
/* 函數: 將資料存入佇列 */
int enqueue(int d) {
   if ( isQueueFull() )          /* 檢查是否已滿 */
      return 0;                  /* 已滿, 無法存入 */
   else {
      rear = (rear+1) % MAXQUEUE;/* 是否超過,重新定位 */
      queue[rear] = d;
   }   
   return 1;
}
/* 函數: 從佇列取出資料 */
int dequeue() {
   if ( isQueueEmpty() )         /* 檢查佇列是否是空 */
      return -1;                 /* 無法取出 */
   front = (front+1) % MAXQUEUE; /* 是否超過,重新定位 */
   return queue[front];          /* 傳回佇列取出元素 */
}
/* 主程式 */
int main() {
   int input[100], output[100]; /* 儲存輸入和取出元素 */
   int select = 1;              /* 選項 */
   int numOfInput  = 0;         /* 陣列的元素數 */
   int numOfOutput = 0;
   int i, temp;
   printf("環狀佇列處理......\n");                 
   while ( select != 3 ) {       /* 主迴圈 */
      printf("[1]存入 [2]取出 [3]顯示全部內容 ==> ");
      scanf("%d", &select);      /* 取得選項 */
      switch ( select ) {
         case 1: /* 將輸入值存入佇列 */
            printf("請輸入存入值(%d) ==> ", numOfInput);
            scanf("%d", &temp);  /* 取得存入值 */
            if (enqueue(temp)) 
                input[numOfInput++] = temp;
            else
                printf("佇列已滿!\n");
            break;
         case 2: /* 取出佇列的內容 */
            if ( !isQueueEmpty() ) {
               temp = dequeue();
               printf("取出佇列元素: %d\n", temp);
               output[numOfOutput++] = temp;
            }
            else
               printf("佇列已空!\n");
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
