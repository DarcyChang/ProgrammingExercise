/* basicStruct-1.c */
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
	struct employee manager = {"D54321", "Peter", 35000};
	
	/* �w�q���c�����ܼ�ptr�A�N�����V���c�ܼ�manager����} */	
	struct employee *ptr = &manager;
	
	/* �L�X�O���骺��} */ 
	printf("&ptr= %x\n", &ptr);
    printf("ptr= %x\n", ptr);
	printf("&manager= %x\n", &manager);
	printf("&manager.id= %x\n", &manager.id);
	printf("manager.name= %x\n", manager.name);
	printf("&manager.salary= %x\n\n", &manager.salary);
	
	/* �ϥ� . �B��l���o�U���c���� */
    printf("<< �ϥ� . �B��l���o�U���c���� >>\n");
	printf("manager.id= %s\n", manager.id);
	printf("manager.name= %s\n", manager.name);	
    printf("manager.salary= %d\n\n", manager.salary);
	
	/* �ϥ�->�B��l���o�U���c���� */
    printf("<< �ϥ�->�B��l���o�U���c���� >>\n");
	printf("ptr->id= %s\n", ptr->id); 
	printf("ptr->name= %s\n", ptr->name); 
	printf("ptr->salary= %d\n\n", ptr->salary);
    
   	/* �ϥ�(*).�B��l���o�U���c���� */
    printf("<< �ϥ�(*).�B��l���o�U���c���� >>\n");
	printf("(*ptr).id= %s\n", (*ptr).id); 
	printf("(*pt).rname= %s\n",(*ptr).name); 
	printf("(*ptr).salary= %d\n", (*ptr).salary);	

	system("PAUSE");
	return 0;
}
