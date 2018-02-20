/*
	Name : matrix.c
	Description : �x�}�ۭ���@
	�N��x�}��C�ۭ����M��J�ĤT�ӯx�}
*/

#include <stdio.h>

#define N 5  /*N x N �x�}*/

void output_Matrix(int [][N]); /*��ܯx�}���e���*/

void main(void)
{
	int A[N][N] = {
		1,2,3,4,5,
		1,2,3,4,5,
		1,2,3,4,5,
		1,2,3,4,5,
		1,2,3,4,5
	};
	int B[N][N] = {
		5,4,3,2,1,
		5,4,3,2,1,
		5,4,3,2,1,
		5,4,3,2,1,
		5,4,3,2,1
	};
	int C[N][N],i,j,k,sum;


	/*	�NA�x�}�C�@�C�����PB�x�}�C�@�C����
		�ۭ����M��JC�x�}���� */
	for ( i = 0; i < N; i++ )
		for ( j = 0; j < N; j++ )
		{
			sum = 0;
			for ( k = 0; k < N; k++ )
				sum = sum + A[i][k] * B[k][j];
			C[i][j] = sum;
		}

	/*�C�X�T�x�}���e*/
	printf("\nContent of Matrix A :\n\n");
	output_Matrix(A);
	printf("\nContent of Matrix B :\n\n");
	output_Matrix(B);
	printf("\nContent of Matrix C :\n\n");
	output_Matrix(C);
}

void output_Matrix(int m[N][N] )
{
	int i,j;

	for ( i = 0; i < N; i++ )
	{
		for ( j = 0; j < N; j++ )
			printf("%5d",m[i][j]);
		printf("\n");
	}
}