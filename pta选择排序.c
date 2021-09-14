#include<stdio.h>
//选择排序（升序） 
//参数说明：数组，数组中已有元素个数 
void selectSort(int data[],int n) ;
//函数功能：找数组中的最小值元素，并返回其下标 
//参数说明：数组名，查找起始位置下标，查找终止位置下标
int findMin(int data[], int start, int end) ; 
//输出数组中所有元素 
//参数说明：数组，数组中已有元素个数 
void outputData(int data[],int n) ;
int main()
{
    int n,i,num[1010] ;
    scanf("%d",&n); 
    for( i = 0 ; i < n ; i++ ) 
        scanf("%d",&num[i]);
    selectSort(num,n); 
    return 0;
}
void selectSort(int num[],int n)
{
    for(int i = 0 ;i < n - 1 ;i ++){
        int t = num[i];
        int min = findMin(num, i, n - 1);
        num[i] = num[min];
        num[min] = t;
        outputData(num,n);
    }
}
void outputData(int num[],int n){
    for(int j = 0 ;j < n ;j ++){
            printf("%d",num[j]);
            if(j != n - 1)
            printf(" ");
            else
            {
                printf("\n");
            }
    }
}
int findMin(int num[], int start, int end)
{
    int min = num[start];
    int index = start;
    for(int i = start ;i <= end ; i ++){
        if(min > num[i]){
            min = num[i];
            index = i;
        }
    }
    return index;
}