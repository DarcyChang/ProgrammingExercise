/* �{���d��: Ch3-3.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* ���clabel���ŧi */ 
struct label {
   char name[20];
   int age;
};
/* ���: ��ܵ��c���Ъ������ܼ� */ 
void showlabel(struct label *ptr) {
   printf("���u�W�P----------\n"); 
   printf("�m�W: %s\n", ptr->name);
   printf("�~��: %d\n", ptr->age);
   printf("------------------\n");
}
/* �D�{�� */
int main() {
   /* �ŧi�ܼ� */
   struct label worker;
   struct label *ptr;
   /* �N���c���Ы��V���c */
   ptr = &worker; 
   /* ���w���c�������ܼ� */
   strcpy(worker.name, "���|�w");
   ptr->age = 30;
   printf("�m�W: %s\n", worker.name);
   printf("�~��: %d\n", worker.age);
   /* �I�s��� */
   showlabel(ptr); 
   system("PAUSE");
   return 0; 
}
