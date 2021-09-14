#include<stdio.h>
#include<string.h>
#include<math.h>
#define Maxline 128
int IRnumberTransfer(char IR[]);
void StateOutput(int mdr[],int ar[],int sr[],char IR[]);
void StateOutput(int mdr[],int ar[],int sr[],char IR[])
{
    printf("ip = %d\n",sr[0]);
    printf("flag = %d\n",sr[1]);
    int r = IRnumberTransfer(IR);
    printf("ir = %d\n",r);
    for(int i = 0 ;i < 4; i ++){
        printf("ax%d = %d",i + 1,mdr[i]);
        if(i != 3){
            printf(" ");
        }
    }
    printf("\n");
    for(int j = 0; j < 4 ;j ++){
        printf("ax%d = %d",j +5,ar[j]);
        if(j != 3){
            printf(" ");
        }
    }
    printf("\n");
}
int IRnumberTransfer(char IR[])
{
    int irn = 0;
    for(int i = 0 ,j = 15 ; i < 16 ; i ++ ,j --){
        if(IR[i] != '0'){
            irn = irn + pow(2,j);
        }
    }
    return irn;
}