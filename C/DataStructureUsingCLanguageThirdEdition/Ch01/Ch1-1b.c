/* �{���d��: Ch1-1b.c */
#include <stdio.h>
#include <stdlib.h>
/* �D�{�� */
int main() {
   /* �x�s�U�����Z���}�C */
   int t[10] = { 81,93,77,59,69,85,90,83,100,75 };
   int sum = 0;                    /* �`�� */
   float average;                  /* ���� */
   int i;
   for ( i = 0; i < 10; i++ )
      sum += t[i];                  /* �p���`�� */
   average = sum / 10;              /* �p�⥭�� */
   printf("�`��: %d\n", sum);       /* ����`�� */
   printf("����: %5.2f\n", average);/* ��ܥ��� */
   system("PAUSE");
   return 0; 
}
