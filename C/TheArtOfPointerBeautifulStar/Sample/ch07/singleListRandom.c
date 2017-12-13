/* singleListRandom.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
 
void insert_func(void);
void sort_func(void);
void delete_func(void);
void display_func(void);
void modify_func(void);
void anykey_func(void);

struct student {
	char name[20];
	int score;
	struct student *next;
};
struct student *ptr, *head, *current, *prev;

int main()
{
	char option1;
    head = (struct student *) malloc(sizeof(struct student));
    head->next=NULL;
	while(1) {
		printf("\n");
		printf("******************\n");
		printf("   1.insert\n");
		printf("   2.delete\n");
		printf("   3.display\n");
		printf("   4.modify\n");
		printf("   5.quit\n");
		printf("*******************\n");
		printf(" Enter your choice (1-5): ");
		option1=getche();
		printf("\n");
		switch(option1)	{
			case '1':
				insert_func();
				break;
			case '2':
				delete_func();
				break;
			case '3':
				display_func();
				break;
			case '4':
				modify_func();
				break;
			case '5':
 				printf("\n");
				return 0;
		}
	}
}

/* 加入是以分數的高低加以排序 */
void insert_func(void)
{
	char s_temp[4];
	ptr=(struct student *) malloc(sizeof(struct student));
	printf(" Student name : ");
	gets(ptr->name);
	printf(" Student score: ");
	gets(s_temp);
	ptr->score = atoi(s_temp);
 
	prev = head;
	current = head->next;
	while ((current != NULL) && (current->score > ptr->score)) {
		prev = current;
		current = current->next;
	}
	ptr->next = current;
	prev->next = ptr;
}

/* 刪除是以姓名為鍵值*/
void delete_func(void)
{
	char del_name[20], ans;
	printf(" Delete student name: ");
	gets(del_name);
	
	prev = head;
	current = head->next;
    	while ((current != NULL) && (strcmp(current->name , del_name)!=0)) {
		prev = current;
		current = current->next;
	}
	if (current != NULL) {
        /* 確認是否要刪除 */       
        printf(" Are you sure? ");
        ans=getche();
        if (ans == 'Y' || ans == 'y') {
            prev->next = current->next;
		    free(current);
		    printf("\n Student %s has been deleted\n",del_name);
         }
	}
	else
		printf(" Student %s not found\n",del_name);
 }

void modify_func(void)
{
	char n_temp[20],s_temp[4];
	printf(" Modify student name: ");
	gets(n_temp);
	current=head->next;

	while ((current != NULL) && (strcmp(current->name , n_temp)!=0)) {
		prev = current;
		current = current->next;
	}
	if (current != NULL) {
		printf(" **************************\n");
		printf("  Student name : %s\n",current->name);
		printf("  Student score: %d\n",current->score);
		printf(" **************************\n");
		printf(" Please enter new score: ");
		gets(s_temp);
		current->score = atoi(s_temp);
		printf(" Student %s has been modified\n",n_temp);
	}
	else
		printf(" Student %s not found\n",n_temp);
}

void display_func(void)
{
	int count=0;

	if(head->next == NULL) {
		printf(" No student record\n");
	}
	else {
		printf("\n");
		printf("  NAME      SCORE\n");
		printf(" ----------------\n");
		current=head->next;
		while(current != NULL) {
			printf("  %-10s %3d\n", current->name, current->score);
			count++;
			current=current->next;
			if(count % 20 == 0) getch();
		}
		printf(" ----------------\n");
		printf(" Total %d record(s) found\n", count);
	}
}
 
