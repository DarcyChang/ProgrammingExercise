/* �{���d��: Ch1-1a.c */
#include <stdio.h>
#include <stdlib.h>
/* �D�{�� */
int main() {
   int t1,t2,t3,t4,t5;             /* �U�������Z */
   int t6,t7,t8,t9,t10;
   int sum;                        /* �`�� */
   float average;                  /* ���� */
   t1 = 81; t2 = 93; t3 = 77; t4 = 59; t5 = 69;
   t6 = 85; t7 = 90; t8 = 83; t9 = 100; t10 = 75;
   sum = t1 + t2 + t3 + t4 + t5 +
         t6 + t7 + t8 + t9 + t10;   /* �p���`�� */
   average = sum / 10;              /* �p�⥭�� */
   printf("�`��: %d\n", sum);       /* ����`�� */
   printf("����: %5.2f\n", average);/* ��ܥ��� */
   system("PAUSE");
   return 0; 
}
