#include <stdio.h>
#include <string.h>
#include <float.h>

#define gallon 3.785
#define mile 1.609
void main()
{
    /*�ݵ��D*/
    /* 04-01d */
    printf("Is %2.3e the same as %2.2f?\n", 1201.0, 1201.0 );

    /* 04-05 */
    printf("%0.2f  %0.0f\n\n", 12.99, 80.0);



    /*�{���D*/
#if 0
    /* 04-01 */
    printf("Here is 04-01\n");
    char firstname[10], secondname[10];
    printf("Please keyin your full name.\n");
    scanf("%s %s", firstname, secondname);
    printf("your last name is : %s\nfirst name is : %s\n\n", secondname, firstname);
#endif

#if 0
    /* 04-02 */
    printf("Here is 04-02\n");
    char name[20];
    int namesize=0;
    printf("Please keyin your name.\n");
    scanf("%s", name);
    printf("2.a answer is \"%s\"\n", name);
    printf("2.b answer is \"%20s\"\n", name);
    printf("2.c answer is \"%-20s\"\n", name);

    namesize=strlen(name)+3;
    printf("namesize is %d\n", namesize);
    printf("2.d answer is \"%*s\"\n", namesize, name);
#endif
#if 0
    /* 04-03 */
    printf("Here is 04-03\n");
    printf("The input is %.1f or %.1e.\n", 21.3, 21.3);
    printf("The input is %.3f or %.3e.\n", 21.29, 21.29);
#endif
#if 0
    /* 04-04 */
    printf("Here is 04-04\n");
    printf("How tall are you?(cm)\n");
    float cm=0, m=0;
    scanf("%f", &cm);
    m=cm/100.0;
    printf("Your Height is %.3f m.\n", m);
#endif
#if 0
    /* 04-05 */
    printf("Here is 04-05\n");
    char firstname[10], secondname[10];
    printf("Please keyin your full name.\n");
    scanf("%s %s", firstname, secondname);
    int first=0, second=0;
    first=strlen(firstname);
    second=strlen(secondname);
    printf("%s %s\n%*d %*d\n", firstname, secondname, first, first, second, second );
    printf("%s %s\n%-*d %-*d\n", firstname, secondname, first, first, second, second );
#endif

#if 0
    /* 04-06 */
    printf("Here is 04-06\n");
    double a=1.0/3.0;
    float b=1.0/3.0;
    printf("double is %.4lf float is %.4f\n", a,b);
    printf("double is %.12lf float is %.12f\n", a,b);
    printf("double is %.16lf float is %.16f\n", a,b);
    printf("DBL_DIG is %d ; FLT_DIG is %d\n\n", DBL_DIG, FLT_DIG );
#endif


    /* 04-07 */
    printf("Here is 04-07\n");
    float road=0, gas=0;
    printf("Please keyin �}�F�h�֭^������\n");
    scanf("%f", &road);
    printf("Please keyin �ΤF�X�[�ڪ��o\n");
    scanf("%f", &gas);
    printf("�}�F %.1f �^������,�ΤF %.1f ���o,�ҥH�C�[�ڶ] %.1f �^��\n", road, gas, road/gas);
    printf("%.1f �^������ %.1f ����, %.1f �[�ڵ��� %.10f ����,�ҥH�C100�����ݭn %.1f ���ɪ��T�o\n", road, road*mile, gas, gas*gallon, ((gas*gallon)/(road*mile))*100.0);


}
