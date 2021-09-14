#include<stdio.h>
int main(void)
{
    int head,leg,ji=0,tu=0,qt=0,con=0;
    scanf("%d%d",&head,&leg);
    while(ji<=head){
        ji++;
        while(tu<=head){
            tu++;
            while(qt<=head){
                qt++;
                if((ji+tu+qt==head)&&(ji*2+tu*4+qt*6==leg)){
                    printf("%d %d %d",ji,tu,qt);
                    con=con+3;
                    if(con%3==0){
                        printf("\n");
                    }
                }
                
            }
        }
        
    }
    return 0;
}