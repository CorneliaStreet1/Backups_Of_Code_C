#include<stdio.h>
int main(void)
{
    int num,i = 0,is = 0;
    scanf("%d",&num);
    while(num != 0){
        i++;
        num = num / 10;
    }
    int number[i];
    int j=0,k=num,digit;
    while (j<i)
    {
        digit = k%10;
        number[j] = digit;
        digit = digit / 10;
        j++;
    }
    if(i % 2 == 0){
        for(int l = 0,p = i - 1;l <= 0.5  *  (i-2);l++,p--){
            if(number[l] == number[p]){
                is = 1;
            }
            else 
            is = 0;
        }
    }    
    if(i % 2 != 0){
        for(int l = 0,p = i - 1;l<= 0.5 * (i - 3);l++,p--){
            if(number[l] == number[p]){
                is = 1;
            }
            else 
            is = 0;
        }
    }
    if(is == 1)
    printf("Yes\n");
    else if(is == 0)
    printf("No\n");
    return 0;
}