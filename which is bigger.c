#include<stdio.h>

#define MAXN 2000000
#define MAXM 100000 
int RecurBinarySearch( int a[] , int key , int left , int right ) ;

int a[MAXN],loc[MAXM];//由于n比较大，所以使用全局变量存储这n个整数；

int main()
{
    int n,m,i;
    scanf("%d %d",&n , &m );

    for( i = 0 ; i < n ; i++ )
        scanf("%d", &a[i]);
    for( i =0 ; i < m ; i++ )
    {
        scanf("%d",&loc[i]);
        loc[i] = RecurBinarySearch( a , loc[i] , 0 , n - 1 );
    }

    for( i = 0 ; i < m - 1 ; i++ )
        printf( "%d " , loc[i] );
    printf( "%d\n", loc[ m - 1 ] );
    return 0;
}
int BinarySearch(int a[],int n,int key)
{
    int ret = -1;
    int left = 0;
    int right = n-1;
    int mid = (n - 1) / 2;
    while(left <= right){
    mid = (right + left) / 2;
    if(a[mid] == key){
        ret = mid;
        goto end;
    }
    else if(key < a[mid]){
        right = mid - 1;
    }
    else if(key > a[mid]){
        left = mid + 1;
    }
    }   
    end:
    return ret;
}
int RecurBinarySearch( int a[] , int key , int left , int right )
{
    int mid = (left + right) / 2;
    if(a[mid] == key)
    return mid;
    else if(key <= a[mid])
    return RecurBinarySearch(a[] ,a[mid],0,n - 1 ) - 1;
    else if(key > a[mid]){
        return RecurBinarySearch(a[] ,a[mid],0,n - 1 ) - 1;
    }
}