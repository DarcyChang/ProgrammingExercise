/* 程式範例: Ch3-4-1.c */
#include <stdio.h>
#include <stdlib.h>
#define LEN       16
/* 主程式 */
int main() {
   /* 字元陣列宣告 */
   char str[LEN] = "This is a book.";
   char str1[LEN];
   /* 字元指標 */
   char *ptr  = str;
   char *ptr1;
   int i; 
   /* 顯示字串內容 */
   ptr1 = "This is a pen.";
   printf("str = %s\n", str);
   printf("ptr = %s\n", ptr);
   printf("ptr1 = %s\n", ptr1);
   /* 字串複製的迴圈 */
   printf("將字串str複製到str1: \n"); 
   i = 0;
   ptr1 = str1;
   while ( *ptr != '\0' ) {
      *(ptr1+i) = *ptr++;
      i++;
   }
   *(ptr1+i) = '\0';
   printf("str1 = %s\n", str1);
   printf("ptr1 = %s\n", ptr1);
   system("PAUSE");
   return 0; 
}
