/* ����k: �ϥνu�ʱ����k�B�z�I��  */

#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>

#define MAX_NUM 100  /*�̤j��Ƶ���*/
#define PRIME 97  /*�̱���MAX_NUM�����*/

/*�w�q��Ƶ��c*/
typedef struct  Person {
	long  id;
	char name[21];
} Student;

/*�إ������*/
Student Hashtab[MAX_NUM];

/*��ƭ쫬�ŧi*/
long hashfun(long);
void insert();
void del();
void show();
long search();
void solve_collision(Student,long);

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


	/*�M�������id�����e,id��0�N��ӱ��Ū�*/
	for ( i = 0; i< MAX_NUM; i++)
		Hashtab[i].id = 0;

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
				search();
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
	Student node;
	long index;

	/*��J�O��*/
	printf("Enter ID : ");
	scanf("%ld",&node.id);
	printf("Enter Name : ");
	scanf("%s",node.name);

	/*�Q�������ƨ��o�x�s�O����}*/
	index = hashfun(node.id);

	/* �P�_������(index)��}�O�_�w�����
	   0�N��Ӧ�}���šA�_�h�Y�o�͸I�� */
	if ( Hashtab[index].id == 0 )
	{
		Hashtab[index].id = node.id;
		strcpy(Hashtab[index].name,node.name);
		printf("Node insert ok!\n");
	}
	else
		solve_collision(node,index);
}

/* �Q�νu�ʱ����ѨM�I�� */
void solve_collision(Student col_node,long i)
{
	long j;

	j = i;
	while ( Hashtab[j].id != col_node.id && Hashtab[j].id !=0 )
	{
		j = (j+1) % PRIME;  /* �N������������ */
		if ( j == i )
		{
			printf("Hashtab is overflow...\n");
			return;
		}
	}
	/* �P�_�Ӧ�}�O�_�w�����*/
	if ( Hashtab[j].id == 0 )
	{
		Hashtab[j].id = col_node.id;
		strcpy(Hashtab[j].name,col_node.name);
		printf("Node insert ok!\n");
	}
	else
		printf("Record existed in Hashtab!\n");
}

/* ������������� */
/* �q������0��}�l�M��̫ܳ�@�� */
/* �@�@���O�_�ӱ��s���� */
void show()
{
	long i;

	puts("Bucket         ID            Name");
	puts("---------------------------------");
	for ( i = 0; i < MAX_NUM; i++ )
	{
		/*�P�_�Ӧ�}�O�_����� */
		if (Hashtab[i].id != 0 )
		{
			printf("%5ld  %10ld %15s\n",i,Hashtab[i].id,
			Hashtab[i].name);
		}
	}
}

void del()
{
	long index;
	/* ���j�M�O�� */
	index = search();
	/* �P�_�O���O�_�s�b */
	if ( index != 0 )
	{
		printf("Deleting record....\n");
		Hashtab[index].id = 0;
	}
}

/* �j�M�O����� */
long search()
{
	long id,index ,j;

	/* ��J���j�M�O�����ǥ�id */
	printf("Enter ID : ");
	scanf("%ld",&id);
	/* �ഫ�ӰO���b���������} */
	index = hashfun(id);

	j = index;
	while ( Hashtab[j].id != id && j != index )
	{
		j = ( j+1 ) % PRIME;
	}
	/* �P�_��ƬO�_�s�b,���h�Ǧ^�ӰO���b�����
	   ����}�H�@�R����ưѦҡA�_�h�Ǧ^0       */
	if ( Hashtab[j].id == id)
	{
		printf("ID : %ld    Name : %s\n",
		Hashtab[j].id,Hashtab[j].name);
		return j;
	}
	else
	{
		printf("Can't find record !\n");
		return 0;
	}
}
