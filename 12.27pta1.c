#include<stdio.h>
#include<stdlib.h>

int ** pascal( int n ) ;
int main()
{
    int        i , j , n ; 
    int        **array ;

    scanf( "%d" , & n ) ;

    array = pascal( n ) ; 

    if ( array != NULL )
    {
        for ( i = 0 ; i < n ; i++)//输出杨辉三角 
        {
            for ( j = 0 ; j < i ; j++ )
                printf("%d " ,array[i][j] ) ;
            printf("%d\n" ,array[i][j] ) ;
        }
        //内存释放        
        for( i = 0; i < n ; i++ )
            free(array[i]);
        free(array);
        array = NULL;
    }

    return 0;
}
int ** pascal( int n )
{
    int** pointer[n];
    for(int i = 0 ; i < n; i ++){
        pointer[i] = malloc(sizeof(int) * (i + 1));
    }
        return pointer[n];
}