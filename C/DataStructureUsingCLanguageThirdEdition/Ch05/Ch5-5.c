/* �{���d��: Ch5-5.c */
#include <stdio.h>
#include <stdlib.h>
/* �e������D�����j��� */
int hanoiTower(int dishs,int peg1,int peg2,int peg3) {
   if ( dishs == 1)             /* �פ���� */
     printf("�L�l�q %d ���� %d\n", peg1, peg3);
   else {
     hanoiTower(dishs - 1,peg1,peg3,peg2); /* ��1�B�J */
     printf("�L�l�q %d ���� %d\n", peg1, peg3);
     hanoiTower(dishs - 1,peg2,peg1,peg3); /* ��3�B�J */
   }
}
/* �D�{�� */
int main() {
   hanoiTower(3,1,2,3);          /* �I�s���j��� */
   system("PAUSE");
   return 0; 
}
