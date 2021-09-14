#include<stdio.h>
int main(void)
{
    int num,unit,digit_100,digit_10;
    scanf("%d",&num);
    if(num%10!=0){
    unit=num%10;
    digit_100=num/100;
    digit_10=(num/10)%10;
    printf("%d",unit*100+digit_10*10+digit_100);
    }
    else{
        printf("The number cannot be changed.\n");
    }
    return 0;
}