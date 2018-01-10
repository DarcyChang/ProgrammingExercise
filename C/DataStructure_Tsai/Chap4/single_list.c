/* file name: single_list.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
void read_f(void);
void write_f(void);
void insert_f(void);
void sort_f(void);
void delete_f(void);
void display_f(void);
void modify_f(void);
void anykey_f(void);
struct student {
	char name[20];
	int score;
	struct student *next;
};
struct student *ptr,*head,*tail,*this_n,*prev;

void main(void)
{
	char option1;
	read_f();
	while(1)
	{
		printf("****************************************\n");
		printf("              1.insert\n");
		printf("              2.delete\n");
		printf("              3.display\n");
		printf("              4.modify\n");
		printf("              5.quit\n");
		printf("****************************************\n");
		printf("   Please enter your choice (1-5)...");
		option1=getche();
		printf("\n");
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

void read_f(void)
{
	FILE *fptr;
	/* 開檔時，若檔案不存在，則要求輸入第一筆資料 */
	if((fptr=fopen("dfile.dat","r")) == NULL)
	{
		printf(" Data file not exist\n");
		printf(" Press any key to edit first record...\n");
		getch();
		insert_f();
	}
	else
	{
		ptr=(struct student *) malloc(sizeof(struct student));
		while(fscanf(fptr, "%s %d", ptr->name, &ptr->score) != EOF)
		{
			sort_f();
			ptr=(struct student *) malloc(sizeof(struct student));
		}
		fclose(fptr);
	}
}

void write_f(void)
{
	FILE *fptr;
	fptr=fopen("dfile.dat","w");
	this_n=head;
	while(this_n != NULL)
	{
		fprintf(fptr, "%s %d\n", this_n->name, this_n->score);
		this_n = this_n->next;
	}
	fclose(fptr);
}

void insert_f(void)
{
	char s_temp[4];
	ptr=(struct student *) malloc(sizeof(struct student));
	printf(" Student name : ");
	gets(ptr->name);
	printf(" Student score: ");
	gets(s_temp);
	ptr->score = atoi(s_temp);
	sort_f();
}

void sort_f(void)
{
	if(head == NULL)      /* 插入資料為第一筆 */
	{
		ptr->next=NULL;
		head=ptr;
		tail=ptr;
	}
	else
	{
		this_n=head;
		if(ptr->score > this_n->score)   /* 插入位置為前端 */
		{
			ptr->next=this_n;
			head=ptr;
		}
		else
		{
			while(this_n->next != NULL)
			{
				prev=this_n;
				this_n=this_n->next;
				if(ptr->score > this_n->score)  /* 插入位置於中間 */
				{
					ptr->next=this_n;
					prev->next=ptr;
					break;
				}
			}
			if(ptr->score <= this_n->score)   /* 插入資料於尾端 */
			{
				ptr->next=NULL;
				this_n->next=ptr;
				tail=ptr;
			}
		}
	}
}

void delete_f(void)
{
	char del_name[20];
	int count=0;
	struct student *clear;
	printf(" Delete student name: ");
	gets(del_name);
	this_n=head;
	while(strcmp(del_name,head->name) == 0)  /* 刪除資料於前端 */
	{
		count++;
		clear=this_n;
		if(head->next == NULL)      /* 資料僅存在一筆 */
			tail=NULL;
		head=head->next;
		this_n=head;
		free(clear);
	}
	while(this_n->next != NULL)   /* 刪除資料於中間 */
	{
		prev=this_n;
		this_n=this_n->next;
		while(strcmp(del_name,this_n->name) == 0)
		{
			count++;
			clear=this_n;
			prev->next=this_n->next;
			this_n=this_n->next;
			free(clear);
		}
	}
	if(strcmp(del_name,this_n->name) == 0)   /*刪除資料於尾端 */
	{
		count++;
		clear=this_n;
		prev->next=NULL;
		tail=prev;
		free(clear);
	}
	if(count > 0)
		printf(" %d student record(s) deleted\n",count);
	else    /* 找不到資料則顯示錯誤 */
		printf(" Student %s not found\n",del_name);
	anykey_f();
}

void modify_f(void)
{
	int count=0;
	char n_temp[20],s_temp[4];
	printf(" Modify student name: ");
	gets(n_temp);
	this_n=head;
	while(this_n != NULL)
	{
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
		this_n=this_n->next;
	}
	if(count > 0)
		printf(" %d student record(s) modified\n",count);
	else     /* 找不到資料則顯示錯誤 */
		printf(" Student %s not found\n",n_temp);
	anykey_f();
}

void display_f(void)
{
	int count=0;
	if(head == NULL) printf(" No student record\n");
	else
	{
		printf("  NAME                SCORE\n");
		printf(" ---------------------------\n");
		this_n=head;
		while(this_n != NULL)
		{
			printf("  %-20s %3d\n", this_n->name, this_n->score);
			count++;
			this_n=this_n->next;
			if(count % 20 == 0) getch();
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
	printf("\n");
}