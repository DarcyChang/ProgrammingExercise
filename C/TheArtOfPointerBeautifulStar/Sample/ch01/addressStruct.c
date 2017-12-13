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
 	
	/* 印出結構變數的記憶體位址 */  
	printf("&manager= %x\n", &manager);
	printf("&manager.id= %x\n", &manager.id);
	printf("manager.name= %x\n", manager.name);
	printf("&manager.salary= %x\n\n", &manager.salary);
	
	/* 印出結構變數的值 */
 	printf("manager.id= %s\n", manager.id);
    printf("manager.name= %s\n", manager.name);	
    printf("manager.salary= %d\n\n", manager.salary);
	system("PAUSE");
	return 0;
}

