/* stringCompare20.c */
#include <stdio.h>
#include <stdlib.h> 

int main()
{
	char *str1 = "Honda Civic";
	char *str2 = "Honda Civic";
	char *str3 = "Honda Accord"; 
 
	printf("str1���V����}: %x\n", str1);
	printf("str2���V����}: %x\n", str2);
	printf("str3���V����}: %x\n", str3);

    if (str1 == str2)
    	printf("str1 �M str2�O�۵���\n");
    else
        printf("str1 �M str2�O���۵���\n");
        
    if (str1 == str3)
    	printf("str1 �M str3�O�۵���\n");
    else
        printf("str1 �M str3�O���۵���\n");
    system("PAUSE");
    return 0;
}
 
