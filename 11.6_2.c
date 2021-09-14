#include<stdio.h>
int main(void)
{
    int year,i;
    scanf("%d",&year);
    i = 2001;
    int num = 0;
    if(year > 2099||year <= 2000){
        printf("Invalid year!");
    }   
    else if(year > 2000&&year <= 2099){
        while(i <= year){
            if((i % 4 ==0&&i %100 != 0)||i % 400 ==0){
                printf("%d\n",i);
                num ++;
            }
            i ++;
        }
        if(num == 0){
            printf("None");
        }
        return 0;
    }
}