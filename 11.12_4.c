#include<stdio.h>
int main(void)
{
    int number;
    int a;
    scanf("%d",&number);
    int i = 1;
    int min;
    scanf("%d",&min);
    while(i < number){
        scanf("%d",&a);
        if(a > min){
            min = min;
        }
        else
        min = a;
        i ++;
    }
    printf("min = %d",min);
    return 0;
}