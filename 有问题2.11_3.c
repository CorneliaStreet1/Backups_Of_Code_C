#include<stdio.h>
int main(void)
{
    int age;
    int Day;
    printf("your age is:");
    scanf("%d",&age);
    Day = age*365;
    printf("there are %d days in your age %d\n",Day, age);
    return 0;

}