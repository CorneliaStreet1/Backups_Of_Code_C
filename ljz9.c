#include<stdio.h>
int main(void)
{
    char number[100];
    int num = 0,i = 0;
    //scanf("%s",number);
    gets(number);
    for(i = 0;number[i] != '\0';i++){
        if(number[i] != ' '){
            num++;
        }
        else if(number[i] == ' '){
            printf("%d ",num);
            num = 0;
        }
    }
    printf("%d",num);
    return 0;
}