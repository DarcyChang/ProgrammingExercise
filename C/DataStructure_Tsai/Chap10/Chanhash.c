/* 雜湊法 : 使用鏈結串列處理碰撞*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>

#define MAX_NUM 100  /*最大資料筆數*/
#define PRIME 97  /*MAX_NUM之質數*/
#define NOTEXISTED NULL

/*定義資料結構*/
typedef struct Person {
	long id;
	char name[21];
	struct Person *link;
} Student;

/*建立雜湊表串列*/
Student *Hashtab[MAX_NUM];

/*函數原型宣告*/
long hashfun(long);
void insert();
void del();
Student *search(Student *,Student *);
void query();
void show();

void main()
{
	char *menu_prompt =
		"=== Hashing Table Program ==\n"
		"  1. Insert\n"
		"  2. Delete\n"
		"  3. Show\n"
		"  4. Search\n"
		"  5. Quit\n"
		"Please input a number : ";
	char menusele;
	int i;

	/*起始雜湊串列，將各串列指向NULL*/
	for ( i = 0; i< MAX_NUM; i++)
		Hashtab[i] = NULL;

	do
	{
		printf("%s",menu_prompt);
		menusele = toupper(getche());
		puts("");
		switch (menusele)
		{
			case '1' :
				insert();
				break;
			case '2' :
				del();
				break;
			case '3' :
				show();
				break;
			case '4' :
				query();
				break;
			case '5' :
				puts("Bye Bye ^_^");
				break;
			default :
				puts("Invalid choice !!");
		}
	} while (menusele != '5' );
}

/*  雜湊函數:  */
/*  以除法運算傳求出記錄應儲存的位址  */
long hashfun(long key)
{
	return ( key % PRIME );
}

void insert()
{
	Student  *newnode;
	long index;

	/*輸入記錄*/
	newnode = ( Student *)malloc(sizeof(Student));
	newnode->link = NULL;
	printf("Enter id : ");
	scanf("%ld",&newnode->id);
	printf("Enter Name : ");
	scanf("%s",newnode->name);

	/*利用雜湊函數求得記錄位址*/
	index = hashfun(newnode->id);
	/*判斷該串列是否為空，若為空則建立此鏈結串列*/
	if ( Hashtab[index] == NULL )
	{
		Hashtab[index] = newnode;
		printf("Node insert ok!\n");
	}
	else
	{
		/*搜尋節點是否已存在串列中
		  如未存在則將此節點加入串列前端*/
		if ((search(Hashtab[index],newnode)) == NOTEXISTED)
		{
			newnode->link = Hashtab[index];
			Hashtab[index] = newnode;
			printf("Node insert ok!\n");
		}
		else
			printf("Record existed...\n");
	}
}

/*刪除節點函數*/
void del()
{
	Student *node ,*node_parent;
	long index;

	node = (Student *)malloc(sizeof(Student));
	printf("Enter ID : ");
	scanf("%ld",&node->id);
	/*利用雜湊函數轉換記錄位址*/
	index  =  hashfun(node->id);

	/*搜尋節點是否存在並傳回指向該節點指標*/
	node  = search(Hashtab[index],node);

	if ( node == NOTEXISTED )
		printf("Record not existed ...\n");
	else
	{
		/*如節點為串列首，則將串列指向NULL
		  否則找到其父節點，並將父節點link向節點後端*/
		printf("ID : %ld   Name : %s\n",node->id,node->name);
		printf("Deleting record....\n");
		if ( node == Hashtab[index] )
			Hashtab[index] = NULL;
		else
		{
			node_parent = Hashtab[index];
			while ( node_parent->link->id != node->id )
				node_parent = node_parent->link;
			node_parent->link = node->link;
		}
		free(node);
	}
}

/* 搜尋節點函數
   如找到節點則傳回指向該節點之指標
   否則傳回NULL  */
Student *search(Student *linklist,Student *Node)
{
	Student *ptr = linklist;
	while (ptr->id != Node->id && ptr->link != NULL)
		ptr = ptr->link;
	if ( ptr == NULL )
		return NOTEXISTED;
	else
		return ptr;
}

/*查詢節點函數*/
void query()
{
	Student *query_node;
	long index;

	query_node = (Student *)malloc(sizeof(Student));
	printf("Enter ID : ");
	scanf("%ld",&query_node->id);

	index = hashfun(query_node->id);
	/*搜尋節點*/
	query_node = search(Hashtab[index],query_node);

	if ( query_node == NOTEXISTED )
		printf("Record not existed...\n");
	else
	{
		printf("ID : %ld  Name : %s\n",
		query_node->id,query_node->name);
	}
}

/* 顯示節點函數
   從雜湊串列一一尋找是否有節點存在 */
void show()
{
	int i;
	Student *ptr;

	puts("ID                  NAME");
	puts("------------------------");
	for ( i = 0; i < MAX_NUM;i++ )
	{
		/* 串列不為空，則將整串列顯示出*/
		if ( Hashtab[i] != NULL )
		{
			ptr = Hashtab[i];
			while (ptr) {
				printf("%-5ld    %15s\n",ptr->id,ptr->name);
				ptr = ptr->link;
			}
		}
	}
}