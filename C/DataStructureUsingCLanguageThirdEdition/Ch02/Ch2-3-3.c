/* �{���d��: Ch2-3-3.c */
#include <stdio.h>
#include <stdlib.h>
/* �D�{�� */ 
int main() {
   struct test {               /* �ŧi���c */
      int math;
      int english;
      int computer;
   };
   typedef struct test score;  /* �w�q�s���A */
   score joe, jane;            /* �ϥηs���A�ܼƫŧi */
   joe.math = 80;              /* ���w�����ܼ� */ 
   joe.english = 85;
   joe.computer = 83;
   jane.math = 78;             /* ���w�����ܼ� */ 
   jane.english = 65;
   jane.computer = 55;
   /* ��ܦ��Z */
   printf("�m�W: Joe\n");
   printf("�ƾ�: %d\n", joe.math);
   printf("�^��: %d\n", joe.english);
   printf("�ƾ�: %d\n", joe.computer);
   printf("=================\n");
   printf("�m�W: Jane\n");
   printf("�ƾ�: %d\n", jane.math);
   printf("�^��: %d\n", jane.english);
   printf("�ƾ�: %d\n", jane.computer);
   system("PAUSE");
   return 0;  
}
