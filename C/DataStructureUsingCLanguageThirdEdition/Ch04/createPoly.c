/* 程式範例: createPoly.c */
/* 函數: 建立多項式的串列 */
PList createPoly(int len, float *array) {
   int i;
   PList first, ptr, newnode;   /* 建立開頭節點 */
   first = (PList) malloc(sizeof(PNode));
   first->coef = 0.0;    /* 建立開頭節點的內容 */
   first->exp = -1;  
   ptr = first;          /* 前一個節點指標 */
   for ( i = len-1; i >= 0; i-- ) {
      if ( array[i] != 0.0 ) {    /* 配置節點記憶體 */
         newnode = (PList) malloc(sizeof(PNode));
         newnode->coef = array[i]; /* 建立節點的內容 */
         newnode->exp = i;         
         ptr->next = newnode;     /* 連結新節點 */ 
         ptr = newnode;           /* 成為前一個節點 */ 
      }   
   }
   ptr->next = first;  /* 連結第1個節點, 建立環狀串列 */
   return first;
}
/* 函數: 顯示多項式 */
void printPoly(PList first) {
   PList ptr = first->next;  /* 串列真正的開頭 */
   float c;
   int e;
   while ( ptr != first ) {  /* 顯示主迴圈 */
      c = ptr->coef;
      e = ptr->exp;
      printf("%3.1fX^%d", c, e);
      ptr = ptr->next;       /* 下一個節點 */
      if ( ptr != first ) printf("+");
   }
   printf("\n");   
}
