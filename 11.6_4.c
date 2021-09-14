#include<stdio.h>
int main(void)
{
    printf("[1] apple\n[2] pear\n[3] orange\n[4] grape\n[0] exit\n");
    int number;
    int i = 1;
    while(i <= 5){
        scanf("%d",&number);
        if(number == 0){
            break;
        }
        else if(number == 1)
        printf("price = 3.00\n");
        else if(number == 2)
        printf("price = 2.50\n");
        else if(number == 3)
        printf("price = 4.10\n");
        else if(number == 4)
        printf("price = 10.20\n");
        else
        printf("price = 0.00\n");
        i++;
    }
    return 0;
}