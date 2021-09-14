#include<stdio.h>
int main(void)
{
    int speed,speed_max;
    scanf("%d%d",&speed,&speed_max);
    if(speed < speed_max*1.1)
    printf("OK");
    if(speed >= 1.1 * speed_max&&speed < speed_max * 1.5)
    printf("Exceed %d%%. Ticket 200",(speed - speed_max)*100/speed_max);
    if(speed >= 1.5 * speed_max)
    printf("Exceed %d%%. License Revoked",(speed - speed_max)*100/speed_max);
    return 0;
}