/* 程式範例: Ch3-1-2.c */
#include <stdio.h>
#include <stdlib.h>
/* 主程式 */
int main() {
   /* 宣告變數 */
   int i, j;
   int *ptr = NULL;
   int *ptr1 = &i;  /* 指標變數的初值 */ 
   i = 1;
   j = 2; 
   /* 取得指標變數的值 */
   ptr = &j;
   printf("i   =%8d 位址=%p\n", i, &i);
   printf("j   =%8d 位址=%p\n", j, &j);
   printf("ptr =%p 位址=%p\n", ptr, &ptr);
   printf("*ptr :位址%p的值=%d\n", ptr, *ptr);
   printf("ptr1=%p 位址=%p\n", ptr1, &ptr1);
   printf("*ptr1:位址%p的值=%d\n", ptr1, *ptr1);
   system("PAUSE");
   return 0; 
}
