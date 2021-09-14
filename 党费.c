#include<stdio.h>
int main(void)
{
    float salary,df;
    scanf("%f",&salary);
    if(salary<=3000){
        df=salary*0.005;
        printf("%.1f",df);
    }
        if(salary>3000&&salary<=5000){
            df=salary*0.01;
            printf("%.1f",df);}
        if(salary>5000&&salary<=10000){
                df=salary*0.015;
                printf("%.1f",df);}
         if(salary>10000){
            df=salary*0.02;
            printf("%.1f",df);
                    }
    return 0;
}