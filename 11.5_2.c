#include<stdio.h>
#include<math.h>
int main(void)
{
    long i = 0,n,power;
    scanf("%ld",&n);
    while(i <= n){
        power = pow(3,i);
        printf("pow(3,%ld) = %ld\n",i,power);
        i++;
    }
    return 0;
}