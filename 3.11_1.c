/*数据溢出*/
#include<stdio.h>
int main(void)
{
    int a=4294967296;
    float b=3.7e38,c=3.7e-38;
    printf("%d\n,%f,\n%f",a,b,c);
    return 0;
}