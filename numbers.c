#include<stdio.h>
int main(void)
{
    int n,m,i=0,result,digit_1,digit_10,digit_100,digit_1000,count=1;
    scanf("%d%d",&n,&m);
    while(i <n){
        i++;
        result = i / m;
        digit_1=i%10;
        digit_10=(i/10)%10;
        digit_100=(i/100)%10;
        digit_1000=(i/1000)%10;
        if(result==digit_1 * digit_1+digit_10 * digit_10+digit_100 * digit_100+digit_1000*digit_1000&&count%5!=0){
            printf("%d  ",i);
            count++;
        }
        else if(result==digit_1 * digit_1+digit_10 * digit_10+digit_100 * digit_100+digit_1000*digit_1000&&count%5==0){
            printf("%d\n",i);
            count++;
        }
    }
    return 0;
}