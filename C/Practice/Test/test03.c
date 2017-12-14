#if 0
 
x= 8.38860800E+006
請按任意鍵繼續 . . .
num1=123
num2=380000
請按任意鍵繼續 . . .
 
#endif
// ----------------------------------------------
  
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
   
int main()
{
       	float num1 = 123.39f, x, y, z;
       	float num2 = 3.8e5f;
       	int a , b ;           
	x= pow(2.0, 23.0);
	printf("\n x= %.8lE \n", x);
//        system("pause");// float 變數型態的精確度，只有 這麼多 
// ------------------------------------------
                                       
        a= (int) (num1 + 0.5);
        b= (int) (num2 + 0.5);
                                                   
        printf("num1=%i\n" ,a );
        printf("num2=%i\n" ,b );
//        system("pause");
        return(0);
}// end of main()
