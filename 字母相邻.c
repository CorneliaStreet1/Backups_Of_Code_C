#include<stdio.h>
int main(void)
{
    char ch_1,ch_2,ch_3;
    scanf("%c%c%c",&ch_1,&ch_2,&ch_3);
    if(ch_1 - ch_2 ==-1&&ch_2 - ch_3 ==-1&&<=ch_1<=90&&65<=ch_2<=90&&65<=ch_3<=90)
    printf("Yes\n");

    if(ch_1 - ch_2 ==-1&&ch_2 - ch_3 ==-1&&97<=ch_1<=122&&97<=ch_2<=122&&97<=ch_3<=122)
    printf("Yes\n");
    else
    {
        printf("No\n");
    }
    return 0;
}