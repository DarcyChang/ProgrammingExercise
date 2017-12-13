/* addressStruct.c */
#include <stdio.h>
#include <stdlib.h>
int main( )
{
	/* 宣告結構變數 */
    struct employee
	{	
 		char id[7];	    /* ID號碼 */
		char name[20];	/* 員工姓名 */
		int salary;	    /* 所得薪資 */
	};
	/* 定義結構變數，並設定其初值 */
	struct employee manager = {"D12345", "Peter", 35000};
 	int a = 10;
	printf("a = %d = 0x%x\n", a, a);
	printf("a = %x\n", &a);

	/* 印出結構變數的記憶體位址 */  
	printf("manager= %p\n", manager);
	printf("&manager= %p\n", &manager);
	printf("manager.id= %p\n", manager.id);
	printf("&manager.id= %p\n", &manager.id);
	printf("manager.name= %p\n", manager.name);
	printf("&manager.name= %p\n", &manager.name);
	printf("manager.salary= %p\n\n", manager.salary);
	printf("&manager.salary= %p\n\n", &manager.salary);
	
	/* 印出結構變數的值 */
 	printf("manager.id= %s\n", manager.id);
    printf("manager.name= %s\n", manager.name);	
    printf("manager.salary= %d\n\n", manager.salary);
	system("PAUSE");
	return 0;
}

