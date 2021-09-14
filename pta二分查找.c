#include<stdio.h>
//函数功能：二分查找
//函数参数：分别为被查找的数组，数组长度，所查找的元素
//函数返回值：如果找到，则返回该元素在数组中的下标，否则返回-1 
int BinarySearch(int a[],int n,int key) ; 
int num[2000010] ;//数据量比较大，将该数组放在全局区 

int main()
{
    int n , m, i;    
    int key;
    scanf("%d%d",&n,&m); 
    for( i = 0 ; i < n ; i++ ) 
        scanf("%d",&num[i]) ;

    for( i = 0 ; i < m ; i++ ) 
    {
        scanf("%d",&key) ;
        printf("%d",BinarySearch(num,n,key)) ;
        if ( i != m - 1 ) printf(" ") ;
        else printf("\n") ;
    }
    return 0 ;
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