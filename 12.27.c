#include<stdio.h>
int main(void)
{
    int n;
    scanf("%d", &n);
    char name[n][22];
    for(int p = 0 ; p < n ; p ++){
            scanf("%s", name[p]);
    }
    int m,i;
    scanf("%d", &m);
    for(int l = 0 ; l < m ;l ++){
        scanf("%d",  &i);
        printf("%s\n", name[i - 1]);
    }    
    return 0;
}