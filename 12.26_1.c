#include<stdio.h>
#include<string.h>
int main(void)
{
    char string[100000];
    char *str[100] = {str[0] = &string[0]};
    int n,i = 0,p = 1;
    scanf("%d",&n);
    for(int y = 0 ; y < n + 1 ; y ++ ){
        gets(string);
    }
    int len = strlen(string);
    for(int j = 0 ; j < len + 1 ;j ++){
        if(string[j] == '\n'){
            str[p] = &string[j];
            p ++;
        }
    }
    for(int i = 0 ; i <= p ; i ++){
        for(int l = 0 ; l < p -i - 1; l ++){
            int big = strcmp(str[l] , str[l + 1]);
            if(big > 0){
                char * temp = str[l];
                str[l] = str[l + 1];
                str[l + 1] = temp;
            }
        }    
    }
    for(int u = 0 ; u <= p ; u ++){
        puts(str[u]);
    }
    return 0;
}
