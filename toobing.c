#include<stdio.h>
int main(void)
{
    int i=2147483647;/*这是2的31次方减一*/
    unsigned int j= 494967295;/*这是2的32次方减一*/
    printf("%d,%d,%d\n",i,i+1,i+2);
    printf("%u,%u,%u\n",j,j+1,j+2);
    return 0;
}