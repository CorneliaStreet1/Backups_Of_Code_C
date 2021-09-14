#include<stdio.h>
int main(void)
{
    float kuatuo,num;
    printf("请输入水的夸脱数");
    scanf("%f",&kuatuo);
    num=kuatuo/3.0e-23;
    printf("%f夸脱水中有%f个水分子",kuatuo,num);
    return 0;
}