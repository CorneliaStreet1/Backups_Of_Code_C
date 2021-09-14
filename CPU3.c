#include<stdio.h>
#include<string.h>
#include<math.h>
#include<Windows.h>
#include<process.h>
/**************写在最前面：**************/
//MDR(mdr)：Memory Data Register，数据寄存器
//AR[4](ar)：Address Register,地址寄存器
//IR[4](ir)指令寄存器
//SR[2](sr)：系统寄存器，0号是程序计数器(ip)，1号是标志寄存器(flag)
//instant，instantNumber，ins，都是立即数，有这么多形式是为了增强可读性，也避免同一个标识符定义冲突
//MDRnumber(mdrNumber)：数据寄存器编号
//ARnumber(arNumber):地址寄存器编号
#define Maxline 128//最大指令条数，由于测试用例指令有限，没有将最大指令条数取到512，这样也可以简化代码段的输出函数
HANDLE hMutex,hMutex2;//两个句柄，一个用来控制输出，一个用来锁内存
char CodeField[Maxline][33] = {'0'};//代码段
short DataField[8192] = {0};//数据段
//虽然我知道field是域的意思，但是CodeSegment太长了，DataSegment也太长了...
typedef struct threadArgument
{
    int address;
    int id;
} Arguments;//PPT中建议的结构体，存的是各个线程的ID和各个线程各自代码段的起始位置(0和256，存入程序计数器中)
unsigned __stdcall run(void * Pargs);//用来跑某个线程的，相当于单核版的main函数，完成取指令分析指令执行指令状态输出的功能
void Sleepy(int instantNumber);//睡眠函数
void Lock(int instant);//锁内存
void Unlock(int instant);//解锁内存
//(此注释对应下一行的函数)没问题，用于将指令读取至代码段，在双核版中已修改，使得可以一次性将两个核的指令读取并分别放在地址0和256开始的地方，省去了filename[]数组
void Load(char codefield[][33]);
//(此注释对应下一行的函数)初始化二维数组为全0，发现如果用codefield[128][33] = {'0'}初始化而不专门初始化一下可能存在局部单元初始值不为零的情况
void initialization(char codefield[][33],short datafield[]);
//(此注释对应下一行的函数)取指令函数，将指令前十六位存在指令寄存器，立即数部分则存在instant[16]数组中
int getInstruction(char IR[],char codefield[][33],char instant[],int sr[]);
//(此注释对应下一行的函数)分析指令，执行指令函数
void analyseAndPerform(char IR[],char instant[],short datafield[],int mdr[],int ar[],int sr[],int ID);

void DataTransfer(int instantNumber,short datafield[],int mdr[],int ar[],char IR[]);//数据传输
void Add(int MDRnumber,int ARnumber,int instantNumber,short datafield[],int mdr[],int ar[]);//加法
void Minus(int MDRnumber,int ARnumber,int instantNumber,short datafield[],int mdr[],int ar[]);//减法，minus是负号的意思
void Multiplication(int MDRnumber,int ARnumber,int instantNumber,short datafield[],int mdr[],int ar[]);//乘法，函数名是乘法
void Division(int MDRnumber,int ARnumber,int instantNumber,short datafield[],int mdr[],int ar[]);//除法函数，函数名是除法的英文
void Conjunction(int MDRnumber, int ARnumber,int instantNumber,short datafield[],int mdr[],int ar[]);//合取，逻辑与运算
void Disjunction(int MDRnumber, int ARnumber,int instantNumber,short datafield[],int mdr[],int ar[]);//析取，逻辑或运算（都是对应的英文）
void Negation(int MDRnumber, int ARnumber,short datafield[],int mdr[],int ar[]);//取非，逻辑非

//(此注释对应下一行的函数)比较指令，受java中Comparator接口的影响取了Comparator这个名字...(我好喜欢自言自语...)
void Comparator(int MDRnumber, int ARnumber,int sr[],int instantNumber,short datafield[],int mdr[],int ar[]);

