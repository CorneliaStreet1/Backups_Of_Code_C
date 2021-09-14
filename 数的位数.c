#include<stdio.h>
int main(void)
{
        int c=0,counter=0;//c的位数,且c初始值不能为零
        scanf("%d",&c);
    while(c !=0){
        c=c/10;
        counter++;
    }
    printf("%d",counter);
    return 0;
}