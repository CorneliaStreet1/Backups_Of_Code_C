#include<stdio.h>
void a(int );
int main(void)
{
    int n ;
    scanf("%d", &n);
    a(n);
    return 0;
}
void a(int n)
{
    for(int i = 1 ; i <= n ;i ++){
        printf("%d ",i);
    }
}
/*void a(int n)
{
    if(n){
         a(n - 1);  
         printf("%d " ,n);
    } 
}*/