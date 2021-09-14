#include<stdio.h>
int isprime(int n);
int main(void)
{
    int m,n;
    scanf("%d%d",&m,&n);
    int i = m;
    int count = 0,sum = 0;
    while(i <= n){
        if(isprime(i)){
            count ++;
            sum =  sum + i;
        }
        i ++;
    }
    printf("%d %d",count,sum);
    return 0;
}
int isprime(int i)
{
   int isprime = 1;
   int k = 2;
   if(i == 1)
   isprime = 0;
   while(k < i){
       if(i % k == 0){
           isprime = 0;
           break;
       }
       else
       {
           isprime = 1;
       }
       k ++;    
   }
   return isprime;
}