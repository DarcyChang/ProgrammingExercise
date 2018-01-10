/* 使用環形佇列處理資料--新增、刪除、輸出 */
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define MAX 20
void enqueue_f(void);   /* 新增函數 */
void dequeue_f(void);   /* 刪除函數 */
void list_f(void);      /* 輸出函數 */

char item[MAX][20];
int front = MAX-1, rear = MAX-1, tag = 0;
/* TAG為記憶FRONT所在是否有儲存資料，0時為沒有存放資料，1時為有存放資料 */

void main(void)
{
	char option;
	while(1)
	{
		printf("\n *****************************\n");
		printf("       <1> insert (enqueue)\n");
		printf("       <2> delete (dequeue)\n");
		printf("       <3> list\n");
		printf("       <4> quit\n");
		printf(" *****************************\n");
		printf(" Please enter your choice...");
		option = getche();
		switch(option)
		{
			case '1':
				enqueue_f();
				break;
			case '2':
				dequeue_f();
				break;
			case '3':
				list_f();
				break;
			case '4':
				exit(0);
		}
	}
}

void enqueue_f(void)
{
	if(front == rear && tag == 1) /* 當佇列已滿，則顯示錯誤 */
		printf("\n\nQueue is full !\n");
	else
	{
		rear = (rear + 1) % MAX;
		printf("\n\n Please enter item to insert: ");
		gets(item[rear]);
		if(front == rear) tag = 1;
	}
}

void dequeue_f(void)
{
	if(front == rear && tag == 0)   /* 當資料沒有資料存在，則顯示錯誤 */
		printf("\n\n No item, queue is empty !\n");
	else
	{
		front = (front + 1) % MAX;
		printf("\n\n Item %s deleted\n", item[front]);
		if(front == rear) tag = 0;
	}
}

void list_f(void)
{
	int count = 0, i;
	if(front == rear && tag == 0)
		printf("\n\n No item, queue is empty\n");
	else
	{
		printf("\n\n  ITEM\n");
		printf(" ------------------\n");
		for(i = (front + 1) % MAX; i != rear; i = ++i % MAX)
		{
			printf("  %-20s\n", item[i]);
			count++;
			if(count % 20 == 0) getch();
		}
		printf("  %-20s\n", item[i]);
		printf(" ------------------\n");
		printf("  Total item: %d\n", ++count);
		getch();
	}
}
