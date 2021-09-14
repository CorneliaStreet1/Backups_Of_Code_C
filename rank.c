#include<stdio.h>
int main(void)
{
    int score;
    scanf("%d",&score);
    if((score >= 90)&&(score <= 100)){
        printf("A\n");
    }
    else if((score < 90)&&(score >= 80))
    printf("B\n");
    else if((score >= 70)&&(score < 80))
    printf("C\n");
    else if((score >= 60)&&(score < 70))
    printf("D\n");
    else if((score < 60)&&(score>=0))
    printf("E\n");
    else if((score < 0)||(score > 100))
    printf("The score is out of range!\n");
}