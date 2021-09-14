#include<stdio.h>
int main(void)
{
    int n,a,b,c,num=0;
    scanf("%d",&n);
    for(a=1;a < n;a++){
        for(b=1;b < n;b++){
            for(c=1;c < n;c++)
            if((a + b + c==n)&&(a + b > c)&&(b + c > a)&&(c + a > b))
            num++;
        }
    }
    printf("%d",num);
    return 0;
}