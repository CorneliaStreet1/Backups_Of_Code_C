#include<stdio.h>
int main(void)
{
    int one,two,five,money,num,i=0;
    scanf("%d%d",&money,&num);
    for(one=0;one<=num;one++){
        for(two=0;two<=num;two++){
            for(five=0;five<=num;five++){
                if((one+two+five==num)&&(one*1+two*2+five*5)==money){
                    i++;
                }
            }
        }
    }
    printf("%d",i);
    return 0;
}