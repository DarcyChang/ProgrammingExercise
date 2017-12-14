#include <stdio.h>
#include <string.h>

#define TEMP_SET_POINT 30

int main()
{
	int i_week = 0, j_day = 0;
	int temperature[4][7]={/* Sun, Mon, Tue, Wen, Thu, Fri, Sat*/
				/* week 1*/	{10,20,30,30,40,50,40},
				/* week 2*/	{1,2,3,4,5,6,7},
				/* week 3*/	{31,32,33,34,35,36,37},
				/* week 4*/	{47,48,49,50,4,10,20}};

	printf("\nFollowing days' temperature more than 30.\n");
	for(i_week = 0; i_week<4; i_week++){
		for(j_day = 0; j_day<7; j_day++){
//			printf("temperature[%d][%d] = %d\n", i_week, j_day, temperature[i_week][j_day]); // For test
			if(temperature[i_week][j_day] > TEMP_SET_POINT){
				switch(i_week){
					case 0:
						printf("Week 1 : ");
						break;
					case 1:
						printf("Week 2 : ");
						break;
					case 2:
						printf("Week 3 : ");
						break;
					case 3:
						printf("Week 4 : ");
						break;
				}
				switch(j_day){
					case 0:
						printf("Sunday\n");
						break;
					case 1:
						printf("Monday\n");
						break;
					case 2:
						printf("Tuesday\n");
						break;
					case 3:
						printf("Wednesday\n");
						break;
					case 4:
						printf("Thursday\n");
						break;
					case 5:
						printf("Friday\n");
						break;
					case 6:
						printf("Saturday\n");
						break;
				}
			}
		}
	}
	return 0;
}
