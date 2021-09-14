//插入排序
#include<stdio.h>

//插入排序（升序） 
//参数说明：数组，数组中已有元素个数 
;void InsertSort(int a[],int n);
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
    int left = 0;
    int right = 1;
    while(right < n){
        if( a[right] < a[right - 1]){
            int t = a[right];
            a[right] = a[left];
            a[left] = t;
            for(int j = 0 ;j < n ;j ++){
                printf("%d",a[j]);
            }
        }
        else
        { for(int j = 0 ;j < n ;j ++){
                printf("%d",a[j]);
            }
        }
        
    }
}