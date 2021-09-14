#include<stdio.h>
#include<stdlib.h>
# include <windows.h>
# include <process.h> 

HANDLE hMutex;
HANDLE outMutex;
int Memory[330000];
typedef struct Code
{
    int ax[8];
    int id, ip, ir, flag;
    int Operation_object1, Operation_object2, Operation_object3, Immediate_number, Operation_object4, Operation_sum;
    int Instruction_set1[1500];//���������� 
 }CODE;
unsigned __stdcall Fun1 (void* pArguments);
unsigned __stdcall Fun2 (void* pArguments);
void Runcode(char Operation_code[], CODE*, int, FILE**);//ִ�д���
void Assignment0_close(CODE*);//ͣ��ָ��
void Assignment1_data_transfer(CODE*);//�������ݴ���
void Assignment2_calculate(CODE*);//������������1 
void Assignment3_calculate(CODE*);//������������2
void Assignment4_calculate(CODE*);//������������3
void Assignment5_calculate(CODE*);//������������4
void Assignment6_logic_calculate(CODE*);//�����߼�����1
void Assignment7_logic_calculate(CODE*);//�����߼�����2
void Assignment8_logic_calculate(CODE*);//�����߼�����3
void Assignment9_compare(CODE*);//�Ƚ�ָ��
int Assignment10_skip(CODE*);//��תָ��
void Assignment11_input(CODE*);//����ָ��
void Assignment12_output(CODE*);//���ָ��
void Output_status(CODE*);//���״̬ 
void Final_Output();
int Convert_numbers(char object[], int, int);//����ת�� 
 
int main()
{
	//outMutex=CreateMutex (NULL, FALSE, NULL);
	//hMutex=CreateMutex (NULL, FALSE, NULL);
	//HANDLE hThread1, hThread2; 
	//hThread1=(HANDLE) _beginthreadex(NULL, 0, Fun1, NULL, 0, NULL); 
	//hThread2=(HANDLE) _beginthreadex(NULL, 0, Fun2, NULL, 0, NULL);
	//WaitForSingleObject(hThread1,INFINITE);
	//CloseHandle(hThread1);
	//WaitForSingleObject(hThread2,INFINITE);
    //CloseHandle(hThread2);
    Fun1(NULL);
    Final_Output();
    return 0;   
 } 
