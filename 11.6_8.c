#include<stdio.h>
int main(void)
{
    int scores,num;
    scanf("%d",&num);
    int a=0,b=0,c=0,d=0,e=0,i=1;
    while(i <= num){
        scanf("%d",&scores);
        if(scores >= 90)
        a++;
        if(scores < 90&&scores >= 80)
        b++;
        if(scores < 80&&scores >= 70)
        c++;
        if(scores < 70&&scores >= 60)
        d++;
        if(scores < 60&&scores >= 0)
        e++;
        i++;
    }
    printf("%d %d %d %d %d",a,b,c,d,e);
    return 0;
}