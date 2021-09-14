#include<stdio.h>
#include<math.h>
int main(void)
{
    double sum = 0;
    int n;
    scanf("%d",&n);
    int i = 1;
    for(i = 1;i <= n;i++){
        sum = sum + sqrt(i);
    }
    printf("sum = %.2f",sum);
    return 0;
}