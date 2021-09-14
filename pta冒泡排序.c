#include<stdio.h>
void bubbleSort(int a[],int n);
void outputData(int data[],int elementCount);
int main()
{
    int n ,i,num[10010];
    scanf("%d",&n); 
    for( i = 0 ; i < n ; i++ ) 
        scanf("%d",&num[i]) ;
    bubbleSort(num,n); 
    outputData(num,n);
    return 0 ;
}
void bubbleSort(int a[],int n)
{
	for(int i = 0;i < n - 1; i ++){
		for(int j = 0;j < n - i -1;j ++){
			if(a[j] < a[j + 1]){
				int t = a[j];
				a[j] = a[j + 1];
				a[j + 1] = t; 
			}
		}
	}
}
void outputData(int a[],int n)
{
	for(int i = 0;i < n;i++){
		printf("%d",a[i]);
		if(i != n-1)
		printf(" ");
		else
		{
			printf("\n");
		}
		
	}
}
