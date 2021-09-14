#include<stdio.h>
int main(void)
{
    int n;
    int i;
    scanf("%d",&n);
    if(n > 0){
        i =1;
    }
    else if(n == 0){
        i = 0;
    }
    else if(n < 0){
        i = -1;
    }
    printf("sign(%d) = %d",n,i);
    return 0;
}