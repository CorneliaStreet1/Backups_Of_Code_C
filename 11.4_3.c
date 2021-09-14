#include<stdio.h>
int main(void)
{
    int n;
    scanf("%d",&n);
    int i=1;
    double sum=0.0;
    for(i=1;i <= 2*n-1;i=i+2){
        sum = sum + 1.0/i;
    }
    printf("sum = %.6f",sum);
    return 0;
}