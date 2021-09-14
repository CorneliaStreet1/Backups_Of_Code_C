#include<stdio.h>
#include<math.h>//用sqrt（）求平方根
float length(float x1,float x2,float y1,float y2);//定义一个求两点间距离的函数
int main(void)
{
    float x1,y1,x2,y2,x3,y3;
    scanf("%f%f%f%f%f%f",&x1,&y1,&x2,&y2,&x3,&y3);
    if((y1 - y2) / (x1 - x2) == (y3 - y2) / (x3 - x2)||(x1 == x2&&x2 == x3) )//排除三点共线的情况
    printf("Impossible\n");
    else{
        float l,a;
        l = length(x1,x2,y1,y2) + length(x1,x3,y1,y3) + length(x2,x3,y2,y3);
        a =x1*y2 - x1*y3 + x2*y3 - x2*y1 + x3*y1 - x2*y2;//三角形面积公式，别问怎么来的，问就是百度
        printf("L = %.2f, A = %.2f",l,a);
    }
    return 0;
}
float length(float x1,float x2,float y1,float y2)
{
    float length;
    length = sqrt((x1 - x2) * (x1 - x2) + (y1-y2) * (y1 - y2));
    return length;
}