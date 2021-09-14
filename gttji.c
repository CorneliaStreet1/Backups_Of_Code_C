#include<stdio.h>
int main(void)
{
    int student,num,i=1,x_0=0,x_1=0,x_2=0,x_3=0,x_4=0,x_5=0,x_6=0,x_7=0;
    scanf("%d",&student);
    while(i<=student){
        scanf("%d",&num);
        i++;
        if(num==0){
            x_0++;
        }
        else if(num==1){
            x_1++;
        }
        else if(num==2){
            x_2++;
        }
        else if(num==3){
            int x_3;
        }
        else if(num==4){
            x_4++;
        }
        else if(num==5){
            x_5++;
        }
        else if(num==6){
            x_6++;
        }
        else if(num==7){
            x_7++;
        }
    }
    if(x_7!=0)
    printf("7:%d\n",x_7);
    if(x_6!=0)
    printf("6:%d\n",x_6);
    if(x_5!=0)
    printf("5:%d\n",x_5);
    if(x_4!=0)
    printf("4:%d\n",x_4);
    if(x_3!=0)
    printf("3:%d\n",x_3);
    if(x_2!=0)
    printf("2:%d\n",x_2);
    if(x_1!=0)
    printf("1:%d\n",x_1);
    if(x_0!=0)
    printf("0:%d\n",x_0);
    return 0;
}