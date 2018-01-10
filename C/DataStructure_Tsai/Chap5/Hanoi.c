/* 
	Name : Hanoi.c

	Description : 利用函數遞迴法求河內塔問題之解

	Rules :
		河內塔問題目的乃在三根柱子中,將n個盤子從
		A 柱子搬到 C 柱中,每次只移動一盤子,而且必須遵守
		每個盤子都比其上面的盤子還要大的原則。

	Ans :
		河內塔問題的想法必須針對最底端的盤子。
		我們必須先把A柱子頂端n-1個盤子想辦法(借助C柱)移至B柱子
		然後才能將想最底端的盤子移至C柱。
		此時C有最大的盤子,B總共n-1個盤子,A柱則無。
		只要再借助A柱子，將B柱n-1個盤子移往C柱即可 :
 
		HanoiTower(n-1,A,C,B);
		將A頂端n-1個盤子借助C移至B
		HanoiTower(n-1,B,A,C);
		將B上的n-1個盤子借助A移至C
*/

#include <stdio.h>
#include <conio.h>

/* 函數原型宣告 */
void HanoiTower(int ,char,char,char);

void main()
{

	int n;
	char A = 'A' , B = 'B' , C = 'C';

	printf("-----Hanoi Tower Implementaion----\n");
	/*輸入共有幾個盤子在A柱子中*/
	printf("How many disks in A ? ");
	scanf("%d",&n);
	if ( n == 0 )
		printf("no disk to move\n");
	else
		HanoiTower(n,A,B,C);
}


/* 遞迴函數呼叫求河內塔之解 */
void HanoiTower(int n,char a,char b,char c)
{
	if ( n == 1 )
		printf("Move disk from %c -> %c\n",a,c);
	else
	{
		/*將A上n-1個盤子借助C移至B */
		HanoiTower(n-1,a,c,b);
		printf("Move disk from %c -> %c\n",a,c);
		/*將B上n-1個盤子借助A移至C */
		HanoiTower(n-1,b,a,c);
	}
}
