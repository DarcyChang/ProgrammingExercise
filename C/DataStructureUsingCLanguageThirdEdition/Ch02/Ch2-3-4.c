/* �{���d��: Ch2-3-4.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
struct test {                 /* �Ҹզ��Z�����c */ 
   int math;
   int english;
   int computer;
};
struct student {              /* �ǥ͸�ƪ����c */ 
   int id;
   char name[20];
   struct test score;         /* ���c�ܼ� */ 
};
/* �D�{�� */ 
int main() {
   /* ���c�ܼƪ��ŧi */
   struct student std1;
   struct student std2 = {2, "���p��", {45, 78, 66}};
   int total;
   std1.id = 1;               /* ���w���c�ܼƪ��� */ 
   strcpy(std1.name, "���|�w");
   std1.score.math = 78;
   std1.score.english = 65;
   std1.score.computer = 90;
   /* ��ܾǥ͸�� */
   printf("�Ǹ�: %d\n", std1.id);
   printf("�m�W: %s\n", std1.name);
   total = std1.score.math + std1.score.english +
           std1.score.computer;
   printf("���Z�`��: %d\n", total);
   printf("--------------------\n"); 
   printf("�Ǹ�: %d\n", std2.id);
   printf("�m�W: %s\n", std2.name);
   total = std2.score.math + std2.score.english + 
           std2.score.computer;
   printf("���Z�`��: %d\n", total);
   system("PAUSE");
   return 0;  
}
