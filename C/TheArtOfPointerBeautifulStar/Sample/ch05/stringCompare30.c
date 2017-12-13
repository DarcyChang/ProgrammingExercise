/* stringCompare30.c */
#include <stdio.h>
#include <stdlib.h> 

int main()
{
	char *str1 = (char *)malloc(20);
    str1 =  "Honda Civic";
	char *str2 = (char *)malloc(20);
    str2 = "Honda Civic";
	char *str3 = (char *)malloc(20);
    str3 = "Honda Accord"; 
 
	printf("str1: %x\n", str1);
	printf("str2: %x\n", str2);
	printf("str3: %x\n", str3);

    if (str1 == str2)
    	printf("str1 ㎝ str2琌单\n");
    else
        printf("str1 ㎝ str2琌ぃ单\n");
        
    if (str1 == str3)
    	printf("str1 ㎝ str3琌单\n");
    else
        printf("str1 ㎝ str3琌ぃ单\n");
    system("PAUSE");
    return 0;
}
 
