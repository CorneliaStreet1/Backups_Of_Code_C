#include<stdio.h>
int main(void)
{
    int n,i = 0;
    scanf("%d",&n);
    int num[n];
    for(i = 0;i <n;i++){
        scanf("%d",&num[i]);
    }
    int max = num[0],min = num[0];
    for(int k = 1;k < n;k ++){
        if(num[k] > max){
            max = num[k];
        }
        else if(num[k] < max){
            max = max;
        }
        else if(num[k] < min){
            min = num[k];
        }
        else if(num[k] > min){
            min = min;
        }
    }
    int numofmax = 0,numofmin = 0;
    for(int j = 0;j < n;j ++){
        if(num[j]== max){
            numofmax = j;
        }
        else if(num[j] == min){
            numofmin = j;
        }
        if(numofmax&&numofmin){
            break;
        }
    }
    printf("min=%d max=%d",min,max);
    return 0;
}