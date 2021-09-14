#include<stdio.h>
#include<string.h>
#include<math.h>
#define Maxline 128
void Load(char codefield[][33]);
int main(void)
{
    int MDR[4] = {0};
    int AR[4] = {0};
    int SR[2] = {0};//0号是程序计数器，1号是标志寄存器
    char CodeField[Maxline][33] = {'0'};
    short DataField[8192] = {0};
    char ir[16] = {'0'};
    char InstantNumber[16] = {'0'};
    int line = SR[0] / 4;
    Load(CodeField);
    for(int i = 0 ; i < 128 ; i ++){
        for(int j = 0 ; j < 33 ; j ++){
            printf("%c",CodeField[i][j]);
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