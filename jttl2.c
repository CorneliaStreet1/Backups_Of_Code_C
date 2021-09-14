#include<stdio.h>
int main(void)
{
    int head,leg,ji,tu,qt;
    scanf("%d%d",&head,&leg);
    for(ji=0;ji<=head;ji++){
        for(tu=0;tu<=head;tu++){
            for(qt=0;qt<=head;qt++){
                if((ji+tu+qt==head)&&(ji*2+tu*4+qt*6==leg)){
                    printf("%d %d %d\n",ji,tu,qt);
                }
            }
        }
    }
    return 0;
}