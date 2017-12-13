/* queue.c */
/* 加入在串列的尾端和刪除在前端 */
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
void Insert();
void Delete();
void Display();
void Quit();
struct student
{
       int id;
       int score;  
       struct student *next;
};
struct student *x,*head,*current, *prev; 

int main()
{
    /* 串列的第一個節點不存放資料 */ 
    head=(struct student *)malloc(sizeof(struct student));
    head->next= NULL; 
    for(;;)
    {
        int a;
        printf("\n");
        printf("1)Insert\n2)Delete\n3)Display\n4)Quit\n");
        printf("Which one: ");
        scanf("%d",&a);
        printf("\n");
        switch(a)
        {
            case 1:Insert();
                   break;
            case 2:Delete();
                   break;
            case 3:Display();
                   break;
            case 4:Quit();
                   break;
        }
    }
    printf("\n\n~~~~~~~~~~~~~~~FINISH~~~~~~~~~~~~~~~~"); 
    getch();
    return 0;
}

/* 加在尾端 */
void Insert()
{
    x=(struct student *)malloc(sizeof(struct student));  
    printf("Please input your ID: ");
    scanf("%10d",&x->id);
    printf("Please input your score: ");
    scanf("%d",&x->score);  
    x->next=NULL;
    
    if(head->next == NULL)
       head->next = x;
    else
    {  
       /* 追蹤串列的尾端 */ 
       current = head->next;
       while(current->next != NULL)
           current = current->next;
       current->next = x;
    }
    printf("====================================\n");
}

/* 刪除前端 */
void Delete()
{
    char ch;

    if(head->next == NULL){
       printf("The linked list is empty!\n");   
       return;
    }
    printf("Are you sure (y/n)? ");
    ch=getche();
    /* 確認是否要刪除 */ 
    if(tolower(ch) == 'y')
    {
       current = head->next;
       head->next = current->next;
       printf("\n%d record has been deleted!!!", current->id);
       free(current);  
    } 
    printf("\n====================================\n"); 
}

void Display()
{
    if(head->next == NULL)
       printf("The linked list is empty!\n");
    else
    {
       /* 將head 指定給currnt，利用current指標將串列的所有節點印出 */ 
       current=head->next;
       while(current!=NULL)
       {   
          printf("ID:%d, score=%d\n", current->id, current->score);
          current=current->next;
       }
    }
    printf("====================================\n");
}

void Quit()
{
    exit(0);
}

