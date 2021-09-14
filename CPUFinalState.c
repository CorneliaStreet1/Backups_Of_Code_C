#include<stdio.h>
#include<string.h>
#include<math.h>
#define Maxline 128
void Load(char codefield[][33]);//没问题
void FieldOutput(char codefield[][33],short datafield[]);
int NumberTransfer(char codefield[][33],int line);
void initialization(CodeField);
int main(void)
{
    int MDR[4] = {0};
    int AR[4] = {0};
    int SR[2] = {0};//0号是程序计数器，1号是标志寄存器
    char CodeField[Maxline][33] = {'0'};
    for(int i = 0 ; i < Maxline ; i++){
        for(int j = 0 ;j < 33 ; j ++){
            CodeField[i][j] = '0';
        }
    }
    short DataField[8192] = {0};
    char ir[16] = {'0'};
    char InstantNumber[16] = {'0'};
    Load(CodeField);
    FieldOutput(CodeField,DataField);
    return 0;
}
void FieldOutput(char codefield[][33],short datafield[])
{
    printf("\n");
    printf("codeSegment :\n");
    for(int i = 0 ;i < 128;i ++){
        long long nt = NumberTransfer(codefield,i);
        printf("%d",nt);
        if(((i + 1) % 8) != 0 ){
            printf(" ");
        }
        else
        printf("\n");
    }
    printf("\n");
    printf("dataSegment :\n");
    for(int j = 0 ;j < 256;j ++){
        printf("%d",datafield[j]);
        if(((j + 1 ) % 16 != 0)){
            printf(" ");
        }
        else{
            printf("\n");
        }
    }
}
int NumberTransfer(char codefield[][33],int line)
{
    int p = 0;
    for(int i = 0 ,j = 31;i < 32 ;i ++,j --){
        if(codefield[line][i] != '0' && codefield[line][i] != '\n'){
            p = p + pow(2,j);
        }
    }
    return p;
}
void Load(char codefield[][33])
{
    FILE* file = fopen("C:\\Users\\jiangyiqing\\Desktop\\dict.dic","r");
    for(int i = 0;i < 512; i ++){
        for(int j = 0 ; j < 33 ; j ++){
            char ch = fgetc(file);
            if((ch != EOF)){
                codefield[i][j] = ch;
            }
        }
    }
}