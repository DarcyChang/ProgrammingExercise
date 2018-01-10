/* 使用多個堆疊處理資料--新增、刪除、輸出 */
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define MAX  10				/* 最大的堆疊容量 */
#define UNIT  2				/* 堆疊的個數 */
void push_f(int number1);   /* 新增函數 */
void pop_f(int number2);    /* 刪除函數 */
void list_f(int number3);   /* 輸出函數 */

char MS[MAX][20];			/* 堆疊陣列 */
int t[UNIT], b[UNIT];  /* top指標與bottom指標 */

void main(void)
{
	int option, i;
	int  number1, number2, number3;

	/*top指標與bottom指標的初始化*/
	for (i=0; i<=UNIT-1 ; i++){
		t[i] = i*(MAX/UNIT)-1;
		b[i] = i*(MAX/UNIT)-1;
	}

	while(1){
		printf("\n *****************************\n");
		printf("        <1> insert (push)\n");
		printf("        <2> delete (pop)\n");
		printf("        <3> list\n");
		printf("        <4> quit\n");
		printf(" *****************************\n");
		printf(" Please enter your choice...");
		scanf("%d", &option);
		switch(option){
			case 1:
				printf("\n The total number of Stack is %d !!", UNIT);
				printf("\n Please enter the number of stack ?");
				scanf("%d",&number1);
				if (number1 > UNIT)
				  printf(" Sorry, the number is out of Stack total number !!\n");
				else
				  push_f(number1);
				break;
			case 2:
				printf("\n Please enter the number of stack ?");
				scanf("%d",&number2);
				if (number2 > UNIT)
				  printf(" Sorry, the number is out of Stack total number !!\n");
				else
				  pop_f(number2);
				break;
			case 3:
				printf("\n Please enter the number of stack ?");
				scanf("%d",&number3);
				if (number3 > UNIT)
				  printf(" Sorry, the number is out of Stack total number !!\n");
				else
				  list_f(number3);
				break;

			case 4:
				exit(0);
		}
	}
}

void push_f(int number1)
{
	if (t[number1-1] == MAX-1 && UNIT == 1){
		printf(" Queue #%d is full !\n",number1);
		printf(" Please choose another Stack to insert !!\n");
	}
	else if(t[number1-1] == b[number1] && UNIT != 1){   /* 當要加入的堆疊已滿，則顯示錯誤 */
		printf(" Stack #%d is full !\n",number1);
		printf(" Please choose another Stack to insert !!\n");
	}
	else{
		printf(" Please enter item to insert: ");
		scanf("%s",&MS[++t[number1-1]]);
		printf(" You insert %s to #%d stack !!\n", MS[t[number1-1]], number1 );
	}
}

void pop_f(int number2)
{
	if(t[number2-1] == b[number2-1])  /* 當堆疊沒有資料存在，則顯示錯誤 */
		printf("\n No item, stack%d is empty !\n",number2);
	else{
		printf("\n Item %s in Stack %d is deleted\n", MS[t[number2-1]], number2);
		t[number2-1]--;
	}
}

void list_f(int number3)
{
	int count = 0, i, start_number = 0;
	if(t[number3-1] == b[number3-1])
		printf("\n No item, stack is empty\n");
	else{
		start_number = (number3-1)*(MAX/UNIT)-1;
		printf("\n  ITEM\n");
		printf(" ------------------\n");
		for(i = start_number+1 ; i <= t[number3-1]; i++){
			printf("  %-20s\n", MS[i]);
			count++;
			if(count % 20 == 0) getch();
		}
		printf(" ------------------\n");
		printf("  Total item: %d\n", count);
		getch();
	}
}

