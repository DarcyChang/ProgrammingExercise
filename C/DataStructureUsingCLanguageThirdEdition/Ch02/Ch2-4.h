/* 程式範例: Ch2-4.h */
#define MAX_TERMS    10  /* 稀疏矩陣的最大元素數 */
struct Term {            /* 稀疏矩陣的元素結構 */ 
   int row;              /* 元素的列數 */ 
   int col;              /* 元素的欄數 */ 
   int value;            /* 元素的值 */ 
};
struct sMatrix {         /* 稀疏矩陣的結構 */
   int rows;             /* 矩陣的列數 */ 
   int cols;             /* 矩陣的欄數 */ 
   int numOfTerms;       /* 矩陣的元素數 */ 
   struct Term smArr[MAX_TERMS];  /* 壓縮陣列的宣告 */
};
typedef struct sMatrix Matrix; /* 建立稀疏矩陣的新型態 */ 
Matrix m;                      /* 建立稀疏矩陣 */ 
/* 抽象資料型態的操作函數宣告 */
extern void createMatrix(int r,int c,int *arr);
extern void printMatrix();
