#include<stdio.h>
int fact(int n);
int main(void)
{
    int n;
    scanf("%d",&n);
    int i = 1;
    int sum = 0;
    for(i = 1;i <= n;i++){
        sum = sum +fact(i);
    }
    printf("%d",sum);
    return 0;
}
int fact(int n)
{
    int fact = 1;
    int i = 1;
    for(i = 1;i <= n;i++){
        fact = fact * i;
    }
    return fact;
}