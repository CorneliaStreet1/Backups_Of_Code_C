#include<stdio.h>
#include<math.h>
int main(void)
{
    float a,b,c,d;
    scanf("%f%f%f",&a,&b,&c);
    d = b*b -4*a*c;
    if(a =0)
    printf("The equation is not quadratic.");
    if((d > 0)&&(a > 0)){
        printf("The equation has two distinct real roots:%f and %f.\n",(-b + sqrt(d))/(2*a),(-b - sqrt(d))/(2*a));
    }
    else if((d > 0)&&(a < 0)){
    printf("The equation has two distinct real roots:%f and %f.\n",(-b - sqrt(d))/(2*a),(-b + sqrt(d))/(2*a));
    }
    else if((d < 0)&&(a > 0)){
        printf("The equation has two complex roots:%f and %f.\n",(-b + sqrt(d))/(2*a),(-b - sqrt(d))/(2*a));
    }
    else if((d < 0)&&(a < 0)){
        printf("The equation has two complex roots:%f and %f.\n",(-b - sqrt(d))/(2*a),(-b + sqrt(d))/(2*a));
    }
    return 0;
    }