/* file name: circle_list.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
void read_f(void);      /* �}�ɨ�� */
void write_f(void);     /* �s�ɨ�� */
void insert_f(void);    /* ���J��� */
void sort_f(void);      /* �ƧǨ�� */
void delete_f(void);    /* �R����� */
void display_f(void);   /* ��X��� */
void modify_f(void);    /* �ק��� */
void anykey_f(void);
struct student {
	char name[20];        /* �m�W */
	int score;            /* ���� */
	struct student *next; /* �U�@���쵲 */
};
struct student *ptr, *head, *tail, *this_n, *prev;

void main(void)
{
	char option1;
	system("cls");
	read_f();
	while(1)
	{
		system("cls");
		printf(" \n****************************************\n");
		printf("               1.insert\n");
		printf("               2.delete\n");
		printf("               3.display\n");
		printf("               4.modify\n");
		printf("               5.quit\n");
		printf(" ****************************************\n");
		printf("   Please enter your choice (1-5)...");
		option1=getche();
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
	/* �}�ɮɡA�Y�ɮפ��s�b�A�h�n�D��J�Ĥ@����� */
	if((fptr = fopen("dfile.dat", "r")) == NULL)
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
	fptr = fopen("dfile.dat", "w");
	this_n = head;
	if(head != NULL)
		do
		{
			fprintf(fptr, "%s %d\n", this_n->name, this_n->score);
			this_n = this_n->next;
		}  while(this_n != head);
	fclose(fptr);
}

void insert_f(void)
{
	char s_temp[4];
	system("cls");
	ptr = (struct student *) malloc(sizeof(struct student));
	printf("\n Student name : ");
	gets(ptr->name);
	printf(" Student score: ");
	gets(s_temp);
	ptr->score = atoi(s_temp);
	sort_f();
}

void sort_f(void)
{
	if(head == NULL)      /* ���J��Ƭ��Ĥ@�� */
	{
		ptr->next = ptr;
		head = ptr;
		tail = ptr;
	}
	else
	{
		this_n = head;
		if(strcmp(ptr->name, this_n->name) < 0)   /* ���J��m���e�� */
		{
			ptr->next = this_n;
			head = ptr;
			tail->next = head;
		}
		else
		{
			while(this_n->next != head)
			{
				prev = this_n;
				this_n = this_n->next;
				if(strcmp(ptr->name, this_n->name) < 0)  /* ���J��m�󤤶� */
				{
					ptr->next = this_n;
					prev->next = ptr;
					break;
				}
			}
			if(strcmp(ptr->name, this_n->name) >= 0)   /* ���J��Ʃ���� */
			{
				ptr->next = head;
				this_n->next = ptr;
				tail = ptr;
			}
		}
	}
}

void delete_f(void)
{
	char del_name[20];
	int count = 0;
	struct student *clear;
	system("cls");
	if(head == NULL) printf(" No student record\n");
	else
	{
		printf("\n Delete student name: ");
		gets(del_name);
		this_n = head;
		while(strcmp(del_name,head->name) == 0)  /* �R����Ʃ�e�� */
		{
			count++;
			clear = this_n;
			if(head->next == head)      /* ��ƶȦs�b�@�� */
			{
				head = NULL;
				tail = NULL;
			}
			else
			{
				head = head->next;
				tail->next = head;
				this_n = head;
			}
			free(clear);
		}
		while(this_n->next != head && head != NULL)   /* �R����Ʃ󤤶� */
		{
			prev = this_n;
			this_n = this_n->next;
			while(strcmp(del_name,this_n->name) == 0)
			{
				count++;
				clear = this_n;
				prev->next = this_n->next;
				if(this_n == tail)
					tail = prev;
				this_n = this_n->next;
				free(clear);
			}
		}
		if(strcmp(del_name,tail->name) == 0)   /*�R����Ʃ���� */
		{
			count++;
			clear = this_n;
			prev->next = head;
			tail = prev;
			free(clear);
		}
		if(count > 0)
			printf(" %d student record(s) deleted\n",count);
		else    /* �䤣���ƫh��ܿ��~ */
			printf(" Student %s not found\n",del_name);
	}
	anykey_f();
}

void modify_f(void)
{
	int count = 0;
	char n_temp[20],s_temp[4];
	system("cls");
	if(head == NULL) printf(" No student record\n");
	else
	{
		printf("\n Modify student name: ");
		gets(n_temp);
		this_n = head;
		do
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
			this_n = this_n->next;
		}  while(this_n != head);
		if(count > 0)
			printf(" %d student record(s) modified\n",count);
		else     /* �䤣���ƫh��ܿ��~ */
			printf(" Student %s not found\n",n_temp);
	}
	anykey_f();
}

void display_f(void)
{
	int count = 0;
	system("cls");
	if(head == NULL) printf(" No student record\n");
	else
	{
		printf("\n  NAME                SCORE\n");
		printf(" ---------------------------\n");
		this_n=head;
		do
		{
			printf("  %-20s %3d\n", this_n->name, this_n->score);
			count++;
			this_n=this_n->next;
			if(count % 20 == 0) getch();
		}  while(this_n != head);
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
