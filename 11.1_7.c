#include<stdio.h>
int main(void)
{
    unsigned long long n,m;
    scanf("%lld",n);
    if(n<=9){
        m=n;
        printf("%d",m);
    }
    else if(n>=10&&n<=99){
        m=9+2*(n-9);
        printf("%d",m);
    }
    else if(n>=100&&n<=999){
        m=189+3*(n-99);
        printf("%d",m);
    }
    else if(n>=1000&&n<=9999){
        m=2889+4*(n-999);
        printf("%d",m);
    }
    else if(n>=10000&&n<=99999){
        m=38889+5*(n-9999);
        printf("%d",m);
    }
    else if(n>=100000&&n<=999999){
        m=488889+6*(n-99999);
        printf("%d",m);
    }
    else if(n>=1000000&&n<=9999999){
        m=5888889+7*(n-999999);
        printf("%d",m);
    }
    else if(n=10000000){
        m=68888889+8*(n-9999999);
        printf("%d",m);
    }
    return 0;
}