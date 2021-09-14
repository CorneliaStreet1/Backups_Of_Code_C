/*#include<stdio.h>
int main(void)
{
    int i = 0,sum = 0;
    int a;
    scanf("%d",&a);
    while(a != -1){
        sum = sum + a;
        scanf("%d",&a);
        i ++;
    }
    printf("%d %d",i,sum);
    return 0;
}*/
/*#include<stdio.h>
int main(void)
{
   int isprime = 1;
   int k = 2,i;
   scanf("%d",&i);
   if(i == 1)
   isprime = 0;
   while(k < i){
       if(i % k == 0){
           isprime = 0;
           break;
       }
       else
       {
           isprime = 1;
       }
       k ++;    
   }
   printf("%d",isprime);
   return 0;*/


   #include<stdio.h>
int main(void)
{
    char ch[100];
    scanf("%s", ch);
    int i = 0,num = 0;
    while(ch[i] != '\0'){
                if(ch[i] = ' ' &&(ch[i - 1] >= 'a'&&ch[i - 1] <= 'z'||ch[i - 1] <= 'A'&&ch[i - 1] <= 'Z'){
            num ++;
        }
        i ++;
    }
    num ++;
    printf("%d",num);
    return 0;
}