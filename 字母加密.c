#include<stdio.h>
int main(void)
{
    char ch[101];
    char Ch[30];
    char cH[30];
    scanf("%s", ch);
    scanf("%s", Ch);
    scanf("%s", cH);
    int i = 0;
     while(ch[i] != '\0'){
         if(ch[i] != 'z' && ch[i] != 'Z'){
             ch[i] = ch[i] + 1;
         }
         else
         {
             ch[i] = ch[i] - 25;
         }
         i ++;
     }
     int j = 0;
     while(ch[j] != 0){
         if(ch[j] >= 'a' && ch[j] <= 'z'){
             printf("%c",cH[ch[j] - 'a']);// 相减后恰好对应编码表中的第某个字母，a 为 97，b为98，相减后恰好为1，即cH[1],恰好是小写字母编码表里的第二个字母
         }
        if(ch[j] >= 'A' && ch[j] <= 'Z'){
             printf("%c",cH[ch[j] - 'a']);
         }
         j ++;
     }
     return 0;
}