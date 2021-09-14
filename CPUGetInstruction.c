#include<stdio.h>
#include<string.h>
#include<math.h>
#define Maxline 128
void Load(char codefield[][33]);
int getInstruction(char IR[],char codefield[][33],char instant[],int sr[]);
void initialization(char codefield[][33],short datafield[]);
int main(void)
{
    int MDR[4] = {0};
    int AR[4] = {0};
    int SR[2] = {0};//0号是程序计数器，1号是标志寄存器
    char CodeField[Maxline][33] = {'0'};
    short DataField[8192] = {0};
    char ir[16] = {'0'};
    char InstantNumber[16] = {'0'};
    int l;
    Load(CodeField);
    l = getInstruction(ir,CodeField,InstantNumber,SR);
    while (l)
    {
     for(int o = 0 ;o < 16 ; o ++){
        printf("%c",InstantNumber[o]);
        }
        printf("\n");
        l = getInstruction(ir,CodeField,InstantNumber,SR);
    }
    return 0;
}
int getInstruction(char IR[],char codefield[][33],char instant[],int sr[])
{
    int line = sr[0] / 4;
    for(int i = 0;i < 16; i ++){
        IR[i] = codefield[line][i];
    }
    for(int p = 16, q = 0;p < 32;q ++ ,p ++){
        instant[q] = codefield[line][p];
    }
    sr[0] = sr[0] + 4;
    for(int j = 0; j < 16 ;j ++){
        if(IR[j] != '0'){
            return 1;
        }
    }
    return 0;
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
void initialization(char codefield[][33],short datafield[])
{
        for(int i = 0 ; i < Maxline ; i++){
        for(int j = 0 ;j < 33 ; j ++){
            codefield[i][j] = '0';
        }
    }
    for(int p = 0 ; p < 8192 ; p ++){
        datafield[p] = 0;
    }
}