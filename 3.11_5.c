#include<stdio.h>
int main(void)
{
    int age,seconds;
    printf("输入你的年龄：");
    scanf("%d",&age);
    seconds=age*3.156e7;
    printf("there are %d seconds in your age",seconds);
    return 0;
}