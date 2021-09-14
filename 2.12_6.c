#include<stdio.h>
int a(void);
int main(void)
{
    int b = a();
    printf("%d",b);
    return 0;
}
a(void)
{
    float m = 1.222;
    return m;
}