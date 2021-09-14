/*#include<stdio.h>
int main(void)
{
    double x;
    scanf("%f",&x);
    if(x==0)
        printf("f(%.1f)=0.0",x);
    else if(x != 0)
        printf("f(%.1f)=%.1f",x,1/x);
    return 0;
}*/
#include<stdio.h>
int main(void)
{
    int a,b;
    scanf("%d%d",&a,&b);
    printf("%d + %d= %d\n",a,b,a+b);
    printf("%d - %d= %d\n",a,b,a-b);
    printf("%d * %d= %d\n",a,b,a*b);
    printf("%d / %d= %d\n",a,b,a/b);
    return 0;
    
}