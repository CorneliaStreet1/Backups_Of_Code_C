#include<stdio.h>
int main(void)
{
    int scores;
    scanf("%d",&scores);
    if(scores >= 90)
    printf("A");
    if(scores < 90&&scores >= 80)
    printf("B");
    if(scores < 80&&scores >= 70)
    printf("C");
    if(scores < 70&&scores >= 60)
    printf("D");
    if(scores < 60&&scores >= 0)
    printf("E");
    return 0;
}