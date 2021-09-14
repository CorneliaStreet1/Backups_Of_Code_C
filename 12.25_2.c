#include<stdio.h>
int getString(char * source , char *strPtr[]);
int main()
{
    char str[100005];
    char *strPtr[1005]={0};
    int  i, num ;
    gets(str);
    num = getString(str , strPtr) ;
    for( i = 0 ; i < num ; i++ )
        puts(strPtr[i]);
    return 0;    
}
int getString(char * source , char *strPtr[])
{
    int p = 0;
    while(* source != '\0'){
        int word = 0;
        if(* source == ' ' && * (source - 1) == ' ')
        word = 1;
        else
        word = 0;
        if(word == 1){
            strPtr[p] = source;
            * (source - 1) = '\0';
            for(char * source1 = source;* source1 != '\0'; source1 ++){
                if(* source1 == ' '){
                    * source1 = '\0';
                    break;
                }
            }
            p ++;
        }
        source ++;
    }
    return p;
}