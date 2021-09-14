#include<stdio.h>
int main(void)
{
    const int FREEZE=0;
    float temperature;
    int cold_days=0,all_days=0;
    printf("Enter the list of daily low temperatures\n");
    printf("Use Celsius,and enter q to quit.\n");
    while(scanf("%f",&temperature)==1)
    {
        all_days++;
        if(temperature<FREEZE)
        cold_days++;
    }
    if(all_days!=0)
    

}