#include<stdio.h>
int main(void)
{
    float inch,cm;
    printf("please enter your height in inch:");
    scanf("%f",&inch);
    cm=inch*2.54;
    printf("your height in cm is %f cm",cm);
    return 0;
}