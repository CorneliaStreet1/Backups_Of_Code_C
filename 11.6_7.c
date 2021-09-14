#include<stdio.h>
int main(void)
{
    float miles,moneyofmiles,moneyoftime;
    int min;
    scanf("%f%d",&miles,&min);
    if(miles <= 3.0){
        moneyofmiles = 10;
    }
    else if(miles >3&&miles <= 10){
        moneyofmiles = 10 +(miles - 3) * 2;
    }
    else if(miles > 10){
        moneyofmiles = 24 + (miles - 10) * 3;
    }
    moneyoftime = min / 5*2;
    float money = moneyofmiles +moneyoftime;
    printf("%f",money);
    return 0;
}