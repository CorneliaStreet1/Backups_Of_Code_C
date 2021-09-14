#include<stdio.h>
#include<math.h>
int main(void)
{
    int n,i=1,height,weight;
    float standard;
    scanf("%d",&n);
    while(i<=n){
        i++;
        scanf("%d%d",&height,&weight);
        standard=(height-100)*1.8;
        if(fabs(weight*1.0-standard)<0.1*standard){
            printf("You are wan mei!\n");
        }
        else if(weight*1.0-standard>=0.1*standard){
            printf("You are tai pang le!\n");
        }
         else if(-weight*1.0+standard>=0.1*standard){
             printf("You are tai shou le!\n");
         }
    }
    return 0;
}
