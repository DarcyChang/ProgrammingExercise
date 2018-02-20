/*
	Name : queen.c
	Description : �Q�λ��j�k�D�X8�ӬӦZ���D����
*/
#include <stdio.h>
#include <conio.h>

#define TRUE 1
#define FALSE 0
#define MAXQUEEN 8
#define ABS(x) ((x>0) ?(x): -(x))  /*�Dx�������*/

/*�s��8�ӬӦZ���C��m,�}�C���Ь��ӦZ����ȸm*/
int queen[MAXQUEEN];
int total_solution;  /*�p��@���X�ո�*/

/*��ƭ쫬�ŧi*/
void place(int);
int attack(int,int);
void output_solution();

void main()
{
	place(0);  /*�q��0�ӬӦZ�}�l�\��ܴѽL*/
}

void place(int q)
{
	int i;

	i = 0;
	while ( i < MAXQUEEN )
	{
		if ( !attack(i, q))  /*�ӦZ��������*/
		{
			queen[q] = i;  /*�x�s�ӦZ�Ҧb���C��m*/
			/*�P�_�O�_���@�ո� */
			if ( q == 7 )
				output_solution();  /*�C�X���ո�*/
			else
				place(q+1);  /*�_�h�~���\�U�@�ӬӦZ*/
		}
		i++;
	}
}

/* ���զb(row,col)�W���ӦZ�O�_�D������
   �Y�D�������h�Ǧ^�Ȭ�1�A�_�h�Ǧ^0 */
int attack(int row,int col)
{
	int i,atk = FALSE;
	int offset_row,offset_col;

	i = 0;
	while ( !atk && i < col )
	{
		offset_col = ABS(i - col);
		offset_row = ABS(queen[i] - row);
		/*�P�_��ӦZ�O�_�b�P�@�C,�ӦZ�O�_�b�﨤�u�W*/
		/*�Y�ӦZ�P�C�Φb�﨤�u�W�h���ͧ���,atk ==TRUE */
		atk = (queen[i] == row)||(offset_row == offset_col);
		i++;
	}
	return atk;
}


/*�C�X8�ӬӦZ����*/
void output_solution()
{
	int x,y;

	total_solution+=1;
	printf("Solution #%3d\n\t",total_solution);

	for ( x = 0; x < MAXQUEEN; x++ )
	{
		for ( y =0; y< MAXQUEEN;y++ )
			if ( x == queen[y] )
				printf("Q");
			else
				printf("-");
		printf("\n\t");
	}
	printf("\n");
}