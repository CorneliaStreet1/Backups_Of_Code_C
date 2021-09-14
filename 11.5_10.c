#include<stdio.h>
#include<math.h>
int main(void)
{
    int m,i = 1,j = 1,l = 1;
    scanf("%d",&m);
    double sum = 0;
    for(l=1;l <= m;l++){
        sum = sum + pow(-1,l-1)*(1.0*i/j);
        i++;
        j = j + 2;
    }
    printf("%.3f",sum);
    return 0;
}