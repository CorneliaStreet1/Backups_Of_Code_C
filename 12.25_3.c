#include<stdio.h>
#include<stdlib.h>
int main(void)
{
    int n;
    scanf("%d",&n);
    int * p = (int *)malloc(sizeof(int) * n);
    for(int i = 0 ; i < n ; i ++ ){
        scanf("%d", &p[i]);
    } 
    for(int j = 0 ;j < n ; j ++){
        int a = p[j];
        p[j] = -10 * a;
    }
    for(int l = 0 ;l < n ; l ++){
        printf("%d",p[l]);
        if(l < n-1)
        printf(" ");
    }
    free(p);
    return 0;
}