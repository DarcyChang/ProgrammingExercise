/* file name: double_list.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
void init_f(void);     /* 初始化串列，建立一空節點為HEAD */
void read_f(void);     /* 開檔函數 */
void write_f(void);    /* 存檔函數 */
void insert_f(void);   /* 插入函數 */
void sort_f(void);     /* 排序函數 */
void delete_f(void);   /* 刪除函數 */
void display_f(void);  /* 輸出函數 */
void modify_f(void);   /* 修改函數 */
void anykey_f(void);
struct student {
	char name[20];         /* 姓名 */
	int score;             /* 分數 */
	struct student *prev;  /* 節點左鏈結 */
	struct student *next;  /* 節點右鏈結 */
};
struct student *ptr, *head, *tail, *this_n;

void main(void)
{
	char option1;
	system("cls");
	init_f();
	read_f();
	while(1)
	{
		system("cls");
		printf(" ****************************************\n");
		printf("              1.insert\n");
		printf("              2.delete\n");
		printf("              3.display\n");
		printf("              4.modify\n");
		printf("              5.quit\n");
		printf(" ****************************************\n");
		printf("   Please enter your choice (1-5)...");
		option1 = getche();
		switch(option1)
		{
			case '1':
				insert_f();
				break;
			case '2':
				delete_f();
				break;
			case '3':
				display_f();
				break;
			case '4':
				modify_f();
				break;
			case '5':
				write_f();
				exit(0);
		}
	}
}

void init_f(void)  /* 設一HEAD，將左右鏈結皆指向本身 */
{
	ptr = (struct student *) malloc(sizeof(struct student));
	strcpy(ptr->name, "0");
	ptr->prev = ptr;
	ptr->next = ptr;
	head = ptr;
	tail = ptr;
}

void read_f(void)
{
	FILE *fptr;
	if((fptr = fopen("dfile.dat","r")) == NULL) /* 找不到檔案則要求輸入第一筆 */
	{
		printf(" Data file not exist\n");
		printf(" Press any key to edit first record...\n");
		getch();
		insert_f();
	}
	else
	{
		ptr = (struct student *) malloc(sizeof(struct student));
		while(fscanf(fptr, "%s %d", ptr->name, &ptr->score) != EOF)
		{
			if(strcmp(ptr->name, "") != 0)
			{
				sort_f();
				ptr = (struct student *) malloc(sizeof(struct student));
			}
			else
				free(ptr);
		}
		fclose(fptr);
	}
}

void write_f(void)
{
	FILE *fptr;
	fptr = fopen("dfile.dat","w");
	this_n = head->next;
	while(this_n != head)
	{
		fprintf(fptr, "%s %d\n", this_n->name, this_n->score);
		this_n = this_n->next;
	}
	fclose(fptr);
}

void insert_f(void)
{
	char s_temp[4];
	system("cls");
	ptr = (struct student *) malloc(sizeof(struct student));
	printf(" Student name : ");
	gets(ptr->name);
	printf(" Student score: ");
	gets(s_temp);
	ptr->score = atoi(s_temp);
	sort_f();
}

void sort_f(void)
{
	this_n = head->next;
	while(this_n != head)
	{
		if(strcmp(ptr->name, this_n->name) < 0)  /* 插入位置為中間 */
		{
			ptr->next = this_n;
			ptr->prev = this_n->prev;
			this_n->prev->next = ptr;
			this_n->prev = ptr;
			break;
		}
		this_n = this_n->next;
	}
	/* 插入位置為尾端 */
	if(head->next == head || this_n == head)
	{
		ptr->next = head;
		ptr->prev = head->prev;
		head->prev->next = ptr;
		head->prev = ptr;
		tail = ptr;
	}
}

void delete_f(void)
{
	char del_name[20];
	int count = 0;
	struct student *clear;
	system("cls");
	if(head->next == head) printf(" No student record\n");
	else
	{
		printf(" Delete student name: ");
		gets(del_name);
		this_n = head->next;
		while(this_n->next != head)
		{
			/* 刪除資料於中間 */
			while((strcmp(del_name,this_n->name) == 0) && (this_n->next != head))
			{
				count++;
				clear = this_n;
				this_n->prev->next = this_n->next;
				this_n->next->prev = this_n->prev;
				this_n = this_n->next;
				free(clear);
			}
			this_n = this_n->next;
		}
		if(strcmp(del_name,this_n->name) == 0)  /* 刪除資料於尾端 */
		{
			count++;
			clear = this_n;
			this_n->prev->next = head;
			head->prev = this_n->prev;
			tail = this_n->prev;
			free(clear);
		}
		if(count > 0)
			printf(" %d student record(s) deleted\n",count);
		else  /* 找不到資料則顯示錯誤 */
			printf(" Student %s not found\n",del_name);
	}
	anykey_f();
}

void modify_f(void)
{
	int count = 0;
	char n_temp[20],s_temp[4];
	system("cls");
	if(head->next == head) printf(" No student recond\n"); /* 無資料顯示錯誤 */
	else
	{
		printf(" Modify student name: ");
		gets(n_temp);
		this_n = head->next;
		while(this_n != head)
		{	/* 若找到修改資料，則印出原內容，並要求修改 */
			if(stricmp(n_temp,this_n->name) == 0)
			{
				printf(" **************************\n");
				printf("  Student name : %s\n",this_n->name);
				printf("  Student score: %d\n",this_n->score);
				printf(" **************************\n");
				printf(" Please enter new score: ");
				gets(s_temp);
				this_n->score = atoi(s_temp);
				count++;
			}
			this_n = this_n->next;
		}
		if(count > 0)
			printf(" %d student record(s) modified\n",count);
		else
			printf(" Student %s not found\n",n_temp);
	}
	anykey_f();
}

void display_f(void)
{
	int count = 0;
	system("cls");
	if(head->next == head) printf(" No student record\n");
	else
	{
		printf("  NAME                SCORE\n");
		printf(" ---------------------------\n");
		this_n = head->next;
		while(this_n != head)
		{
			printf("  %-20s %3d\n", this_n->name, this_n->score);
			count++;
			this_n = this_n->next;
			if(count % 20 == 0) getch(); /* 每次印出20筆資料 */
		}
		printf(" ---------------------------\n");
		printf(" Total %d record(s) found\n", count);
	}
	anykey_f();
}

void anykey_f(void)
{
	printf(" Press any key to continue...");
	getch();
}
