#include<stdio.h>
int main(void)
{
    int a,b,c,d,e,f,g;
    float average;
    scanf("%d%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f,&g);
    average = 1.0*(a+b+c+d+e+f+g)/7.0;
    if(average>90){
        printf("A:%.1f",average);
    }
    else if(average<=90&&average>70){
        printf("B:%.1f",average);
    }
    else if(average<=70&&average>50){
        printf("C:%.1f",average);
    }
    else if(average<=50){
        printf("D:%.1f",average);
    }
    return 0;
}    