/* �{���d��: Ch1-4.c */
#include <stdio.h>
#include <stdlib.h>
#include "Ch1-4.h"
/* ��ƭ쫬�ŧi */
static void maxvalue(void);
static void minvalue(void);
int var1, var2;
static int result;
/* ���: �̤j�� */
static void maxvalue() {
   if ( var1 > var2 ) result = var1;
   else               result = var2;
}
/* ���: �̤p�� */
static void minvalue() {
   if ( var1 < var2 ) result = var1;
   else               result = var2;
}
/* ���: ��ܾ���ܼƪ�������G */
void cmpresult(int type) {
   printf("�ܼ�1: %d\n", var1);
   printf("�ܼ�2: %d\n", var2);
   if ( type == MAXCMP ) {
       maxvalue();
       printf("�̤j��: %d\n", result);
   } else {
       minvalue();
       printf("�̤p�� : %d\n", result);
   }
}
