/* 程式範例: Ch4-4.c */
#include <stdio.h>
#include <stdlib.h>
struct Node {         /* Node節點結構 */
   int data;          /* 結構變數宣告 */ 
   struct Node *next; /* 指向下一個節點 */
};
typedef struct Node CNode;   /* 環狀串列節點的新型態 */
typedef CNode *CList;        /* 環狀串列的新型態 */
CList first = NULL;          /* 環狀串列的開頭指標 */
/* 函數: 建立環狀串列 */
void createCList(int len, int *array) {
   CList last;    /* 最後一個節點的指標 */
   CList newnode;
   int i;
   for ( i = 0; i < len; i++ ) {
      /* 配置節點記憶體 */
      newnode = (CList) malloc(sizeof(CNode));
      newnode->data = array[i]; /* 建立節點內容 */
      if ( i == 0 ) last = newnode; /* 指向最後一個節點 */
      newnode->next = first;
      first = newnode;
   }
   last->next = first;   /* 連結第1個節點, 建立環狀串列 */
}
/* 函數: 顯示串列資料 */
void printCList() {
   CList current = first;  /* 目前的串列指標 */
   do {  /* 顯示主迴圈 */
      printf("[%d]", current->data);
      current = current->next;  /* 下一個節點 */
   } while ( current != first );
   printf("\n");
}
/* 函數: 檢查串列是否是空的 */
int isCListEmpty() {
   if ( first == NULL ) return 1;
   else                 return 0;
}
/* 函數: 搜尋節點資料 */
CList searchCNode(int d) {
   CList current = first;      /* 目前的串列指標 */
   do {  /* 搜尋主迴圈 */
      if ( current->data == d ) /* 是否找到資料 */
         return current;        /* 找到 */
      current = current->next;  /* 下一個節點 */
   } while ( current != first && first != first->next );
   return NULL;                 /* 沒有找到 */
}
/* 函數: 插入節點 */
void insertCNode(CList ptr, int d) { 
   CList previous, newnode;  
   /* 配置節點記憶體 */
   newnode = (CList) malloc(sizeof(CNode));
   newnode->data = d;
   if ( isCListEmpty() ) {        /* 串列是空的 */
       first = newnode;           /* 第一個節點 */
       first->next = newnode;     /* 下一個指向自己 */
   }
   if ( ptr == NULL ) {
      /* 情況1: 插入第一個節點且成為串列開始 */
      newnode->next = first;      /* 新節點成為串列開始 */
      previous = first;
      /* 找出最後一個節點 */
      while ( previous->next != first )
         previous = previous->next;/* 下一個節點 */
      previous->next = newnode;    /* 指向新的第一個節點 */
      first = newnode;             /* 新的串列開始 */
   }
   else {
      /* 情況2: 插在節點之後 */
      newnode->next = ptr->next;   /* 新節點指向下一節點 */
      ptr->next = newnode;         /* 節點ptr指向新節點 */
   }
}
/* 函數: 刪除節點 */
int deleteCNode(CList ptr) {
   CList previous;                 /* 前一節點指標 */
   int value = ptr->data;          /* 節點值 */
   if ( isCListEmpty() )           /* 串列是空的 */
      return 0;
   previous = first;
   if ( first != first->next )     /* 串列超過一個節點 */
      while ( previous->next != ptr ) /* 找ptr前一個節點 */
        previous = previous->next;    /* 下一個節點 */
   if ( ptr == first ) {              /* 如果是第一節點 */
      /* 情況1: 刪除第1個節點 */
      first = first->next;            /* 下一個節點 */
      previous->next = ptr->next;  /* 前節點指向下一節點 */
   }
   else
      /* 情況2: 刪除中間節點 */
      previous->next = ptr->next;  /* 前節點指向下一節點 */
   free(ptr);                      /* 釋回節點記憶體 */
   return value;                   /* 傳回刪除的節點值 */
}
/*/ 主程式 */
int main() {
   int temp;  /* 宣告變數 */
   int data[6] = { 4, 5, 6, 7, 8, 9 }; /* 建立串列的陣列 */
   CList ptr;
   /* 建立, 走訪與搜尋環狀串列 */
   createCList(6, data);   /* 建立環狀串列 */
   printf("原來的串列: ");
   printCList();  /* 顯示串列 */
   printf("串列是否空的: %d\n", isCListEmpty());
   temp = 0; 
   while ( temp != -1 ) {
      printf("請輸入搜尋的郵寄編號(-1結束) ==> ");
      scanf("%d", &temp);  /* 讀取節點值 */
      if ( temp != -1 )    /* 搜尋節點資料 */
         if ( searchCNode(temp) != NULL ) 
            printf("串列包含節點[%d]\n", temp);
         else
            printf("串列不含節點[%d]\n", temp);
   }      
   /* 節點插入 */
   temp = 0;
   insertCNode(NULL, 50); /* 插入第一個節點 */
   printf("插入後串列: ");
   printCList();          /* 顯示插入後串列 */
   while ( temp != -1 ) {
      printf("請輸入插入其後的郵寄編號(-1結束) ==> ");
      scanf("%d", &temp);   /* 讀取郵寄編號 */
      if ( temp != -1 ) {
         ptr = searchCNode(temp); /* 找尋節點 */
         if ( ptr != NULL ) 
            printf("請輸入新的郵寄編號(0~100) ==> ");
            scanf("%d", &temp);  /* 讀取新的郵寄編號 */
            insertCNode(ptr, temp);
            printf("插入後串列: ");
            printCList();          /* 顯示插入後串列 */
      } 
   }
   /* 節點刪除 */
   temp = 0; 
   while ( temp != -1 ) {
      printf("請輸入刪除的郵寄編號(-1結束) ==> ");
      scanf("%d", &temp);  /* 讀取郵寄編號 */
      if ( temp != -1 ) {  /* 搜尋節點資料 */
         ptr = searchCNode(temp);  /* 找尋節點 */
         if ( ptr != NULL ) {
            temp = deleteCNode(ptr); /* 刪除節點 */
            printf("刪除節點: %d\n", temp); 
            printf("刪除後串列: ");
            printCList();        /* 顯示刪除後串列 */
         }         
      }
   }
   system("PAUSE");
   return 0; 
}
