#include<stdio.h>
int main(void)
{
    char ch[100];
    gets(ch);
    int i = 0,num = 0;
    while(ch[i] != '\0'){
        if(ch[i] = ' '&&ch[i + 1] != ' '){
            num ++;
        }
        i++;
    }
    num ++;
    printf("%d",num);
    return 0;
}