#include<stdio.h>
#include<string.h>
#include<math.h>
#define Maxline 128
void initialization(char codefield[][33],short datafield[]);//初始化二维数组为全0
int getInstruction(char IR[],char codefield[][33],char instant[],int sr[]);//修改了一下，line去掉，变成函数内部局部变量，没问题
void analyseAndPerform(char IR[],char instant[],short datafield[],int mdr[],int ar[],int sr[]);
void DataTransfer(int instantNumber,short datafield[],int mdr[],int ar[],char IR[]);
void Add(int MDRnumber,int ARnumber,int instantNumber,short datafield[],int mdr[],int ar[]);
void Minus(int MDRnumber,int ARnumber,int instantNumber,short datafield[],int mdr[],int ar[]);
void Multiplication(int MDRnumber,int ARnumber,int instantNumber,short datafield[],int mdr[],int ar[]);
void Division(int MDRnumber,int ARnumber,int instantNumber,short datafield[],int mdr[],int ar[]);
void Conjunction(int MDRnumber, int ARnumber,int instantNumber,short datafield[],int mdr[],int ar[]);
void Disjunction(int MDRnumber, int ARnumber,int instantNumber,short datafield[],int mdr[],int ar[]);
void Negation(int MDRnumber, int ARnumber,short datafield[],int mdr[],int ar[]);
void Comparator(int MDRnumber, int ARnumber,int sr[],int instantNumber,short datafield[],int mdr[],int ar[]);
void Skip(int MDRnumber,int ARnumber,int InstantNumber,int sr[]);
void Input(int MDRnumber,int mdr[]);
void Output(int MDRnumber,int mdr[]);
int RegisterNumberTransfer(char IR[],int start,int end);
int InstantNumberTransfer(char instantnumber[]);//补码不对，已修正
int IRnumberTransfer(char IR[]);
int getInstruction(char IR[],char codefield[][33],char instant[],int sr[])
{
    int line = sr[0] / 4;
    for(int i = 0;i < 16; i ++){
        IR[i] = codefield[line][i];
    }
    for(int p = 16, q = 0;p < 32;q ++ ,p ++){
        instant[q] = codefield[line][p];
    }
    for(int j = 0; j < 16 ;j ++){
        if(IR[j] != '0'){
            return 1;
        }
    }
    return 0;
}
void analyseAndPerform(char IR[],char instant[],short datafield[],int mdr[],int ar[],int sr[])
{
    int MDRnumber;
    int ARnumber;
    char copy[17];
    for(int i = 0; i < 16; i++){
        copy[i] = IR[i];
    }
    copy[16] = '\0';
    char operation[9];
    for(int j = 0 ; j < 8 ; j ++){
        operation[j] = IR[j];
    }
    operation[8] = '\0';
    int number1 = RegisterNumberTransfer(copy,8,11);
    int number2 = RegisterNumberTransfer(copy,12,15);
    if((number1 < 5) && (number2 > 4) &&(number1 > 0)){
        MDRnumber = number1;
        ARnumber = number2;
    }
    else if((number1 < 5) && (number2 == 0) &&(number1 > 0)){
        MDRnumber = number1;
        ARnumber = 0;
    }
    else if((number1 > 4) && (number2 == 0)){
        ARnumber = number1;
        MDRnumber = 0;
    }
    else if((number1 > 4) && (number2 <5) && (number2 > 0)){
        ARnumber = number1;
        MDRnumber = number2;
    }
    else if((number1 == 0) && (number2 > 4)){
        ARnumber = number2;
        MDRnumber = number1;
    }
    else if((number1 == 0) && number2 < 4){
        MDRnumber = number2;
        ARnumber = number1;
    }
    int ins = InstantNumberTransfer(instant);
    if(strcmp(operation,"00000001") == 0){
        DataTransfer(ins,datafield,mdr,ar,IR);
    }
    else if(strcmp(operation,"00000010") == 0){
        Add(MDRnumber,ARnumber,ins,datafield,mdr,ar);
    }
    else if(strcmp(operation,"00000011") == 0){
        Minus(MDRnumber,ARnumber,ins,datafield,mdr,ar);
    }
    else if(strcmp(operation,"00000100") == 0){
        Multiplication(MDRnumber,ARnumber,ins,datafield,mdr,ar);
    }
    else if(strcmp(operation,"00000101") == 0){
        Division(MDRnumber,ARnumber,ins,datafield,mdr,ar);
    }
    else if(strcmp(operation,"00000110") == 0){
        Conjunction(MDRnumber,ARnumber,ins,datafield,mdr,ar);
    }
    else if(strcmp(operation,"00000111") == 0){
        Disjunction(MDRnumber,ARnumber,ins,datafield,mdr,ar);
    }
    else if(strcmp(operation,"00001000") == 0){
        Negation(MDRnumber,ARnumber,datafield,mdr,ar);
    }
    else if(strcmp(operation,"00001001") == 0){
        Comparator(MDRnumber,ARnumber,sr,ins,datafield,mdr,ar);
    }
    else if(strcmp(operation,"00001010") == 0){
        Skip(MDRnumber,ARnumber,ins,sr);
    }
    else if(strcmp(operation,"00001011") == 0){
        Input(MDRnumber,mdr);
    }
    else if(strcmp(operation,"00001100") == 0){
        Output(MDRnumber,mdr);
    }
    StateOutput(mdr,ar,sr,IR);
}
int RegisterNumberTransfer(char IR[],int start,int end)
{
    int n = 0;
    for(int i = start , j = 3;i < end +1 ;i ++,j --){
        if(IR[i] == '1'){
            n = n + pow(2,j);
        }
    }
    return n;
}
void Add(int MDRnumber,int ARnumber,int instantNumber,short datafield[],int mdr[],int ar[]){
    if((MDRnumber > 0) && (ARnumber >= 5) ){
        int index = (ar[ARnumber - 5] - 16384) / 2;
        mdr[MDRnumber -1] = mdr[MDRnumber - 1] + datafield[index];
    }
    else if((ARnumber == 0)){
        mdr[MDRnumber -1] = mdr[MDRnumber - 1] + instantNumber;
    }
}
void Minus(int MDRnumber,int ARnumber,int instantNumber,short datafield[],int mdr[],int ar[])
{
    if((MDRnumber > 0) && (ARnumber >= 5) ){
        int index = (ar[ARnumber - 5] - 16384) / 2;
        mdr[MDRnumber -1] = mdr[MDRnumber - 1] - datafield[index];
    }
    else if((ARnumber == 0)){
        mdr[MDRnumber -1] = mdr[MDRnumber - 1] - instantNumber;
    }
}
void Multiplication(int MDRnumber, int ARnumber,int instantNumber,short datafield[],int mdr[],int ar[])
{
    if((MDRnumber > 0) && (ARnumber >= 5) ){
        int index = (ar[ARnumber - 5] - 16384) / 2;
        mdr[MDRnumber -1] = mdr[MDRnumber - 1] * datafield[index];
    }
    else if((ARnumber == 0)){
        mdr[MDRnumber -1] = mdr[MDRnumber - 1] * instantNumber;
    }
}
void Division(int MDRnumber, int ARnumber,int instantNumber,short datafield[],int mdr[],int ar[])
{
    if((MDRnumber > 0) && (ARnumber >= 5) ){
        int index = (ar[ARnumber - 5] - 16384) / 2;
        mdr[MDRnumber -1] = mdr[MDRnumber - 1] / datafield[index];
    }
    else if((ARnumber == 0)){
        mdr[MDRnumber -1] = mdr[MDRnumber - 1] / instantNumber;
    }
}
void Conjunction(int MDRnumber, int ARnumber,int instantNumber,short datafield[],int mdr[],int ar[])
{
    if((MDRnumber > 0) && (ARnumber >= 5) ){
        int index = (ar[ARnumber - 5] - 16384) / 2;
        mdr[MDRnumber -1] = (mdr[MDRnumber - 1] && datafield[index]);
    }
    else if((ARnumber == 0)){
        mdr[MDRnumber -1] = (mdr[MDRnumber - 1] && instantNumber);
    }
}
void Disjunction(int MDRnumber, int ARnumber,int instantNumber,short datafield[],int mdr[],int ar[])
{
    if((MDRnumber > 0) && (ARnumber >= 5) ){
        int index = (ar[ARnumber - 5] - 16384) / 2;
        mdr[MDRnumber -1] = (mdr[MDRnumber - 1] || datafield[index]);
    }
    else if((ARnumber == 0)){
        mdr[MDRnumber -1] = (mdr[MDRnumber - 1] || instantNumber);
    }
}
void Negation(int MDRnumber, int ARnumber,short datafield[],int mdr[],int ar[])
{
    if(MDRnumber == 0){
        int index = (ar[ARnumber - 5] - 16384) / 2;
        datafield[index] = (! datafield[index]);
    }
    else if(ARnumber == 0){
        mdr[MDRnumber - 1] = (! mdr[MDRnumber - 1]);
    }
}
void Comparator(int MDRnumber, int ARnumber,int sr[],int instantNumber,short datafield[],int mdr[],int ar[])
{
    int m = mdr[MDRnumber - 1];
    int index = (ar[ARnumber - 5] - 16384) / 2;
    int a = datafield[index];
    if(ARnumber == 0){
        if(m > instantNumber){
            sr[1] = 1;
        }
        else if(m == instantNumber){
            sr[1] = 0;
        }
        else{
            sr[1] = -1;
        }
    }
    else if(ARnumber != 0){
        if(m > a){
            sr[1] = 1;
        }
        else if(m == a){
            sr[1] = 0;
        }
        else{
            sr[1] = -1;
        }
    }

}
void Skip(int MDRnumber,int ARnumber,int InstantNumber,int sr[])
{
    if((MDRnumber == 0) &&(ARnumber == 0)){
       int a = sr[0];
        sr[0] = sr[0] + InstantNumber - 4;
    }
    else if(MDRnumber == 1){
        if(sr[1] == 0){
            sr[0] = sr[0] + InstantNumber - 4;
        }
    }
    else if(MDRnumber == 2){
        if(sr[1] == 1){
            sr[0] = sr[0] + InstantNumber - 4;
        }
    }
    else if(MDRnumber == 3){
        if(sr[1] == -1){
            sr[0] = sr[0] + InstantNumber - 4;
        }
    }
}
void Input(int MDRnumber,int mdr[])
{
    int in;
    printf("in:\n");
    scanf("%d",&in);
    mdr[MDRnumber - 1] = in;
}
void Output(int MDRnumber,int mdr[])
{
    printf("out: ");
    printf("%d",mdr[MDRnumber - 1]);
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
void DataTransfer(int instantNumber,short datafield[],int mdr[],int ar[],char IR[])
{
    int left = RegisterNumberTransfer(IR,8,11);
    int right = RegisterNumberTransfer(IR,12,15);
    if(right != 0){
        if(right < 5){
            int index = (ar[left - 5] - 16384) / 2;
            datafield[index] = mdr[right - 1];
        }
        else if(right > 4){
            int Index = (ar[right - 5] - 16384) / 2;
            mdr[left - 1] = datafield[Index];
        }
    }
    else if(right == 0){
        if(left < 5 ){
            mdr[left - 1] = instantNumber;
        }
        else if(left > 4){
            ar[left - 5] = instantNumber;
        }
    }
}
