/* 程式範例: Ch3-5.c */
#include <stdio.h>
#include <stdlib.h>
#include "Ch3-5.h"
#include "String.c"
/* 主程式 */
int main() {
   /* 宣告變數 */
   char str[80];
   char str1[80];
   char *ptr;
   int len;
   printf("請輸入處理的字串: ");
   gets(str);
   /* 顯示字串 */ 
   printf("原始字串: \"%s\"\n", str);
   /* 顯示字串長度 */ 
   len = strLen(str);
   printf("字串\"%s\"的長度為: %d\n", str, len);
   /* 複製字串 */ 
   printf("複製字串: \"%s\"\n", strCpy(str1, str));
   printf("請輸入欲連接的字串: ");
   gets(str1);
   printf("欲連接字串: \"%s\"\n", str1); 
   ptr = strCat(str, str1);       /* 連接字串 */ 
   printf("連接結果的字串: \"%s\"\n", ptr);
   printf("請輸入欲比較的字串: ");
   gets(str1);
   printf("欲比較的字串: \"%s\"\n", str1);
   /* 字串比較 */ 
   printf("字串比較結果: %d\n", strCmp(str, str1));
   printf("請輸入搜尋字串: ");
   gets(str1);
   printf("搜尋字串: \"%s\"\n", str1);    
   ptr = strPos(str, str1);        /* 搜尋字串 */
   if ( ptr != NULL )
      printf("搜尋字串出現的位址:%p(%c)\n", ptr, *ptr);
   else
      printf("搜尋字串不是子字串\n");
   system("PAUSE");
   return 0; 
}
