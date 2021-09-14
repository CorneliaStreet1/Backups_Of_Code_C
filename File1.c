#include<stdio.h>
void LowerCases(char c,int a[]);
void UperCases(char c, int b[]);
int main(void)
{
    FILE* file = fopen("C:\\Users\\jiangyiqing\\Desktop\\dict.dic","r");
    int Up = 0, Low = 0, numbers = 0, others = 0;
    int lines = 0, max = 0, min = 20001121, length = 0;
    int ch;
    int Upcase[26] = {};
    int Lowercase[26] = {};
    while ((ch = fgetc(file)) != EOF)
    {
        if(('a' <= ch) && (ch <= 'z')){
            Low ++;
            length ++;
            LowerCases(ch,Lowercase);
        }
        else if(('A' <= ch) && (ch <= 'Z')){
            Up ++;
            length ++;
            UperCases(ch,Upcase);
        }
        else if(('0' <= ch) && (ch <= '9')){
            numbers ++;
            length ++;
        }
        else if(ch == '\n'){
            lines ++;
            if(length > max)
            max = length;
            if(length < min)
            min = length;
            length = 0;
        }
        else
        others ++;
    }
    lines ++;
    fclose(file);
    int task;
    scanf("%d", &task);
    if(task == 1){
        printf("Task1:\n");
        printf("capital:%d\n",Up);
        printf("lowercase:%d\n",Low);
        printf("digit:%d\n",numbers);
        printf("others:%d\n",others);
    }
    else if(task == 2){
        printf("Task2:\n");
        printf("line:%d\n",lines);
        printf("%d characters in max line.\n",max);
        printf("%d characters in min line.",min);
    }
    else if(task == 3){
        printf("Task3:\n");
        printf("CAPITAL:\n");
        char capital = 'A';
        int n = 0;
        while (capital <= 'Z')
        {
            printf("%c:%d\n",capital,Upcase[n]);
            n ++;
            capital ++;
        }
        char lower = 'a';
        int m = 0;
        printf("LOWERCASE:\n");
        while (lower <= 'z')
        {
            printf("%c:%d\n",lower,Lowercase[m]);
            m ++;
            lower ++;
        }
    }
    return 0;
}
void LowerCases(char c,int a[])
{
    char l = 'a';
    int m = 0;
    while (l != c)
    {
        l ++;
        m ++;
    }
    a[m] ++;
}
void UperCases(char c, int b[])
{
    char u = 'A';
    int n = 0;
    while (u != c)
    {
        u ++;
        n ++;
    }
    b[n] ++;
}