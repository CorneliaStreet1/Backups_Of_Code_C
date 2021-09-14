#include<stdio.h>
int main(void)
{
    int gas,kind;
    double money;
    char type,space;
    scanf("%d%d",&gas,&kind);
    getchar();
    scanf("%c",&type);
    if(kind==90&&type=='m')
    money=6.95*gas*0.95;
    else if(kind==90&&type=='e')
    money=6.95*gas*0.97;
    else if(kind==97&&type=='m')
    money=7.93*gas*0.95;
    else if(kind==97&&type=='e')
    money=7.93*gas*0.97;
    else if(kind==93&&type=='m')
    money=7.44*gas*0.95;
    else if(kind==93&&type=='e')
    money=7.44*gas*0.97;
    printf("%.2f",money);
    return 0;
}