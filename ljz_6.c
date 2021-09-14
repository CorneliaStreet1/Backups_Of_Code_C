#include<stdio.h>
int main(void)
{
    int M,N,digit_1,digit_10,digit_100;//个位 十位 百位
    scanf("%d%d",&M,&N);
    int i=M;
    if(N<100||N>999||M>999||M<100||M>N){
        printf("Invalid Value.\n");
    }
    while(i>=M&&i<=N){
        digit_1=i%10;
        digit_10=(i/10)%10;
        digit_100=i/100;
        if(i == digit_1*digit_1*digit_1 + digit_10*digit_10*digit_10+digit_100*digit_100*digit_100){
            printf("%d\n",i);
        }
        i++;
    }
    return 0;
}