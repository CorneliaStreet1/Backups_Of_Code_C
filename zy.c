#include <stdio.h>

//判断一个数是否为完全数的函数
int        isPerfect(int);

//打印完全数的函数 
void    printPerfact(int);

int main()
{
    int i,a,b,count;

    scanf("%d%d",&a,&b);
    count = 0 ;//a,b两数间完全数的数量，初始化为0 
    for(i=a;i<=b;i++)
    {
        if (isPerfect(i))  //如果是完全数 
        {
            printPerfact(i) ;//打印该完全数 
            count ++ ;  //计数器加1 
        }        
    }
    printf("The total number is %d.\n",count);//输出a,b两数间完全数的数量 
    return 0 ;
}
int isPerfect(int n)
{
	int isp=0;
	int i,sum=0;
	for(i=1;i<=n/2;i++){
		if(n%i==0){
			sum+=i;
		}
	}
	if(sum==n){
		isp=1;
	}
	return (isp);
}
void printPerfact(int n)
{
	printf("%d=1",n);
	int i=2;
	for(;i<=n/2;i++){
		if (n%i==0) printf("+%d",i);
	}printf("\n");
}