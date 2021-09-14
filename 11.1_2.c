#include<stdio.h>
int main(void)
{
    int n;
    int a,b,c;
    int i=1;
    scanf("%d",&n);
    while(i<=n){
        scanf("%d%d%d",&a,&b,&c);
        if((a>=75)&&(b>=75)&&(c>=75)&&(a+b+c>=240)){
            printf("Yes\n");
        }
        else{
            printf("No\n");
        }
        i++;
    }
    return 0;
}