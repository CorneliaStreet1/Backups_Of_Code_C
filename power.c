#include<stdio.h>
#include<math.h>
int main(void)
{
    int x,y,i,b;
    scanf("%d%d",&x,&y);
    if(x!=0&&y>=0){
        i = 0;
        do{
            b=pow(x,i);
            i=i+1;
        }
        while(i<=y);
        printf("%d",b);
    }
    return 0;
}
