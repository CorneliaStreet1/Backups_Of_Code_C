#include<stdio.h>
int main(void)
{
    int n,i=1;
    scanf("%d",&n);
    double sum=0.0;
    for(i=1;i<=n;i++){
        sum=sum + 1.0/i;
    }
    printf("sum = %.6f",sum);
    return 0;
}