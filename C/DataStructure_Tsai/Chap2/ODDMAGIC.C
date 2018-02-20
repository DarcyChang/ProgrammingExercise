/*
	Name : oddmagic.c
	Description : ODD Magic Matrix Implementation
	�_���]�N��}��@
*/

#include <stdio.h>
#define MAX	15  /*�x�}�̤j��15 x 15 */

int Square[MAX][MAX];  /*�w�q��Ưx�}*/ 
int N;  /*�x�}��C�j�p�ܼ�*/	

void Magic();
void main()
{
	int i,j;

	/*Ū���]�N�x�}���j�pN,N ���_�ƥB0 <= N <= 15 */
	do {
		printf("\nEnter odd matrix size : ");
		scanf("%d",&N);
		if ( N % 2 == 0 || N<= 0 || N >15)
			printf("Should be > 0 and < 15 odd number");
		else
			break;
	} while (1);


	Magic();  /*�Nsquare �ܬ�N x N ���]�N�x�}*/

	/*����]�N�x�}���G*/
	printf("\nThe %d*%d Magic Matrix\n",N,N);
	printf("-------------------------\n");
	for ( i = 0; i < N; i++ )
	{
		for ( j = 0; j < N; j++ )
			printf("%3d",Square[i][j]);
		printf("\n");
	}
}

void Magic()
{
	int i,j,p,q,key;

	/*��l�Ưx�}���e,�x�}�����M0 */
	for ( i = 0; i < N; i++ )
		for ( j = 0; j < N; j++ )
			Square[i][j] = 0;

	Square[0][(N -1) /2] = 1; /*�N1��̤ܳW�C������m*/
	key = 2;
	i = 0;
	j = (N-1) / 2;    /* i,j�O���ثe�Ҧb��m*/

	while ( key <= N*N )
	{
		p = (i-1) % N;  /* p,q���U�@�B��m,i,j�U��1������_������*/
		q = ( j-1) % N;
		/* p < 0 (�W�X��}�W��)*/
		if ( p < 0 )  p = N - 1; /* �h�Np ����N -1(�̤U�C) */
		if ( q < 0 )  q = N - 1; /* q < 0 (�W�X��}����) */
		/* �h�Nq ����N -1(�̥k��) */
		if ( Square[p][q] != 0 )  /*�P�_�U�@�B�O�_�w���Ʀr*/
			i = (i + 1) % N;  /*�w���h i ���U ( ��b��ȤU��*/
		else {
			i = p;  /*�N�U�@�B��massing���ثe��m */
			j = q;
		}
		Square[i][j] = key;
		key++;
	}
}