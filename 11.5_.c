#include<stdio.h>
#include<math.h>
int main(void)
{
    int n,i=1,j=1;
    scanf("%d",&n);
    double sum = 0.0;
    while(j<=n){
      int k=pow(-1,i-1);
        sum = sum + k*(1.0/i);
        i = i + 3;
        j++;
    }
    printf("sum = %.3f",sum);
    return 0;
}