/* addressStruct.c */
#include <stdio.h>
#include <stdlib.h>
int main( )
{
	/* �ŧi���c�ܼ� */
    struct employee
	{	
 		char id[7];	    /* ID���X */
		char name[20];	/* ���u�m�W */
		int salary;	    /* �ұo�~�� */
	};
	/* �w�q���c�ܼơA�ó]�w���� */
	struct employee manager = {"D12345", "Peter", 35000};
 	int a = 10;
	printf("a = %d = 0x%x\n", a, a);
	printf("a = %x\n", &a);

	/* �L�X���c�ܼƪ��O�����} */  
	printf("manager= %p\n", manager);
	printf("&manager= %p\n", &manager);
	printf("manager.id= %p\n", manager.id);
	printf("&manager.id= %p\n", &manager.id);
	printf("manager.name= %p\n", manager.name);
	printf("&manager.name= %p\n", &manager.name);
	printf("manager.salary= %p\n\n", manager.salary);
	printf("&manager.salary= %p\n\n", &manager.salary);
	
	/* �L�X���c�ܼƪ��� */
 	printf("manager.id= %s\n", manager.id);
    printf("manager.name= %s\n", manager.name);	
    printf("manager.salary= %d\n\n", manager.salary);
	system("PAUSE");
	return 0;
}

