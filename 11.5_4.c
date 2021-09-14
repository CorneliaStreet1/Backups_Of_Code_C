#include<stdio.h>
int main(void)
{
    int a,b,c,d;
    scanf("%d%d%d%d",&a,&b,&c,&d);
    printf("Sum = %d;Average = %.1f\n",a+c+b+d,(a+b+c+d)/4.0);
    return 0;
}