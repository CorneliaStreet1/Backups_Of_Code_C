#include<stdio.h>
int main(void)
{
    int x,y,power=1,i=0;
    scanf("%d%d",&x,&y);
    while(i<y){
        power=power * x;
        i++;
    }
    printf("%d",power);
    return 0;
}