/* �Q�ΰ�n��(HEAP TREE)�B�z�|���i�X���--���J�B�x�s�B���J�B�R���B��X */
#include <stdio.h>
#include <conio.h>
#define MAX 100  /* �]�w�W�� */

void load_f(void);    /* ���J��� */
void save_f(void);    /* �x�s��� */
void insert_f(void);  /* ���J��� */
void delete_f(void);  /* �R����� */
void display_f(void); /* ��X��� */
void create(int);     /* �إ߸�Ʃ��n�� */
void removes(int);    /* �q��n�𤤧R����� */
void show(char);      /* �L�X��Ʃ�ù� */
void adjust_u(int [], int);      /* �q�U�ӤW�վ��� */
void adjust_d(int [], int, int); /* �q�W�ӤU�վ��� */
void exchange(int *, int *);     /* �洫��� */
int search(int);                 /* �j�M��� */

int heap_tree[MAX];   /* ��n��}�C */
int last_index = 0;   /* �̫�@����ƪ�INDEX */

void main(void)
{
	char option;
	load_f();
	do
	{
		printf("\n ***************************\n");
		printf("         <1> login\n");
		printf("         <2> logout\n");
		printf("         <3> show\n");
		printf("         <4> quit\n");
		printf(" ***************************\n");
		printf(" Please enter your choice: ");
		option = getche();
		printf("\n");
		switch(option)
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
				save_f();
				break;
			default :
				printf("\n Option error!!\n");
		}
	} while(option != '4');
}

void load_f(void)
{
	FILE *fptr;
	int id_temp;
	if((fptr = fopen("dfile.dat", "r")) == NULL) /* �}�ɥ�����ܿ��~�T�� */
	{
		printf(" File dfile.dat not found!!\n");
		printf(" Loading failure!!\n");
	}
	else
	{
		printf(" Loading...");
		while(fscanf(fptr, "%d", &id_temp) != EOF)
			create(id_temp);  /* �إ߰�n */
		printf("OK\n");
		fclose(fptr);
	}
}

void save_f(void)
{
	FILE *fptr;
	int c_index;
	fptr = fopen("dfile.dat", "w");
	printf("\n Data save...");
	for(c_index = 1; c_index <= last_index; c_index++)
		fprintf(fptr, "%d\n", heap_tree[c_index]);
	printf("OK");
	fclose(fptr);
}

void insert_f(void)
{
	int id_temp;
	if(last_index >= MAX) /* ��ƼƶW�L�W���A��ܿ��~�T�� */
	{
		printf("\n Login members are more than %d!!\n", MAX);
		printf(" Please wait for a minute!!\n");
	}
	else
	{
		printf("\n Please enter login ID number: ");
		scanf("%d", &id_temp);
		create(id_temp);  /* �إ߰�n */
		printf(" Login successfully!!\n");
	}
}

void delete_f(void)
{
	int id_temp, del_index;
	if(last_index < 1)  /* �L��Ʀs�b�A��ܿ��~�T�� */
	{
		printf("\n No member to logout!!\n");
		printf(" Please check again!!\n");
	}
	else
	{
		printf("\n Please enter logout ID number: ");
		scanf("%d", &id_temp);
		del_index = search(id_temp);  /* �M����R����� */
		if(del_index == 0)  /* �S����ơA��ܿ��~�T�� */
			printf(" ID number not found!!\n");
		else
		{
			removes(del_index);  /* �R����ơA�ýվ��n�� */
			printf(" ID number %d logout!!\n", id_temp);
		}
	}
}

void display_f(void)
{
	char option;
	if(last_index < 1)  /* �L��Ʀs�b�A��ܿ��~�T�� */
		printf("\n No member to show!!\n");
	else
	{
		printf("\n ***************************\n");
		printf("        <1> increase\n");  /* ��ܲĤ@�����Ѥp��j�ƦC */
		printf("        <2> decrease\n");  /* ��ܲĤG�����Ѥj��p�ƦC */
		printf(" ***************************\n");
		do
		{
			printf(" Please enter your option: ");
			option = getche();
			printf("\n");
		} while(option != '1' && option != '2');
		show(option);
	}
}

