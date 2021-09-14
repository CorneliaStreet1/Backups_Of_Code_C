#include<stdio.h>
int main(void)
{
    int a,b;
    scanf("%d%d",&a,&b);
    if((a > 11)&&(b <11)){
        printf("error\n");
    }
    else if((a < 11)&&(b > 11)){
        printf("error\n");
    }
    else if((a > 11)&&(b > 11)&&(a - b==2)){
        printf("A win\n");
    }
    else if((a >11 )&&(b > 11)&&(b - a ==2)){
        printf("B win\n");
    }
    else if((a < 11)&&(b < 11)){
        printf("no result\n");
    }
    else if((a == 11)&&(b < 11)){
        printf("A win\n");
    }
    else if((b == 11)&&(a < 11)){
        printf("B win\n");
    }
    else if((a == 11)&&(b >11)){
        printf("error\n");
    }
    else if((b == 11)&&(a >11)){
        printf("error\n");
    }
    else
    printf("error");
    return 0;
}