unsigned __stdcall Fun1 (void* pArguments)
{
	CODE Code1;
    CODE *CodePtr1 = &Code1;
    (*CodePtr1).id = 1;
    int i = 0, j = 0, k, codesegcnt=0;
    char ch;
    char order[32];
    FILE *fp = fopen("C:\\Users\\jiangyiqing\\Desktop\\dict1.dic","r");
    ch = fgetc(fp);
    while(ch != EOF)
    {
        if(ch != '\n')
        {
            order[i] = ch;
            i++;
        }//��ÿһ�д���order�� 
        else
        {   
            (*CodePtr1).Instruction_set1[codesegcnt] = Convert_numbers(order, 2, 32);
            codesegcnt+=4;
            i=0;
        } 
        ch = fgetc(fp);
    }
    fseek(fp,0,SEEK_SET);
    ch = fgetc(fp);
    while(ch != EOF)
    {
        if(ch != '\n')
        {
            order[i] = ch;
            i++;
        }//��ÿһ�д���order�� 
        else
        {
            Runcode(order, CodePtr1, j, &fp);
            i=0;
            j++;
        } 
        ch = fgetc(fp);
    }
}
unsigned __stdcall Fun2 (void* pArguments)
{
	CODE Code2;
    CODE *CodePtr2 = &Code2;
    (*CodePtr2).id = 2;
    (*CodePtr2).ip = 256;
    int i = 0, j = 0, k, codesegcnt=0;
    char ch;
    char order[32];
    FILE *fp = fopen("dict.dic","r");
    ch = fgetc(fp);
    while(ch != EOF)
    {
        if(ch != '\n')
        {
            order[i] = ch;
            i++;
        }//��ÿһ�д���order�� 
        else
        {   
            (*CodePtr2).Instruction_set1[codesegcnt] = Convert_numbers(order, 2, 32);
            codesegcnt+=4;
            i=0;
        } 
        ch = fgetc(fp);
    }
    fseek(fp,0,SEEK_SET);
    ch = fgetc(fp);
    while(ch != EOF)
    {
        if(ch != '\n')
        {
            order[i] = ch;
            i++;
        }//��ÿһ�д���order�� 
        else
        {
            Runcode(order, CodePtr2, j, &fp);
            i=0;
            j++;
        } 
        ch = fgetc(fp);
    }
}
void Runcode(char Operation_code[32], CODE *CodePtr, int j, FILE **fp)//ִ�д���
{
    int i;
    int isChange;
    char object1[9] = {0}, object2[5] = {0}, object3[5] = {0}, object4[17] = {0}, object5[17] = {0};
    for(i = 0; i<8; i++)
    {
        object1[i] = Operation_code[i]; 
    }
    for(i = 8; i<12; i++)
    {
        object2[i-8] = Operation_code[i];
        object3[i-8] = Operation_code[i+4];
    }
    for(i = 16; i<32; i++)
    {
        object4[i-16] = Operation_code[i];
        object5[i-16] = Operation_code[i-16]; 
    }
    (*CodePtr).Operation_object1 = Convert_numbers(object1, 2, 8);//ǰ��λת��10����
    (*CodePtr).Operation_object2 = Convert_numbers(object2, 2, 4); 
    (*CodePtr).Operation_object3 = Convert_numbers(object3, 2, 4);
    (*CodePtr).Operation_object4 = Convert_numbers(object5, 2, 16);
    (*CodePtr).Operation_sum = Convert_numbers(Operation_code, 2, 32);
    (*CodePtr).Immediate_number= Convert_numbers(object4, 0, 16);//������ת��Ϊʮ���� 
     
    if((*CodePtr).Operation_object1 == 0)
    { 
        Assignment0_close(CodePtr);
    }
    else if((*CodePtr).Operation_object1 == 1)
    {
        Assignment1_data_transfer(CodePtr);
    }
    else if((*CodePtr).Operation_object1 == 2)
    {
        Assignment2_calculate(CodePtr);
    }
    else if((*CodePtr).Operation_object1 == 3)
    {
        Assignment3_calculate(CodePtr);
    }
    else if((*CodePtr).Operation_object1 == 4)
    {
        Assignment4_calculate(CodePtr);
    }
    else if((*CodePtr).Operation_object1 == 5)
    {
        Assignment5_calculate(CodePtr);
    }
    else if((*CodePtr).Operation_object1 == 6)
    {
        Assignment6_logic_calculate(CodePtr);
    }
    else if((*CodePtr).Operation_object1 == 7)
    {
        Assignment7_logic_calculate(CodePtr);
    }
    else if((*CodePtr).Operation_object1 == 8)
    {
        Assignment8_logic_calculate(CodePtr);
    }
    else if((*CodePtr).Operation_object1 == 9)
    {
        Assignment9_compare(CodePtr);
    }
    else if((*CodePtr).Operation_object1 == 10)
    {
          
        isChange=Assignment10_skip(CodePtr);
        if(isChange==1){
            int line = (*CodePtr).ip/4;
            //printf("%d\n",line);
            fseek(*fp, 33*line, SEEK_SET);
            isChange=0;
        }
 
    }
    else if((*CodePtr).Operation_object1 == 11)
    {
        Assignment11_input(CodePtr);
    }
    else if((*CodePtr).Operation_object1 == 12)
    {
        Assignment12_output(CodePtr);
    }
    else if((*CodePtr).Operation_object1 == 13)
    {
        WaitForSingleObject(hMutex, INFINITE);
    }
    else if((*CodePtr).Operation_object1 == 14)
    {
        ReleaseMutex (hMutex); 
    }
    else if((*CodePtr).Operation_object1 == 15)
    {
        Sleep((*CodePtr).Immediate_number);          
    }
 }
 int Convert_numbers(char object[], int p, int line)//��p�Ľ���ת��Ϊn�Ľ���,0�������� 
 {
    int j, ret = 0;
    if(p != 0)
    {
        for(j = 0; j < line; j++)
        {
            ret = ret*p + object[j] - '0'; 
        }
    }
    else
    {
        if(object[0] - '0' == 0)
        {
            for(j = 0; j < line; j++)
            {
                ret = ret*2 + object[j] - '0'; 
            }
        }
        if(object[0] - '0' == 1)
        {
            for(j = 1; j < line; j++)
            {
                if(object[j] == '0') object[j] = '1';
                else if (object[j] == '1') object[j] = '0';
            }
            for(j = 1; j < line; j++)
            {
                ret = ret*2 + object[j] - '0'; 
            }
            ret = -1*ret - 1;
        }
    } 
    return ret;
  } 
