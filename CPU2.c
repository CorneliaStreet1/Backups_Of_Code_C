#include<stdio.h>
#include<Windows.h>
#include<process.h>
#include<string.h>
#include<math.h>
#define Maxline 128
HANDLE hMutex,hMutex2;
HANDLE h;
int lock = 0;//全局变量，用来做锁锁住16384,为0默认无锁
char CodeField[Maxline][33] = {'0'};//代码段改为全局
short DataField[8192] = {0};//数据段改为全局
typedef struct cpu{
    int MDR[4];//寄存器编号比对应数组下标大一
    int AR[4];//寄存器编号比对应数组下标大5
    int SR[2];//0号是程序计数器，1号是标志寄存器
    char ir[16];//指令寄存器
    int id;
    char InstantNumber[16];
} CPU;
void Stop();
void Lock(int lock);
void Unlock(int lock);
void Sleepy(int instantNumber);
unsigned __stdcall AnalyseAndPerform(void* arguments);
void Load(char codefield[][33]);//测试OK
void initialization(char codefield[][33],short datafield[]);//初始化数组为全0，不用改
int getInstruction(char IR[],char codefield[][33],char instant[],int sr[]);//放到了分析执行指令函数内部去了
void analyseAndPerform(char IR[],char instant[],short datafield[],int mdr[],int ar[],int sr[],char codefield[][33],int ID);//修改了函数原型以适应放入内部的取指令函数
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
void Output(int MDRnumber,int mdr[],int ID);//已加ID
int RegisterNumberTransfer(char IR[],int start,int end);
int InstantNumberTransfer(char instantnumber[]);//补码不对，已修正
int IRnumberTransfer(char IR[]);//没问题
void StateOutput(int mdr[],int ar[],int sr[],char IR[],int ID);//格式上没问题了,已加ID
void FieldOutput(char codefield[][33],short datafield[]);//应该没问题了，加了个初始化数组为全0的函数
int NumberTransfer(char codefield[][33],int line);//没问题
int main(void)
{
    initialization(CodeField,DataField);
    DataField[0] = 100;
    Load(CodeField);
    CPU cpu1 = {{0,0,0,0},{0,0,0,0},{0,0},{'0'},1,{'0'}};
    CPU cpu2 = {{0,0,0,0},{0,0,0,0},{256,0},{'0'},2,{'0'}};
    HANDLE th1,th2;
    int i = 0;
    HANDLE h = CreateMutex(NULL,FALSE,NULL);
    while(i < 100){
        th1 = (HANDLE)_beginthreadex(NULL,0,AnalyseAndPerform,&cpu1,0,NULL);
        th2 = (HANDLE)_beginthreadex(NULL,0,AnalyseAndPerform,&cpu2,0,NULL);
        WaitForSingleObject(th1,INFINITE);
        WaitForSingleObject(th2,INFINITE);
        i ++;
    }
    CloseHandle(th1);
    CloseHandle(th2);
    FieldOutput(CodeField,DataField);
    return 0;
}
void Load(char codefield[][33])
{
    FILE* file1 = fopen("C:\\Users\\jiangyiqing\\Desktop\\dict1.dic","r");//记得自行改成你的目录，交到OJ记得改成"dict.dic"
    FILE* file2 = fopen("C:\\Users\\jiangyiqing\\Desktop\\dict2.dic","r");//记得自行改成你的目录，交到OJ记得改成"dict.dic"
    for(int i = 0;i < 64; i ++){
        for(int j = 0 ; j < 33 ; j ++){
            char ch = fgetc(file1);
            if((ch != EOF)){
                codefield[i][j] = ch;
            }
        }
    }
    for(int i = 64;i < 128; i ++){
        for(int j = 0 ; j < 33 ; j ++){
            char ch = fgetc(file2);
            if((ch != EOF)){
                codefield[i][j] = ch;
            }
        }
    }
    fclose(file1);
    fclose(file2);
}
unsigned __stdcall AnalyseAndPerform(void* arguments)
{
    CPU* c = (CPU*) arguments;
    analyseAndPerform(c->ir,c->InstantNumber,DataField,c->MDR,c->AR,c->SR,CodeField,c->id);
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
    for(int j = 0; j < 16 ;j ++){
        if(IR[j] != '0'){
            return 1;
        }
    }
    return 0;
}
void analyseAndPerform(char IR[],char instant[],short datafield[],int mdr[],int ar[],int sr[],char codefield[][33],int ID)
{
    
    int p = getInstruction(IR,codefield,instant,sr);
    if(p == 0){
        ;
    }
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
    int ins = InstantNumberTransfer(instant);//立即数
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
        Output(MDRnumber,mdr,ID);
    }
    else if(strcmp(operation,"00001101") == 0){
        Lock(lock);
    }
    else if(strcmp(operation,"00001110") == 0){
        Unlock(lock);
    }
    else if(strcmp(operation,"00001111") == 0){
        Sleepy(ins);
    }
    StateOutput(mdr,ar,sr,IR,ID);//将CPU状态输出放到了分析执行指令函数内
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
void Output(int MDRnumber,int mdr[],int ID)
{
    printf("id = %d",ID);
    printf("out: ");
    printf("%d",mdr[MDRnumber - 1]);
    printf("\n");
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
void StateOutput(int mdr[],int ar[],int sr[],char IR[],int ID)
{
    WaitForSingleObject(h,INFINITE);
    printf("id = %d\n", ID);
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
    ReleaseMutex(h);
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
void Lock(int instant)
{
    hMutex = CreateMutex(NULL,FALSE,"DataField[(instant - 16384) /2]");
    WaitForSingleObject(hMutex,INFINITE);
}
void Unlock(int instant)
{
    hMutex = CreateMutex(NULL,FALSE,"DataField[(instant - 16384) /2]");
    ReleaseMutex(hMutex);
}
void Sleepy(int instantNumber)
{
    Sleep(instantNumber);
}