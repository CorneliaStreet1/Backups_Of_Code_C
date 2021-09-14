#include<stdio.h>
int main(void)
{
    int n,count = 0,sum = 0,points;
    double average;
    scanf("%d",&n);
    if(n == 0){
        printf("average = 0.0\ncount = 0");
    }
    else if(n != 0){
    int i = 1;
    for(i = 1;i <= n;i++){
        scanf("%d",&points);
        sum = sum + points;
        if(points >= 60){
            count ++;
        }
    }}
    if(n != 0)
    printf("average = %.1f\ncount = %d",1.0 * sum / n,count);
    return 0;
}

