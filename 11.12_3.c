#include<stdio.h>
unsigned long long fact(int n);
int main(void)
{
    double sum = 1;
    int i = 1;
    int num;
    scanf("%d",&num);
    while(i <= num ){
        sum = sum + 1.0/fact(i);
        i ++;
    }  
    printf("%.8f",sum);
    return 0;
}
unsigned long long fact(int i)
{
    unsigned long long fact = 1;
    for(int k = 1;k <= i;k++){
        fact = fact * k;
    }
    return fact;
}
