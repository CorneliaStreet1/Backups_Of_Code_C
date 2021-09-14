#include<stdio.h>
int F(int n);
int main(void)
{
    int n;
    scanf("%d",&n);
    printf("%d",F(n));
    return 0;
}
int F(int n)
{
    if(n == 1||n == 0){
        return 1;
    }
    else
    return F(n - 1) + F(n - 2); 
}