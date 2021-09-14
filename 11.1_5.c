#include<stdio.h>
int main(void)
{
    int i=0,num,k=0,line,l=1;
    scanf("%d",&line);
    while(l<=line){
        scanf("%d",&num);
        if(num != -1){
        for(k=0;k<=num-1;k++){
            if(num%k !=0){
                i++;
            }
        }
        if(num == -1){
            l++;
        }
    }
    printf("%d",i);
    return 0;
}
