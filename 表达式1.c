#include<stdio.h>
int main(void)
{
    double a,b,c,d;
    scanf("%f%f%f%f",&a,&b,&c,&d);
    if(b*c -d==0){
        printf("error");
    }
    else{
        printf("%f",a/(b*c-d));
    }
    return 0;
}