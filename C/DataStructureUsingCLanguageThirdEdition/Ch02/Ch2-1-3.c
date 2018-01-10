/* 程式範例: Ch2-1-3.c */
#include <stdio.h>
#include <stdlib.h>
/* 主程式 */
int main() {
   /* 學生功課表, 使用課程代碼 */
   int courses[6][5]={0, 2, 0, 2, 0,
                      1, 4, 1, 4, 1,
                      5, 0, 5, 0, 5,
                      0, 0, 0, 0, 0,
                      3, 0, 3, 0, 3,
                      0, 0, 0, 0, 0 };
   int week_no;    /* 星期幾 */
   int num;        /* 第幾節課 */
   int code;       /* 課程代碼 */
   printf("請輸入星期(1 到 5). ==> ");
   scanf("%d", &week_no);   /* 讀取星期幾 */
   printf("請輸入第幾節課(1 到 6). ==> ");
   scanf("%d", &num);       /* 讀取第幾節課 */
   /* 取得課程代碼 */
   code = courses[num-1][week_no-1];
   printf("課程代碼: %d\n", code); 
   /* 顯示課程名稱 */
   switch ( code ) {
      case 0: printf("沒課！\n");
              break;
      case 1: printf("計算機概論\n");
              break;
      case 2: printf("離散數學\n");
              break;
      case 3: printf("資料結構\n");
              break;
      case 4: printf("資料庫理論\n");
              break;
      case 5: printf("上機實習\n");
              break;
   }
   system("PAUSE");
   return 0; 
}
