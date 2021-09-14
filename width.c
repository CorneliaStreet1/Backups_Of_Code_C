#include<stdio.h>
int main(void)
{
    int n;
    scanf("%d",&n);
    int ch[17];
    char num[13] = {'1','0','X','9','8','7','6','5','4','3','2'};
    int i = 1;
    int sum = 0;
    while(i <= n){
        for(int j = 0 ;j < 17; j ++){
            scanf("%d",&ch[i]);
        }
        char cha;
        scanf("%c",&cha);
        sum = ch[0] * 7 + ch[1] * 9 + ch[2] * 10 + ch[3] * 5 + ch[4] * 8 + ch[5] * 4 + ch[6] * 2 + ch[7] * 1 + ch[8] * 6 + ch[9] * 3 + ch[10] * 7 + ch[11] * 9 + ch[12] * 10 + ch[13] * 5 + ch[14] * 8 + ch[15] * 4 + ch[16] * 2;
        int t = sum % 11;
        if(num[t] == cha)
        printf("right\n");
        else
        {
            printf("wrong\n");
        }
        sum = 0;
        i ++;
    }
    return 0;
}
