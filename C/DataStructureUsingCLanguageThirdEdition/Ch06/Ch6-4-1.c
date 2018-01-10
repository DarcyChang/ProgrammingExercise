/* 程式範例: Ch6-4-1.c */
#include <stdio.h>
#include <stdlib.h>
#include "Ch6-4-1.h"
/* 函數: 檢查雙佇列是否是空的 */
int isDequeEmpty() {
   if ( front == rear ) return 1;
   else                 return 0;
}
/* 函數: 檢查雙佇列是否已滿 */
int isDequeFull() {
   int pos;
   pos = ( rear+1 == MAXQUEUE ) ? 0 : rear+1;
   if ( front == pos  ) return 1;
   else                 return 0;
}
/* 函數: 將資料存入佇列 */
int endeque(int d) {
   if ( isDequeFull() )          /* 檢查是否已滿 */
      return 0;                  /* 已滿, 無法存入 */
   else { /* 是否超過,重新定位 */
      rear = ( rear+1 == MAXQUEUE ) ? 0 : rear+1;
      deque[rear] = d;
   }   
   return 1;
}
/* 函數: 從佇列(尾端)取出資料 */
int dedeque_rear() {
   int temp;
   if ( isDequeEmpty() )         /* 檢查佇列是否是空 */
      return -1;                 /* 無法取出 */
   temp = deque[rear];
   rear--;                       /* 尾端指標往前移 */
   /* 是否超過陣列邊界 */
   if ( rear < 0 )
      rear = MAXQUEUE - 1;       /* 從最大值開始 */
   return temp;                  /* 傳回佇列取出元素 */
}
/* 函數: 從佇列(前端)取出資料 */
int dedeque_front() {
   if ( isDequeEmpty() )         /* 檢查佇列是否是空 */
      return -1;                 /* 無法取出 */
   /* 是否超過,重新定位 */   
   front = ( front+1 == MAXQUEUE ) ? 0 : front+1; 
   return deque[front];          /* 傳回佇列取出元素 */
}
/* 主程式 */
int main() {   
   int input[6] =  { 1, 2, 3, 4, 5, 6 }; /* 輸入元素 */
   int output[6];                        /* 取出元素 */
   int select;                           /* 選擇項 */
   int i, temp, pos = 0;
   for ( i = 0; i < 6; i++ )   /* 將陣列元素存入佇列 */
      endeque(input[i]);
   printf("輸入限制性雙佇列的處理......\n");   
   while ( !isDequeEmpty() ) {   /* 主迴圈 */
      printf("[1]從後取出 [2]從前取出 ==> ");
      scanf("%d", &select);       /* 取得選項 */
      switch ( select ) {
         case 1:  /* 從尾端取出佇列內容 */
            temp = dedeque_rear();
            output[pos++] = temp;
            break;
         case 2:  /* 從前端取出佇列內容 */
            temp = dedeque_front();
            output[pos++] = temp;
            break;
      }
   }
   printf("存入佇列的順序: ");   /* 顯示輸入陣列內容 */
   for ( i = 0; i < 6; i++ )
      printf("[%d]", input[i]);
   printf("\n佇列取出的順序: "); /* 顯示取出陣列內容 */
   for ( i = 0; i < 6; i++ )
      printf("[%d]", output[i]);  
   printf("\n");
   system("PAUSE");
   return 0; 
}
