/* 程式範例: adjacencyList.c */
#define MAX_VERTICES   10       /* 圖形的最大頂點數 */
struct Vertex {                 /* 圖形頂點結構宣告 */
   int data;                    /* 頂點資料 */
   int weight;                  /* 權值 */ 
   struct Vertex *next;         /* 指下一個頂點的指標 */
};
typedef struct Vertex *Graph;   /* 圖形的新型態 */
/* 函數: 使用邊線陣列建立含內分支度的圖形 */ 
void createGraph(Graph head, int len, int *edge) {
   Graph newnode, ptr;           /* 頂點指標 */
   int from, to;                 /* 邊線的起點和終點 */
   int i;
   for ( i = 1; i < MAX_VERTICES; i++ ) {
      head[i].data = 0;          /* 清除頂點值 */
      head[i].next = NULL;       /* 清除圖形指標 */
   }
   for ( i = 0; i < len; i++ ) { /* 讀取邊線的迴圈 */
      from = edge[i*3];          /* 邊線的起點 */
      to = edge[i*3+1];          /* 邊線的終點 */
      head[to].data += 1;        /* 內分支度加一 */
      /* 配置新頂點的記憶體 */
      newnode = (Graph)malloc(sizeof(struct Vertex));
      newnode->data = to;       /* 建立頂點內容 */
      newnode->weight = edge[3*i+2];
      newnode->next = NULL;     /* 設定指標初值 */
      ptr = &(head[from]);      /* 指標陣列的頂點指標 */
      while ( ptr->next != NULL ) /* 走訪至串列尾 */
         ptr = ptr->next;         /* 下一個頂點 */
      ptr->next = newnode;        /* 插入結尾 */
   }
}
/* 函數: 顯示圖形 */
void printGraph(Graph head) {
   Graph ptr;
   int i;
   /* 使用迴圈顯示圖形 */
   for ( i = 1; i < MAX_VERTICES; i++ ) {
      ptr = head[i].next;               /* 頂點指標 */
      if ( ptr != NULL ) {  /* 有使用的節點 */
         printf("V%d(%d) =>",i,head[i].data);/* 頂點 */
         while ( ptr != NULL ) {        /* 走訪顯示 */
            printf("V%d[%d] ", ptr->data,
                   ptr->weight);        /* 頂點內容 */
            ptr = ptr->next;            /* 下一個頂點 */
         }
         printf("\n");
      }   
   }
}
