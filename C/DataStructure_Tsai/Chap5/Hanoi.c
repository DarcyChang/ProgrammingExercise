/* 
	Name : Hanoi.c

	Description : �Q�Ψ�ƻ��j�k�D�e������D����

	Rules :
		�e������D�ت��D�b�T�ڬW�l��,�Nn�ӽL�l�q
		A �W�l�h�� C �W��,�C���u���ʤ@�L�l,�ӥB������u
		�C�ӽL�l�����W�����L�l�٭n�j����h�C

	Ans :
		�e������D���Q�k�����w��̩��ݪ��L�l�C
		�ڭ̥�������A�W�l����n-1�ӽL�l�Q��k(�ɧUC�W)����B�W�l
		�M��~��N�Q�̩��ݪ��L�l����C�W�C
		����C���̤j���L�l,B�`�@n-1�ӽL�l,A�W�h�L�C
		�u�n�A�ɧUA�W�l�A�NB�Wn-1�ӽL�l����C�W�Y�i :
 
		HanoiTower(n-1,A,C,B);
		�NA����n-1�ӽL�l�ɧUC����B
		HanoiTower(n-1,B,A,C);
		�NB�W��n-1�ӽL�l�ɧUA����C
*/

#include <stdio.h>
#include <conio.h>

/* ��ƭ쫬�ŧi */
void HanoiTower(int ,char,char,char);

void main()
{

	int n;
	char A = 'A' , B = 'B' , C = 'C';

	printf("-----Hanoi Tower Implementaion----\n");
	/*��J�@���X�ӽL�l�bA�W�l��*/
	printf("How many disks in A ? ");
	scanf("%d",&n);
	if ( n == 0 )
		printf("no disk to move\n");
	else
		HanoiTower(n,A,B,C);
}


/* ���j��ƩI�s�D�e���𤧸� */
void HanoiTower(int n,char a,char b,char c)
{
	if ( n == 1 )
		printf("Move disk from %c -> %c\n",a,c);
	else
	{
		/*�NA�Wn-1�ӽL�l�ɧUC����B */
		HanoiTower(n-1,a,c,b);
		printf("Move disk from %c -> %c\n",a,c);
		/*�NB�Wn-1�ӽL�l�ɧUA����C */
		HanoiTower(n-1,b,a,c);
	}
}
