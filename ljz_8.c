#include<stdio.h>
int main(void)
{
    int a,b,c;
    scanf("%d%d",&a,&b);
    c=a*b;
    int k=c;
    int counter=0;//求c的位数
    while(k !=0){
        k=k/10;
        counter++;
    }
    //注意上方求c的位数的代码在c==0时是会输出0位的
    //下方是功能实现区
    int digit,i=1;
    while(i<=counter){
        digit=c%10;
        if(c<10)
        printf("%d",c);
        else printf("%d",digit);
        c=c/10;
        i++;
    }
    return 0;
}