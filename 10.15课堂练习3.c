#include<stdio.h>
int main(void)
{
    int a,b,c,d,e;
    scanf("%d%d%d%d",&a,&b,&c,&d);
    if(a+b+c+d<20)
    printf("%d",a+b+c+d+10);
    else
    {
        if(a+b+c+d>=20&&a+b+c+d<30)
        printf("%d",a+b+c+d+8);
        else
        {
            if(a+b+c+d>=30&&a+b+c+d<40)
            printf("%d",a+b+c+d+5);
            else
            {
                if(a+b+c+d>=40)
                printf("%d",a+b+c+d);
            }
        }
        return 0;
    }
    
}