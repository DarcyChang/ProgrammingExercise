/* file name: double_list.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
void init_f(void);     /* ��l�Ʀ�C�A�إߤ@�Ÿ`�I��HEAD */
void read_f(void);     /* �}�ɨ�� */
void write_f(void);    /* �s�ɨ�� */
void insert_f(void);   /* ���J��� */
void sort_f(void);     /* �ƧǨ�� */
void delete_f(void);   /* �R����� */
void display_f(void);  /* ��X��� */
void modify_f(void);   /* �ק��� */
void anykey_f(void);
struct student {
	char name[20];         /* �m�W */
	int score;             /* ���� */
	struct student *prev;  /* �`�I���쵲 */
	struct student *next;  /* �`�I�k�쵲 */
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

void init_f(void)  /* �]�@HEAD�A�N���k�쵲�ҫ��V���� */
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
	if((fptr = fopen("dfile.dat","r")) == NULL) /* �䤣���ɮ׫h�n�D��J�Ĥ@�� */
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
		if(strcmp(ptr->name, this_n->name) < 0)  /* ���J��m������ */
		{
			ptr->next = this_n;
			ptr->prev = this_n->prev;
			this_n->prev->next = ptr;
			this_n->prev = ptr;
			break;
		}
		this_n = this_n->next;
	}
	/* ���J��m������ */
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
			/* �R����Ʃ󤤶� */
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
		if(strcmp(del_name,this_n->name) == 0)  /* �R����Ʃ���� */
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
		else  /* �䤣���ƫh��ܿ��~ */
			printf(" Student %s not found\n",del_name);
	}
	anykey_f();
}

void modify_f(void)
{
	int count = 0;
	char n_temp[20],s_temp[4];
	system("cls");
	if(head->next == head) printf(" No student recond\n"); /* �L�����ܿ��~ */
	else
	{
		printf(" Modify student name: ");
		gets(n_temp);
		this_n = head->next;
		while(this_n != head)
		{	/* �Y���ק��ơA�h�L�X�줺�e�A�ín�D�ק� */
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
			if(count % 20 == 0) getch(); /* �C���L�X20����� */
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
