/* stack.c */
/* �[�J�M�R�����b��C���e�� */
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
struct student *x,*head,*current;

int main()
{
    /* ��C���Ĥ@�Ӹ`�I���s���� */ 
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

/* �[�J�@�`�I���C�e�� */ 
void Insert()
{
    /* �t�m�O���^�A�ë��w��� */ 
    x=(struct student *)malloc(sizeof(struct student));  
    printf("Please input your ID: ");
    scanf("%d",&x->id);
    printf("Please input your score: ");
    scanf("%d",&x->score);  
    x->next=NULL;
    
    x->next=head->next;
    head->next=x;
    printf("====================================\n");
}

/* �R����C�e�ݪ��`�I */ 
void Delete()
{
    char ch;
    /* �P�_��C�O�_����� */       
    if(head->next == NULL)
    {
       printf("The linked list is empty!\n");
       return;
    }
    printf("Are you sure (y/n)? ");
    ch=getche();
    
    if(tolower(ch) == 'y')
    {
        current=head->next;    
        printf("\n%d record has been deleted!!!", current->id); 
        head->next=current->next;
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
       current=head->next;
       while(current!=NULL)
       {   
          printf("ID:%d, score=%d\n",current->id,current->score);
          current=current->next;
       }
    }
    printf("====================================\n");
}

void Quit()
{
    exit(0);
}