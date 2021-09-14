#include<stdio.h>
int main(void)
{
    int n,m,num1[n],num2[m];
    scanf("%d",&n);
    for(int i = 0 ; i < n ; i ++){
        scanf("%d",&num1[i]);
    }
    scanf("%d",&m);
    for(int j = 0 ; j < m ; j ++){
        scanf("%d",&num2[j]);
    }
    int max = n;
    if(m > n)
    max = m;
    int a[max], p = 0;
    for(int k = 0 ; k < n ; k ++ ){
        for(int l = 0 ; l < m ; l ++){
            if(num1[k] == num2[l]){
                a[p] = num1[k];
                p ++;
            }
        }
    }
   for(int u = 0 ; u < p - 1 ; u ++ ){
        if(a[u] == a[u + 1]){
            a[u] = 20001121;
        }
    } 
    for(int y = 0 ; y < p ; y++){
            if(a[y] != 20001121){
                printf("%d",a[y]);
                if(y != p - 1)
                printf(" ");
                else
                printf("\n");
            }    
    }
    return 0;
}