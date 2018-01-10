/* 程式範例: Ch10-3-2.c */
#include <stdio.h>
#include <stdlib.h>
#define MAX_LEN      12          /* 最大的陣列尺寸 */
/*  函數: 計算費氏數 */
int fib(int n) {
   if ( n <= 1 )                 /* N 是否小於壹 */
      if ( n == 0 ) return 0;    /* 傳回0 */
      else          return 1;    /* 傳回1 */
   else
      return fib(n-2) + fib(n-1);/* 遞迴計算費氏數 */
}
/* 函數: 計算費氏數列的 k 值當 Fk+1 >= n + 1 */
int fibindex(int n, int *m) {
   int k = 0;                    /* 指定k值 */
   while ( fib(k) < n + 1 )      /* 比較迴圈 */
      k++;                       /* 如果成立k加一 */
   if ( fib(k) != n + 1 )        /* 不是費氏數 */ 
      *m = fib(k)-(n+1);         /* 計算m值 */ 
   return k - 1;                 /* 傳回k */
}
/* 函數: 費氏搜尋法 */
int fibsearch(int *data, int n, int key) {
   int k, m = 0;                 /* 階層值k與m */
   int mid;                      /* 費氏樹根節點 */
   int fn1, fn2, temp;
   k = fibindex(n, &m);          /* 計算k與m值 */
   mid = fib(k);                 /* 根節點的費氏數 */
   fn1 = fib(k - 1);             /* 前一個費氏數 */
   fn2 = fib(k - 2);             /* 前二個費氏數 */
   while ( mid != 0 ) {          /* 費氏搜尋主迴圈 */
      if ( key < data[mid-1-m] ) /* 比較小 */
         if ( fn2 <= 0 ) mid = 0;/* 沒有找到 */
         else {
            mid = mid - fn2;     /* 左子樹的新費氏數 */
            temp = fn1;          /* 計算k-1的差值fn2 */
            fn1 = fn2;           
            fn2 = temp - fn2;    
         }
         else if ( key > data[mid-1-m] ) /* 比較大 */
            if ( fn1 <= 0 ) mid = 0; /* 沒有找到 */
            else {
               mid = mid + fn2;  /* 右子樹的新費氏數 */
               fn1 = fn1 - fn2;  /* 計算k-2的差值fn2 */
               fn2 = fn2 - fn1;  
            }
            else
               return mid-1-m;   /* 找到了 */
   }
   return -1;                    /* 沒有找到 */
}
/* 主程式 */ 
int main() {
   int data[MAX_LEN] = {         /* 搜尋的陣列 */
        12,   15,  17,  19,  27,  31,
        35,   43,  46,  77,  80,  95 };
   int i, index, target, c;
   printf("原始陣列: "); 
   for ( i = 0; i < MAX_LEN; i++ )
       printf("[%d]", data[i]); /* 顯示陣列元素 */
   printf("\n");
   target = 0;
   while ( target != -1 ) {
      printf("請輸入搜尋值(-1結束) ==> ");
      scanf("%d", &target);
      /* 呼叫費氏搜尋法的搜尋函數 */ 
      index = fibsearch(data, MAX_LEN, target);
      if (index != -1)
          printf("搜尋到鍵值: %d(%d)\n", target, index);
      else
          printf("沒有搜尋到鍵值: %d\n", target);
   }
   system("PAUSE");
   return 0;  
}
