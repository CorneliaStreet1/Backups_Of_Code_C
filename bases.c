#include<stdio.h>
int main(void)
{
    int x;
    x=100;
    printf("dec = %d,octal = %o ,hex = %x \n",x,x,x);
    printf("dec = %d,octal = %#o,hex = %#x",x,x,x);
    return 0;
}
