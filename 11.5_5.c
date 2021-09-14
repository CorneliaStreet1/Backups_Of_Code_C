#include<stdio.h>
int main(void)
{
    float n,cost;
    scanf("%f",&n);
    if(n>=0.0&&n<=50.0){
        printf("cost = %.2f",n*0.53);
    }
    else if (n>50){
        printf("cost = %.2f",50*0.53+(n-50)*0.58);
    }
    else
    printf("Invalid Value!\n");
    return 0;
}