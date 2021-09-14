#include<stdio.h>
int main(void)
{
    char chaR;
    scanf("%c",&chaR);/*永远不要写成scanf（“变量名”，&变量名）*/
    printf("the code of %c is %d",chaR,chaR);
    return 0;
    


}