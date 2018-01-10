/*
	Name : LifeGame.c
	Description : Game of Life Implementation
	�ͩR�ӭM�C����@


	�Y�@�ӭM�F�~�D�b�䫫���B�����B�﨤�u�۾F���ӭM(cells)

	Game of life rules :
	�t�榺 : �Y�@���ӭM�u���@�өΨS���F�~�ӭM�s���� 
			 �h�b�U�@�N�A���N�t��Ӧ��C
	������ : �@���ӭM���|�өΥ|�ӥH�W�F�~��O����
			 �h�b�U�@�N�A���N�]�����Ӧ��C
	í�w   : �@���ӭM���G�өΤT�Ӭ۾F���ӭM
			 �h�U�@�N���N�~��ͦs�C
	�_��   : �@���ӭM���T�Ӭ۾F�����ӭM
			 �h�U�@�N���N�_���C

	�ѤW�W�h�o :
		��0,1,4,5,6,7,8 �Ӭ۾F���ӭM��
		�b�U�@�N�N�]�t��ιL�����Ӧ��C
		��2�Ӭ۾F���ӭM�̤U�@�N�|�~��䪬�A���|���ܡC
		��3�Ӭ۾F���ӭM�̤��ި�{�b�O�ͬO���A�U�@�N�@�w�|�������C
*/

#include <stdio.h>
#include <conio.h>
#include <ctype.h>

#define MAXROW 10
#define MAXCOL 25
#define DEAD 0
#define ALIVE 1

int map[MAXROW][MAXCOL], newmap[MAXROW][MAXCOL];
int Generation;

/*��ƭ쫬�ŧi*/
void init();
int Neighbors();
void output_map();
void Copymap();

void main()
{
	int row ,col;
	char ans;

	init();   /*�_�lmap */
	output_map();

	do
	{
		/*	�p��C�@��(row,col)��cell ���F�~�Ӽ�
			�̦��ӼƨM�w��U�@�N�O�ͬO���C
			�N�U�@�N��map�Ȧs�bnewmap�H��overwrite map�C
		*/
		for ( row = 0; row < MAXROW; row++ )
			for ( col = 0; col < MAXCOL; col++ )
				switch(Neighbors(row,col) )
				{
					case 0 :
					case 1 :
					case 4 :
					case 5 :
					case 6 :
					case 7 :
					case 8 :
						newmap[row][col] = DEAD;
						break;
					case 2 :
						newmap[row][col] = map[row][col];
						break;
					case 3 :
						newmap[row][col] = ALIVE;
						break;
				}
		Copymap();  /*�Nnewmap copy to map */

		do {
			printf("\nContinue next Generation ? ");
			ans = toupper(getche());
			if ( ans == 'Y' || ans == 'N' )
				break;
		} while (1);

		if ( ans == 'Y' ) output_map();

	} while (ans == 'Y');
}

void init()
{
	int row,col;

	/*�_�lmap���A,�@�}�lcells�ҷ|DEAD */
	for ( row = 0; row < MAXROW; row++ )
		for ( col = 0; col < MAXCOL; col++ )
			map[row][col] = DEAD;

	printf("Game of life Program \n");
	printf("Enter (x,y) where (x,y) is a living cell\n");
	printf(" 0 <= x <= %d , 0 <= y <= %d\n",MAXROW-1,MAXCOL-1);
	printf("Terminate with (x,y) = ( -1,-1)\n");

	/*��J���ӭM����m,�H(-1,-1)������J*/
	do
	{
		scanf("%d %d",&row,&col);
		if ( 0 <= row < MAXROW && 0 <= col < MAXCOL)
			map[row][col] = ALIVE;
		else
			printf("(x,y) exceeds map ranage!\n");
	} while ( row != -1 || col != -1 );
}

int Neighbors(int row,int col)
{
	int count = 0,c,r;

	/*	�p��C�@��cell���F�~�Ӽ�
		�]��cell������Q���F�~�p��
		�G�̫��٭n�վ�
	*/

	for ( r = row -1; r <= row +1; r++ )
		for ( c = col -1;  c <= col +1; c++ )
		{
			if (r < 0 || r >= MAXROW || c < 0 || c >= MAXCOL)
				continue;
			if ( map[r][c] == ALIVE )
				count++;
		}
	/*�վ�F�~�Ӽ�*/
	if ( map[row][col] == ALIVE  )
		count--;
	return count;
}


/*��ܥثe�ӭM���A*/
void output_map()
{
	int row ,col;

	printf("\n\n%20cGame of life cell status\n",' ');
	printf("%20c------Generation %d-------\n",' ',++Generation);
	for ( row = 0; row < MAXROW; row++ )
	{
		printf("\n%20c",' ');
		for ( col = 0; col < MAXCOL; col++ )
			if ( map[row][col] == ALIVE )
				putchar('@');
			else
				putchar('-');
	}
}

/*�Nnewmap copy ��map ��*/
void Copymap()
{
	int row , col;

	for ( row = 0; row < MAXROW; row++ )
		for ( col = 0; col < MAXCOL; col++ )
			map[row][col] = newmap[row][col];
}
