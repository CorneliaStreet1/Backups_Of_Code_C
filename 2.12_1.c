#include<string.h>
#include<stdio.h>
void delcharfun(char *str,char ch);
int main()
{
    char ch,str[110];

    scanf("%s",str);    //读入字符串 
    getchar();            //读取回车符号 
    scanf("%c",&ch);    //读入字符 
    delcharfun(str,ch);    //删除 
    printf("%s\n",str);    //输出删除后结果 
    return 0;    
}
void delcharfun(char *str,char ch)
{
    int k,i = 0, is = 1;
    while(str[i] != '\0' && is == 1){
        if(str[i] == ch){
            k = i;
            while(str[k] != '\0'){
            str[k] = str[k + 1];
            k ++;
            }
        }
        int p = 0;
        while(str[p] != '\0'){
            if(str[p] == ch){
                is = 1;
                break;
            }
            else
            is = 0;
        }
        i ++;
    }
}