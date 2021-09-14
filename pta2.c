#include<stdio.h>
void fun(char a[],int n);
int main(void)
{
    int n;
    scanf("%d",&n);
    char ch[6];
    int i = 1;
    while(i <= n){
        scanf("%s", ch);
        int last = 0;
        if(ch[4]>= '0' && ch[4] <= '9' ){
            last = 1;
        }
        int count = 0;
        if(last == 1){
            for(int i = 0 ;i < 4 ;i ++){
                if((ch[i] >= 'a'&& ch[i] <= 'z' && ch[i] != 'o'&&ch[i] != 'i') ||(ch[i] >= 'A' && ch[i] <= 'Z' && ch[i] != 'I' && ch[i] != 'O') ){
                    count ++;
                }
            }
        }
        int num = 0;
        for(int i = 0; i< 6 ;i ++){
            if(ch[i] >= '0' && ch[i] <= '9'){
                num ++;
            }
        }
        if(last == 1 && count == 2 && num == 3){
            fun(ch,6);
            printf("yes:%s\n", ch);
        }
        else
        {
            printf("no.\n");
        }
        i ++;
    }
    return 0;
}
void fun(char a[],int n)
{
    for(int i = 0 ; i < n ;i ++){
        if(a[i] == 'a')
        a[i] = 'A';
        if(a[i] == 'b')
        a[i] = 'B';
                if(a[i] == 'c')
        a[i] = 'C';
                if(a[i] == 'd')
        a[i] = 'D';
                if(a[i] == 'e')
        a[i] = 'E';
                if(a[i] == 'f')
        a[i] = 'F';
                if(a[i] == 'g')
        a[i] = 'G';
                if(a[i] == 'h')
        a[i] = 'H';
                if(a[i] == 'i')
        a[i] = 'I';
                if(a[i] == 'j')
        a[i] = 'J';
                if(a[i] == 'k')
        a[i] = 'K';
                if(a[i] == 'l')
        a[i] = 'L';
                if(a[i] == 'm')
        a[i] = 'M';
                if(a[i] == 'n')
        a[i] = 'N';
                if(a[i] == 'o')
        a[i] = 'O';
                if(a[i] == 'p')
        a[i] = 'P';
                if(a[i] == 'q')
        a[i] = 'Q';
                if(a[i] == 'r')
        a[i] = 'R';
                if(a[i] == 's')
        a[i] = 'S';
                if(a[i] == 't')
        a[i] = 'T';
                if(a[i] == 'u')
        a[i] = 'U';
                if(a[i] == 'v')
        a[i] = 'V';
                        if(a[i] == 'w')
        a[i] = 'W';
                if(a[i] == 'x')
        a[i] = 'X';
                if(a[i] == 'y')
        a[i] = 'Y';
                if(a[i] == 'z')
        a[i] = 'Z';
    }
}