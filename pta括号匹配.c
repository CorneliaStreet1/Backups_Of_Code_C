#include<stdio.h>
int main(void)
{
    char ch[100];
    scanf("%s",ch);
    int a = 0,b = 0;
    int count = 0;
    for(int i = 0 ; i < 100 ; i ++){
        if(ch[i] == '(')
        a ++;
        else if(ch[i] == ')')
        b ++;
        if(b > a)
            count = 1;
    }
    
    if(a == b && a != 0 &&b !=  0){
        printf("parentheses match!\n");
    }
    else if( a != b || count == 1)
    printf("parentheses do not match!\n");
    return 0;
}