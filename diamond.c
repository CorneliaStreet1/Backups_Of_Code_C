#include<stdio.h>
int main(void)
{
 int n,line=0;
 scanf("%d",&n);
 int x=n;
 while(line<=x){
     line++;
     int i;
     i=x-1;
     while(i>0){
         printf(" ");
         i--;
     }
     x--;
     int j=0;
     while(j<2*line){
         printf("*");
         j++;
     }
 }
 int line_ ,y=n;
 while(line_ <=y){
     line_ ++;
     int j=y-1;

 }
}