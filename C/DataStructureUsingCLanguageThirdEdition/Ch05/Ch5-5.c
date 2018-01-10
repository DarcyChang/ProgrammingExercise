/* 程式範例: Ch5-5.c */
#include <stdio.h>
#include <stdlib.h>
/* 河內塔問題的遞迴函數 */
int hanoiTower(int dishs,int peg1,int peg2,int peg3) {
   if ( dishs == 1)             /* 終止條件 */
     printf("盤子從 %d 移到 %d\n", peg1, peg3);
   else {
     hanoiTower(dishs - 1,peg1,peg3,peg2); /* 第1步驟 */
     printf("盤子從 %d 移到 %d\n", peg1, peg3);
     hanoiTower(dishs - 1,peg2,peg1,peg3); /* 第3步驟 */
   }
}
/* 主程式 */
int main() {
   hanoiTower(3,1,2,3);          /* 呼叫遞迴函數 */
   system("PAUSE");
   return 0; 
}
