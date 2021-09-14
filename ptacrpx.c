#include<stdio.h>
//插入排序（升序） 
//参数说明：数组，数组中已有元素个数 
void InsertSort(int a[],int n);

int main()
{
    int        n , i,    num[1000] ;

    scanf( "%d" , &n ); 
    for( i = 0 ; i < n ; i++ ) 
        scanf( "%d", &num[i] ) ;
    InsertSort( num , n ) ; 
    return 0 ;
}
void InsertSort(int a[],int n)
{
    for(int i = 1 ; i < n ; i ++){
        int j = i - 1;
        int m = j;
        int k = i;
        while( a [i] < a[j]&& j >= 0 ){
            int t = a[i];
            a[i] = a[j];
            a[j] = t;
            i --;
            j --;
        }
        i = k;
        j = m;
        for(int p = 0 ; p < n ; p ++ ){
            printf("%d",a[p]);
            if(p != n -1)
            printf(" ");
            else
            {
                printf("\n");
            }
            

        }
    }
}