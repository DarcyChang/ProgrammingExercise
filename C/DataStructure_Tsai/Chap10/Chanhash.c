/* ����k : �ϥ��쵲��C�B�z�I��*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>

#define MAX_NUM 100  /*�̤j��Ƶ���*/
#define PRIME 97  /*MAX_NUM�����*/
#define NOTEXISTED NULL

/*�w�q��Ƶ��c*/
typedef struct Person {
	long id;
	char name[21];
	struct Person *link;
} Student;

/*�إ�������C*/
Student *Hashtab[MAX_NUM];

/*��ƭ쫬�ŧi*/
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

	/*�_�l�����C�A�N�U��C���VNULL*/
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

/*  ������:  */
/*  �H���k�B��ǨD�X�O�����x�s����}  */
long hashfun(long key)
{
	return ( key % PRIME );
}

void insert()
{
	Student  *newnode;
	long index;

	/*��J�O��*/
	newnode = ( Student *)malloc(sizeof(Student));
	newnode->link = NULL;
	printf("Enter id : ");
	scanf("%ld",&newnode->id);
	printf("Enter Name : ");
	scanf("%s",newnode->name);

	/*�Q�������ƨD�o�O����}*/
	index = hashfun(newnode->id);
	/*�P�_�Ӧ�C�O�_���šA�Y���ūh�إߦ��쵲��C*/
	if ( Hashtab[index] == NULL )
	{
		Hashtab[index] = newnode;
		printf("Node insert ok!\n");
	}
	else
	{
		/*�j�M�`�I�O�_�w�s�b��C��
		  �p���s�b�h�N���`�I�[�J��C�e��*/
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

/*�R���`�I���*/
void del()
{
	Student *node ,*node_parent;
	long index;

	node = (Student *)malloc(sizeof(Student));
	printf("Enter ID : ");
	scanf("%ld",&node->id);
	/*�Q���������ഫ�O����}*/
	index  =  hashfun(node->id);

	/*�j�M�`�I�O�_�s�b�öǦ^���V�Ӹ`�I����*/
	node  = search(Hashtab[index],node);

	if ( node == NOTEXISTED )
		printf("Record not existed ...\n");
	else
	{
		/*�p�`�I����C���A�h�N��C���VNULL
		  �_�h������`�I�A�ñN���`�Ilink�V�`�I���*/
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

/* �j�M�`�I���
   �p���`�I�h�Ǧ^���V�Ӹ`�I������
   �_�h�Ǧ^NULL  */
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

/*�d�߸`�I���*/
void query()
{
	Student *query_node;
	long index;

	query_node = (Student *)malloc(sizeof(Student));
	printf("Enter ID : ");
	scanf("%ld",&query_node->id);

	index = hashfun(query_node->id);
	/*�j�M�`�I*/
	query_node = search(Hashtab[index],query_node);

	if ( query_node == NOTEXISTED )
		printf("Record not existed...\n");
	else
	{
		printf("ID : %ld  Name : %s\n",
		query_node->id,query_node->name);
	}
}

/* ��ܸ`�I���
   �q�����C�@�@�M��O�_���`�I�s�b */
void show()
{
	int i;
	Student *ptr;

	puts("ID                  NAME");
	puts("------------------------");
	for ( i = 0; i < MAX_NUM;i++ )
	{
		/* ��C�����šA�h�N���C��ܥX*/
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