void Assignment1_data_transfer(CODE* CodePtr)//�������ݴ���
{
    if((*CodePtr).Operation_object3 == 0) (*CodePtr).ax[(*CodePtr).Operation_object2 - 1] = (*CodePtr).Immediate_number;
    else if((*CodePtr).Operation_object3 >= 5) (*CodePtr).ax[(*CodePtr).Operation_object2 - 1] = Memory[(*CodePtr).ax[(*CodePtr).Operation_object3-1]];
    else Memory[(*CodePtr).ax[(*CodePtr).Operation_object2-1]] = (*CodePtr).ax[(*CodePtr).Operation_object3 - 1];
    (*CodePtr).ip = (*CodePtr).ip + 4;
    (*CodePtr).ir = (*CodePtr).Operation_object4;
    Output_status(CodePtr);
} 
void Assignment2_calculate(CODE* CodePtr)//������������1 
{
    if((*CodePtr).Operation_object3 == 0) (*CodePtr).ax[(*CodePtr).Operation_object2 - 1] = (*CodePtr).ax[(*CodePtr).Operation_object2 - 1] + (*CodePtr).Immediate_number;
    else (*CodePtr).ax[(*CodePtr).Operation_object2 - 1] = (*CodePtr).ax[(*CodePtr).Operation_object2 - 1] + Memory[(*CodePtr).ax[(*CodePtr).Operation_object3-1]];
    (*CodePtr).ip = (*CodePtr).ip + 4;
    (*CodePtr).ir = (*CodePtr).Operation_object4;
    Output_status(CodePtr);
}
void Assignment3_calculate(CODE* CodePtr)//������������2
{
    if((*CodePtr).Operation_object3 == 0) (*CodePtr).ax[(*CodePtr).Operation_object2 - 1] = (*CodePtr).ax[(*CodePtr).Operation_object2 - 1] - (*CodePtr).Immediate_number;
    else (*CodePtr).ax[(*CodePtr).Operation_object2 - 1] = (*CodePtr).ax[(*CodePtr).Operation_object2 - 1] - Memory[(*CodePtr).ax[(*CodePtr).Operation_object3-1]];
    (*CodePtr).ip = (*CodePtr).ip + 4;
    (*CodePtr).ir = (*CodePtr).Operation_object4;
    Output_status(CodePtr);
}
void Assignment4_calculate(CODE* CodePtr)//������������3
{
    if((*CodePtr).Operation_object3 == 0) (*CodePtr).ax[(*CodePtr).Operation_object2 - 1] = (*CodePtr).ax[(*CodePtr).Operation_object2 - 1] * (*CodePtr).Immediate_number;
    else (*CodePtr).ax[(*CodePtr).Operation_object2 - 1] = (*CodePtr).ax[(*CodePtr).Operation_object2 - 1] * Memory[(*CodePtr).ax[(*CodePtr).Operation_object3-1]];
    (*CodePtr).ip = (*CodePtr).ip + 4;
    (*CodePtr).ir = (*CodePtr).Operation_object4;
    Output_status(CodePtr);
}
void Assignment5_calculate(CODE* CodePtr)//������������4
{
    if((*CodePtr).Operation_object3 == 0) (*CodePtr).ax[(*CodePtr).Operation_object2 - 1] = (*CodePtr).ax[(*CodePtr).Operation_object2 - 1] / (*CodePtr).Immediate_number;
    else (*CodePtr).ax[(*CodePtr).Operation_object2 - 1] = (*CodePtr).ax[(*CodePtr).Operation_object2 - 1] / Memory[(*CodePtr).ax[(*CodePtr).Operation_object3-1]];
    (*CodePtr).ip = (*CodePtr).ip + 4;
    (*CodePtr).ir = (*CodePtr).Operation_object4;
    Output_status(CodePtr);
}
void Assignment6_logic_calculate(CODE* CodePtr)//�����߼�����1
{
    if((*CodePtr).Operation_object3 == 0) (*CodePtr).ax[(*CodePtr).Operation_object2 - 1] = ((*CodePtr).ax[(*CodePtr).Operation_object2 - 1]) && ((*CodePtr).Immediate_number);
    else (*CodePtr).ax[(*CodePtr).Operation_object2 - 1] = (*CodePtr).ax[(*CodePtr).Operation_object2 - 1] && Memory[(*CodePtr).ax[(*CodePtr).Operation_object3-1]];
    (*CodePtr).ip = (*CodePtr).ip + 4;
    (*CodePtr).ir = (*CodePtr).Operation_object4;
    Output_status(CodePtr);
}
void Assignment7_logic_calculate(CODE* CodePtr)//�����߼�����2
{
    if((*CodePtr).Operation_object3 == 0) (*CodePtr).ax[(*CodePtr).Operation_object2 - 1] = (*CodePtr).ax[(*CodePtr).Operation_object2 - 1] || (*CodePtr).Immediate_number;
    else (*CodePtr).ax[(*CodePtr).Operation_object2 - 1] = (*CodePtr).ax[(*CodePtr).Operation_object2 - 1] || Memory[(*CodePtr).ax[(*CodePtr).Operation_object3-1]];
    (*CodePtr).ip = (*CodePtr).ip + 4;
    (*CodePtr).ir = (*CodePtr).Operation_object4;
    Output_status(CodePtr);
}
void Assignment8_logic_calculate(CODE* CodePtr)//�����߼�����3
{
    if((*CodePtr).Operation_object3 == 0) (*CodePtr).ax[(*CodePtr).Operation_object2 - 1] = !(*CodePtr).ax[(*CodePtr).Operation_object2 - 1];
    else Memory[(*CodePtr).ax[(*CodePtr).Operation_object3-1]] =! Memory[(*CodePtr).ax[(*CodePtr).Operation_object3-1]];
    (*CodePtr).ip = (*CodePtr).ip + 4;
    (*CodePtr).ir = (*CodePtr).Operation_object4;
    Output_status(CodePtr);
}
void Assignment9_compare(CODE* CodePtr)//�Ƚ�ָ��
{
    if((*CodePtr).Operation_object3 == 0) 
    {
        if((*CodePtr).ax[(*CodePtr).Operation_object2 - 1] == (*CodePtr).Immediate_number) (*CodePtr).flag = 0;
        else if((*CodePtr).ax[(*CodePtr).Operation_object2 - 1] > (*CodePtr).Immediate_number)   (*CodePtr).flag = 1;
        else (*CodePtr).flag = -1;
    }
    else
    {
        if((*CodePtr).ax[(*CodePtr).Operation_object2 - 1] == Memory[(*CodePtr).ax[(*CodePtr).Operation_object3-1]]) (*CodePtr).flag = 0;
        else if((*CodePtr).ax[(*CodePtr).Operation_object2 - 1] > Memory[(*CodePtr).ax[(*CodePtr).Operation_object3-1]]) (*CodePtr).flag = 1;
        else (*CodePtr).flag = -1;
    }
    (*CodePtr).ip = (*CodePtr).ip + 4;
    (*CodePtr).ir = (*CodePtr).Operation_object4;
    Output_status(CodePtr);
}
int Assignment10_skip(CODE* CodePtr)//��תָ��
{
    int isChange=0;
    (*CodePtr).ip+=4;
    if((*CodePtr).Operation_object3 == 0){
        (*CodePtr).ip = (*CodePtr).ip + (*CodePtr).Immediate_number-4 ;
        isChange=1;
    }
    if((*CodePtr).Operation_object3 ==1){
        if((*CodePtr).flag == 0){
            (*CodePtr).ip = (*CodePtr).ip + (*CodePtr).Immediate_number-4 ;
            isChange=1;
        }
    }
    if((*CodePtr).Operation_object3 == 2){
        if((*CodePtr).flag == 1){
            (*CodePtr).ip = (*CodePtr).ip + (*CodePtr).Immediate_number-4 ;
            isChange=1;
        }
    }
    if((*CodePtr).Operation_object3 == 3){
        if((*CodePtr).flag == -1){
            (*CodePtr).ip = (*CodePtr).ip + (*CodePtr).Immediate_number-4 ;
            isChange=1;
        }
    }
         
    (*CodePtr).ir = (*CodePtr).Operation_object4;
     
    Output_status(CodePtr);
    return isChange;
}
void Assignment11_input(CODE* CodePtr)//����ָ��
{
    printf("in:\n");
    scanf("%d", &(*CodePtr).ax[(*CodePtr).Operation_object2 - 1]);
    (*CodePtr).ip = (*CodePtr).ip + 4;
    (*CodePtr).ir = (*CodePtr).Operation_object4;
    Output_status(CodePtr);
}
void Assignment12_output(CODE* CodePtr)//���ָ��
{
	WaitForSingleObject(outMutex,INFINITE); 	
    printf("id=%d	out: %d\n", (*CodePtr).id , (*CodePtr).ax[(*CodePtr).Operation_object2 - 1]);
    (*CodePtr).ip = (*CodePtr).ip + 4;
    (*CodePtr).ir = (*CodePtr).Operation_object4;
    Output_status(CodePtr);
    ReleaseMutex (outMutex);
}
void Output_status(CODE* CodePtr)//���״̬
{
    int i;
    printf("id=%d\nip = %d\nflag = %d\nir = %d\n",(*CodePtr).id ,(*CodePtr).ip,(*CodePtr).flag,(*CodePtr).ir);
    for(i = 0;i <= 3;i++)
    {
        if(i == 3)
            printf("ax%d = %d\n",i + 1,(*CodePtr).ax[i]);
        else
            printf("ax%d = %d ",i + 1,(*CodePtr).ax[i]);
    }
    for(i = 4;i <= 7;i++)
    {
        if(i == 7)
            printf("ax%d = %d\n",i+1,(*CodePtr).ax[i]);
        else
            printf("ax%d = %d ",i+1,(*CodePtr).ax[i]);
    }
    printf("\n");
}
void Assignment0_close(CODE* CodePtr)//ͣ��ָ��
{
    int i;
    (*CodePtr).ip = (*CodePtr).ip + 4;
    (*CodePtr).ir = (*CodePtr).Operation_object4;
    Output_status(CodePtr);
    printf("\ncodeSegment :\n");
    for(i = 0;i <= 63*4; i+=4) //�����и���һ����128��ָ��
    {
        if((i+4) % 32 == 0) //���������±��0��ʼ�����Ҫ+1�жϽ���λ��
            printf("%d\n", (*CodePtr).Instruction_set1[i]);
        else
            printf("%d ", (*CodePtr).Instruction_set1[i]);
    }
}
void Final_Output()
{
    for(int i = 0;i <= 255*2; i+=2)//�����й���256��״̬
    {
        if((i + 2) % 32 == 0)
            printf("%d\n", Memory[16384+i]);
        else
            printf("%d ", Memory[16384+i]);
    }
}