void Skip(int MDRnumber,int ARnumber,int InstantNumber,int sr[]);//跳转指令
void Input(int MDRnumber,int mdr[]);//输入函数
void Output(int MDRnumber,int mdr[],int ID);//输出函数，更改了函数原型加了一个参数 int ID，用于符合输出要求
int RegisterNumberTransfer(char IR[],int start,int end);//用于得到寄存器的编号的十进制形式
int InstantNumberTransfer(char instantnumber[]);//补码不对，已修正，用于得到立即数的十进制形式
int IRnumberTransfer(char IR[]);//用于得到指令寄存器寄存的16位指令的十进制形式，拿来输出CPU状态中 ir 的值
void StateOutput(int mdr[],int ar[],int sr[],char IR[],int ID);//CPU状态输出，每执行完一条指令就输出CPU各寄存器的状态
void FieldOutput(char codefield[][33],short datafield[]);//在停机指令后输出代码段和数据段
int NumberTransfer(char codefield[][33],int line);//用于将代码段的一条32位指令转换为十进制，得到的返回值给输出代码段的十进制值用
int main(void)
{
    HANDLE thread1,thread2;//线程句柄
    Arguments argument1,argument2;//结构体，存线程ID和代码段起始位置
    initialization(CodeField,DataField);//将代码段数据段初始化为全0，修了一个奇奇怪怪的bug..
    DataField[0] = 100;//将内存的16384初始化为100，地址寄存器存的地址address和地址所指向的数组单元的下标index满足 index = (address - 16384) / 2
    Load(CodeField);//将指令集读入代码段，对两个核的指令集不在同一个文件的情况处理过了，省去了结构体arguments里的filename[]数组
    hMutex = CreateMutex(NULL,FALSE,NULL);//用于锁住内存16384；
    hMutex2 = CreateMutex(NULL,FALSE,NULL);//用于锁住输出
    argument1.address = 0;//程序计数器的初始值
    argument1.id = 1;//线程ID
    argument2.address = 256;//程序计数器的初始值
    argument2.id = 2;//线程ID
    thread1 = (HANDLE)_beginthreadex(NULL,0,run,&argument1,0,NULL);//开始线程1
    thread2 = (HANDLE)_beginthreadex(NULL,0,run,&argument2,0,NULL);//开始线程2
    WaitForSingleObject(thread1,INFINITE);//等待线程1结束
    CloseHandle(thread1);//删除句柄1
    WaitForSingleObject(thread2,INFINITE);
    CloseHandle(thread2);
    FieldOutput(CodeField,DataField);//线程1和2都结束之后输出代码段和数据段
    return 0;
}
unsigned __stdcall run(void * Parguments)
{
    Arguments* p = (Arguments *) Parguments;
    int ID = p->id;
    int MDR[4] = {0};//数据寄存器编号比对应数组下标大一
    int AR[4] = {0};//地址寄存器编号比对应数组下标大5
    int SR[2] = {0};//系统寄存器，0号是程序计数器，1号是标志寄存器
    SR[0] = p->address;//将程序计数器(IP)初始化为0或256
    char ir[16] = {'0'};//指令寄存器ir，存指令前16位
    char InstantNumber[16] = {'0'};//用于单独储存被取到的指令的后16位立即数部分
    int l;//变量l是取指令函数的返回值，作为循环的控制变量
    l = getInstruction(ir,CodeField,InstantNumber,SR);//取第一条指令，同时判定是否是停机指令，不是停机指令就返回1，是停机指令就返回0，返回0，l = 0 循环结束
    while (l)//l == 1循环继续，l == 0 ,取到停机指令，循环结束(也就是停机了，所以没有写专门的停机函数)
    {
        analyseAndPerform(ir,InstantNumber,DataField,MDR,AR,SR,ID);
        //StateOutput(MDR,AR,SR,ir,ID);//可以把这一行注释掉，这样就可以在执行完指令后不输出CPU状态，只有在执行到Output函数才会有输出票号,方便判定票数是否符合逻辑
        //反正我在自己判定结果正确性的时候注释掉了上面那行，毕竟在一堆CPU的状态值中找 “id =     out：”太难找了
        SR[0] = SR[0] + 4;//改变程序计数器的值，可以放在GetInstruction内，这个更改是在单核版修bug的时候改的，不过发现改了既修不好bug也不会改变任何东西，就懒得放回去了
        l = getInstruction(ir,CodeField,InstantNumber,SR);//取下一条指令
    }
    SR[0] = SR[0] + 4;//停机指令后还要更改一次程序计数器的值
    //StateOutput(MDR,AR,SR,ir,ID);//停机指令后输出停机后的CPU状态
}
void Load(char codefield[][33])
{
    FILE* file1 = fopen("C:\\Users\\jiangyiqing\\Desktop\\dict1.dic","r");//改成"dict1.dic"
    FILE* file2 = fopen("C:\\Users\\jiangyiqing\\Desktop\\dict2.dic","r");//要改成dict2.dic
    for(int i = 0;i < 64; i ++){
        for(int j = 0 ; j < 33 ; j ++){
            char ch = fgetc(file1);
            if((ch != EOF)){
                codefield[i][j] = ch;
            }
        }
    }//这个循环加载第一个线程CPU1的指令集
    for(int i = 64;i < 128; i ++){
        for(int j = 0 ; j < 33 ; j ++){
            char ch = fgetc(file2);
            if((ch != EOF)){
                codefield[i][j] = ch;
            }
        }
    }//加载CPU2的指令集，64是起始行数
    fclose(file1);
    fclose(file2);
}
int getInstruction(char IR[],char codefield[][33],char instant[],int sr[])
{
    int line = sr[0] / 4;//line是要读取的指令的行数，二维数组一行存一条指令
    for(int i = 0;i < 16; i ++){
        IR[i] = codefield[line][i];
    }//这个循环把指令的前十六位存入指令寄存器

    for(int p = 16, q = 0;p < 32;q ++ ,p ++){
        instant[q] = codefield[line][p];
    }//这个循环把当前指令的后16位存入立即数数组

    for(int j = 0; j < 16 ;j ++){
        if(IR[j] != '0'){
            return 1;
        }
    }//这个循环遍历指令的每一位，发现某一位不为0就return1，如果遍历完，发现指令的每一位都是0，说明是停机指令，循环结束，return 0
    return 0;
}
void analyseAndPerform(char IR[],char instant[],short datafield[],int mdr[],int ar[],int sr[],int ID)
{
    int MDRnumber;//数据寄存器编号
    int ARnumber;//指令寄存器编号
    char copy[17];//是指令寄存器的指令的副本，出于数据安全考虑，避免修改原始数据
    for(int i = 0; i < 16; i++){
        copy[i] = IR[i];
    }
    copy[16] = '\0';
    char operation[9];//这个数组存储指令寄存器中的指令的操作码部分
    for(int j = 0 ; j < 8 ; j ++){
        operation[j] = IR[j];
    }
    operation[8] = '\0';//给操作码数组的最后一位加上'\0'，把字符数组变成字符串，方便后续调用字符串比较函数strcmp()
    int number1 = RegisterNumberTransfer(copy,8,11);//指令集8到11位对应的操作对象的十进制编号
    int number2 = RegisterNumberTransfer(copy,12,15);//指令集12-15位对应的操作对象的十进制编号
    //下面是对数据寄存器和地址寄存器编号的确定
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
    //寄存器编号确定完毕
    int ins = InstantNumberTransfer(instant);//得到立即数的十进制形式
    //下面是用字符串比较的方式确定执行哪一个操作
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
        Lock(ins);
    }
    else if(strcmp(operation,"00001110") == 0){
        Unlock(ins);
    }
    else if(strcmp(operation,"00001111") == 0){
        Sleepy(ins);
    }
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
        int index = (ar[ARnumber - 5] - 16384) / 2;
        int a = datafield[index];
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
    printf("id = %d    ",ID);
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
    WaitForSingleObject(hMutex2,INFINITE);
    printf("id = %d\n",ID);
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
    ReleaseMutex(hMutex2);
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
void Sleepy(int instantNumber)
{
    Sleep(instantNumber);
}
void Lock(int instant)
{
    //hMutex = CreateMutex(NULL,FALSE,"DataField[(instant - 16384) /2]");
    WaitForSingleObject(hMutex,INFINITE);
}
void Unlock(int instant)
{
    //hMutex = CreateMutex(NULL,FALSE,"DataField[(instant - 16384) /2]");
    ReleaseMutex(hMutex);
}