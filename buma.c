#include<stdio.h>
#include<math.h>
int InstantNumberTransfer(char instantnumber[]);
int main(void)
{
    char ins[16];
    for(int i = 0 ; i < 16 ; i ++){
        scanf("%c", &ins[i]);
    }
    int a = InstantNumberTransfer(ins);
    printf("%d",a);
    return 0;
}
int InstantNumberTransfer(char instantnumber[])
{
    int in = 0;
    if(instantnumber[0] == '0'){
        for(int i = 1,j = 14 ;i < 16 ; i ++,j -- ){
            if(instantnumber[i] != '0'){
            in = in + pow(2,j);
            }
        }
    }
    else if(instantnumber[0] == '1'){
        for(int i = 1 ; i < 16 ; i ++){
            if(instantnumber[i] == '0'){
                instantnumber[i] = '1';
            }
            else if(instantnumber[i] == '1'){
                instantnumber[i] = '0';
            }
        }
        for(int p = 1,j = 14 ;p < 16 ; p ++,j -- ){
            if(instantnumber[p] != '0'){
            in = in + pow(2,j);
            }
        }
        in = - 1 * in;
        in = in - 1;   
    }
    return in;
}