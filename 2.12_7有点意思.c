#include<stdio.h>
int main(void)
{
    int lotteryOdds;
    int k = 50,n = 6;
    for(int i = 1 ; i <= k ; i++){
            lotteryOdds = lotteryOdds * (n - i + 1) / i;
    }
    printf("%d",lotteryOdds);
    return 0;
}
