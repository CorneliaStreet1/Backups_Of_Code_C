#include<stdio.h>
#include<math.h>
int main(void)
{
    double sum = 0,eps;
    int i = 1;
    scanf("%lf",&eps);
    do{
        sum =  sum + pow(-1,i - 1) / i;
        i = i + 3;
    }while(1.0 / i > eps);
    sum = sum + pow(-1,i - 1) / i;
    printf("sum = %.6f",sum);
    return 0;
}