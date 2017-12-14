/* chapter 03 exercise */
#include <stdio.h>

int main()
{
    /* data type size */

    printf("data type size\n");
    printf("int size is %d Bytes\n\n", sizeof(int));
    printf("short size is %d Bytes\n\n", sizeof(short));
    printf("long size is %d Bytes\n\n", sizeof(long));
    printf("long long size is %d Bytes\n\n", sizeof(long long));
    printf("char size is %d Bytes\n\n", sizeof(char));

    printf("float size is %d Bytes\n\n", sizeof(float));
    printf("double size is %d Bytes\n\n", sizeof(double));

    /* 03-01 */

    printf("03-01\n");
    int i_a=2147483647;
    float f_a=99999999999999;//99999999999999999999999999999999999999.999999999999999999999999999999999999999999999999999999999;
    printf("int %d+1 overflow is %d \n", i_a,i_a+1);
    printf("float(underflow) %f*9999999999999999 overflow is %f \n\n", f_a, f_a*999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999);

    /* 03-02 */

    printf("03-02\n");
    char c_a;
    printf("Please key in ASCII code number: ");
    scanf("%d", &c_a);
    printf("Number %d ASCII code is %c\n\n",c_a,c_a);

    /* 03-03 */

    printf("03-03\n");
    printf("\a \7");
    printf("Startled by the sudden sound, Sally shouted\n");
    printf("\"By the Great Pumpkin, what was that!\"\n\n");


    /* 03-04 */

    printf("03-04\n");
    float f_b=21.290000;
    printf("The input is %f or %e\n\n", f_b, f_b);

    /* 03-05 */

    printf("03-05\n");
    int i_year;
    printf("How old are you:");
    scanf("%d", &i_year);
    printf("%d year have %d second\n\n",i_year, i_year*365*24*60*60);

    /* 03-06 */
    /* quart用int和%d、%f，輸入1或100，答案都一樣，何解?*/
    /* 宣告型態的問題，要注意型態和輸出對應格式*/
    printf("03-06\n");
    double d_water;
    double d_quart;
    printf("Please key in quart number:");
    scanf("%lf", &d_quart);
//    d_water=(i_quart*950)/3.0e-23;
//    printf(" %lf quart are equal to %lf water\n\n", d_quart, d_water);
    printf(" %lf quart are equal to %lf water\n\n", d_quart, (d_quart*950)/3.0e-23);

    /* 03-07 */

    printf("03-07\n");

    float f_inch,f_cm;
    printf("Please key in your stature for inch:");
    scanf("%f", &f_inch);
    printf("%f inch are equal to %f cm.\n", f_inch,f_inch*2.54);
    printf("Please key in your stature for cm:");
    scanf("%f", &f_cm);
    printf("%f cm are equal to %f inch.\n", f_cm,f_cm/2.54);

    /* exercise end */
    return 0;

}
