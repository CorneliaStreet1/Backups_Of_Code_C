#include<stdio.h>
int main(void)
{
    long long n,i;
    scanf("%d",&n);
    i=n;   
    while(i>=3){
        n=n*(n-1)*(n-2)+n;
        i--;
    }
    printf("%d",n);
    if((n==1)||(n==2)){
        printf("0");
    }
    return 0;
}