#include<stdio.h>
double fact(int n);
int main(void)
{
    int m,n;
    scanf("%d%d",&m,&n);
    double result;
    int a,b,c;
    a = fact(n);
    b = fact(m);
    c = fact(n-m);
    printf("result = %d",1.0*a/(b*c));
    return 0;
}
double fact(int n)
{
    int i=1,fact=1;
    while(i<n){
        i++;
        fact = fact * i;
    }
    return fact;
}    