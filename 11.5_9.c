#include<stdio.h>
int main(void)
{
    int m,n,i;
    scanf("%d%d",&m,&n);
    double sum=0;
    for(i=m;i<=n;i++){
        sum = sum + i*i +1.0/i;
    }
    printf("sum = %.6f",sum);
    return 0;
}