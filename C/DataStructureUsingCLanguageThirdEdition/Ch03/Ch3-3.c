/* 程式範例: Ch3-3.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* 結構label的宣告 */ 
struct label {
   char name[20];
   int age;
};
/* 函數: 顯示結構指標的成員變數 */ 
void showlabel(struct label *ptr) {
   printf("員工名牌----------\n"); 
   printf("姓名: %s\n", ptr->name);
   printf("年齡: %d\n", ptr->age);
   printf("------------------\n");
}
/* 主程式 */
int main() {
   /* 宣告變數 */
   struct label worker;
   struct label *ptr;
   /* 將結構指標指向結構 */
   ptr = &worker; 
   /* 指定結構的成員變數 */
   strcpy(worker.name, "陳會安");
   ptr->age = 30;
   printf("姓名: %s\n", worker.name);
   printf("年齡: %d\n", worker.age);
   /* 呼叫函數 */
   showlabel(ptr); 
   system("PAUSE");
   return 0; 
}