void create(int id_temp)  /* ID_TEMP���s�W��� */
{
	heap_tree[++last_index] = id_temp;  /* �N��Ʒs�W��̫� */
	adjust_u(heap_tree, last_index);    /* �վ�s�W��� */
}

void removes(int index_temp)  /* INDEX_TEMP�����R����Ƥ�INDEX */
{	/* �H�̫�@����ƥN���R����� */
	heap_tree[index_temp] = heap_tree[last_index];
	heap_tree[last_index--] = 0;
	if(last_index > 1)  /* ����Ƶ��Ƥj��1���A�h���վ� */
	{	/* �����N��Ƥj���PARENT NODE�A�h���W�վ� */
		if(heap_tree[index_temp] > heap_tree[index_temp / 2] && index_temp > 1)
			adjust_u(heap_tree, index_temp);
		else /* ���N��Ƥp���CHILDEN NODE�A�h���U�վ� */
			adjust_d(heap_tree, index_temp, last_index-1);
	}
}

void show(char op)
{
	int heap_temp[MAX+1];
	int c_index;
	/* �N��n���ƽƻs��t�@�Ӱ}�C�@�ƧǤu�@ */
	for(c_index = 1; c_index <= last_index; c_index++)
		heap_temp[c_index] = heap_tree[c_index];
	/* �N�}�C�վ㬰�Ѥp��j�ƦC */
	for(c_index = last_index-1; c_index > 0; c_index--)
	{
		exchange(&heap_temp[1], &heap_temp[c_index+1]);
		adjust_d(heap_temp, 1, c_index);
	}
	printf("\n       ID number\n");
	printf(" =====================\n");
	/* ��ܲĤ@�ؤ覡��X�A�H���W�覡��X--�ϥΰ��|
	   ��ܲĤG�ؤ覡��X�A�H����覡��X--�ϥΦ�C */
	switch(op)
	{
		case '1':
			for(c_index = 1; c_index <= last_index; c_index++)
				printf("%14d\n", heap_temp[c_index]);
			break;
		case '2':
			for(c_index = last_index; c_index > 0; c_index--)
				printf("%14d\n", heap_temp[c_index]);
			break;
	}
	printf(" =====================\n");
	printf(" Total member: %d\n", last_index);
}

void adjust_u(int temp[], int index)  /* INDEX���ثe��Ʀb�}�C��INDEX */
{
	while(index > 1)  /* �N��Ʃ��W�վ�ܮڬ��� */
	{
		if(temp[index] <= temp[index/2])  /* ��ƽվ㧹���N���X�A�_�h�洫��� */
			break;
		else
			exchange(&temp[index], &temp[index/2]);
		index /= 2;
	}
}

/* INDEX1���ثe��Ʀb�}�C��INDEX�AINDEX2���̫�@����Ʀb�}�C��INDEX */
void adjust_d(int temp[], int index1, int index2)
{	/* ID_TEMP�O���ثe��ơAINDEX_TEMP�h�O�ثe��Ƥ�CHILDEN NODE��INDEX */
	int id_temp, index_temp;
	id_temp = temp[index1];
	index_temp = index1 * 2;
	/* �������Ƥ�INDEX���j��̫�@����Ƥ�INDEX�A�h�~���� */
	while(index_temp <= index2)
	{
		if((index_temp < index2) && (temp[index_temp] < temp[index_temp+1]))
			index_temp++;  /* INDEX_TEMP�O���ثe��Ƥ�CHILDEN NODE�����j�� */
		if(id_temp >= temp[index_temp])  /* ��������h���X�A�_�h�洫��� */
			break;
		else
		{
			temp[index_temp/2] = temp[index_temp];
			index_temp *= 2;
		}
	}
	temp[index_temp/2] = id_temp;
}

void exchange(int *id1, int *id2)  /* �洫�ǨӤ�ID1��ID2�x�s����� */
{
	int id_temp;
	id_temp = *id1;
	*id1 = *id2;
	*id2 = id_temp;
}

int search(int id_temp)  /* �M��}�C��ID_TEMP�Ҧb */
{
	int c_index;
	for(c_index = 1; c_index <= MAX; c_index++)
		if(id_temp == heap_tree[c_index])
			return c_index;  /* ���h�^�Ǹ�Ʀb�}�C����INDEX */
	return 0;  /* �S���h�^��0 */
}