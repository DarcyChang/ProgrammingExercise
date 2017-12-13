/* basicStruct-1.c */
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
	struct employee manager = {"D54321", "Peter", 35000};
	
	/* 定義結構指標變數ptr，將它指向結構變數manager的位址 */	
	struct employee *ptr = &manager;
	
	/* 印出記憶體的位址 */ 
	printf("&ptr= %x\n", &ptr);
    printf("ptr= %x\n", ptr);
	printf("&manager= %x\n", &manager);
	printf("&manager.id= %x\n", &manager.id);
	printf("manager.name= %x\n", manager.name);
	printf("&manager.salary= %x\n\n", &manager.salary);
	
	/* 使用 . 運算子取得各結構元素 */
    printf("<< 使用 . 運算子取得各結構元素 >>\n");
	printf("manager.id= %s\n", manager.id);
	printf("manager.name= %s\n", manager.name);	
    printf("manager.salary= %d\n\n", manager.salary);
	
	/* 使用->運算子取得各結構元素 */
    printf("<< 使用->運算子取得各結構元素 >>\n");
	printf("ptr->id= %s\n", ptr->id); 
	printf("ptr->name= %s\n", ptr->name); 
	printf("ptr->salary= %d\n\n", ptr->salary);
    
   	/* 使用(*).運算子取得各結構元素 */
    printf("<< 使用(*).運算子取得各結構元素 >>\n");
	printf("(*ptr).id= %s\n", (*ptr).id); 
	printf("(*pt).rname= %s\n",(*ptr).name); 
	printf("(*ptr).salary= %d\n", (*ptr).salary);	

	system("PAUSE");
	return 0;
}
