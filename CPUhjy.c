#include<stdio.h>
#include<math.h>
#define maxnum 128  //���521��ָ�ʾ����Щ 
int flag;  //��־�Ĵ��� 
int ip;  //��������� 
int n;  //ͣ��ָ���־ 
int IRnumberTransfer(char IR[]);
void readfile(char a[][33]);
void fetch(char a[][33], char ir[]);
void analyze(char ir[], int* p1, int* p21, int* p22, int* p3, int data[], int ku[]);
void Load(char codefield[][33]);
void chuansong( int* p21, int* p22, int* p3, int data[], int ku[]);
void suanshu1( int* p21, int* p22, int* p3, int data[], int ku[]);
void suanshu2( int* p21, int* p22, int* p3, int data[], int ku[]);
void suanshu3( int* p21, int* p22, int* p3, int data[], int ku[]);
void suanshu4( int* p21, int* p22, int* p3, int data[], int ku[]);
int getInstruction(char IR[],char codefield[][33]);
void luoji1( int* p21, int* p22, int* p3, int data[], int ku[]);
void luoji2( int* p21, int* p22, int* p3, int data[], int ku[]);
void luoji3( int* p21, int* p22, int data[], int ku[]);

void bijiao( int* p21, int* p22, int* p3, int data[], int ku[]);
void tiaozhuan( int* p21, int* p22, int* p3);
void shuru( int* p21, int data[]);
void zhuangtai(int* p1, int* p21, int* p22, int data[]);
void shuchu(char a[][33], int ku[]);

int main()
{
	char a[maxnum][33];
	int ku[32768]={0};  //���������Ϊ32767,Ҫ����� 256������ 
	char ir[33];
	int p1, p21, p22, p3;
	int data[8]={0};
	Load(a);
	while(n!=1)
	{
		int IP = ip;
		int Flag = flag;
		int N = n;
		fetch(a,ir);
		ip+=4;
		analyze(ir, &p1, &p21, &p22, &p3, data, ku);
		int caozuoma = p1;
		int left = p21;
		int right = p22;
		int intsant = p3;
		zhuangtai(&p1, &p21, &p22, data);
	}
	shuchu(a, ku);
	return 0; 
} 

void readfile(char a[][33])
{
	int i=0, j=0;
	FILE *fp=fopen("C:\\Users\\jiangyiqing\\Desktop\\dict.dic","r");
	
	if(fp)
	{
		char ch=fgetc(fp);
		while(i<maxnum && !feof(fp))
		{
			for( ;j<32;j++)
			{
				a[i][j]=ch;
				ch=fgetc(fp);
			}
			if(ch=='\n')
			ch=fgetc(fp);
			i++;
		}
		
		fclose(fp);
	}
	
}

void fetch(char a[][33], char ir[])
{
	int i;
	for(i=0;i<33;i++)
	{
		ir[i]=a[ip/4][i];
	}
} 

void analyze(char ir[], int* p1, int* p21, int* p22, int* p3, int data[], int ku[])
{
	int i;
	*p1 = 0;
	*p21= 0; 
	*p22 = 0;
	*p3 = 0;
	for(i=0;i<33;i++)  //�Ĳ��ֶ�����תʮ���� 
	{
		if(i<8){
			(*p1) = (*p1) * 2 + (ir[i]-'0');
			int P1 = *p1;
		}
		else if(i>=8&&i<12)
		*p21=*p21*2+(ir[i]-'0');
		
		else if(i>=12&&i<16)
		*p22=*p22*2+(ir[i]-'0');
		
		else if(i>=16&&i<32)
		*p3=*p3*2+(ir[i]-'0');
	}
	if(*p3>32767)
	*p3=*p3-65536;  //������Ϊ����
	
	switch(*p1)  //����ָ�� 
	{
		case 0: n = 0; break;
		case 1: chuansong(p21, p22, p3, data, ku); break;
		case 2: suanshu1(p21, p22, p3, data, ku); break;
		case 3: suanshu2(p21, p22, p3, data, ku); break;
		case 4: suanshu3(p21, p22, p3, data, ku); break;
		case 5: suanshu4(p21, p22, p3, data, ku); break;
		case 6: luoji1(p21, p22, p3, data, ku); break;
		case 7: luoji2(p21, p22, p3, data, ku); break;
		case 8: luoji3(p21, p22, data, ku); break;
		case 9: bijiao( p21, p22, p3, data, ku); break;
		case 10: ip+=*p3; break;
		case 11: shuru(p21, data); break;
		case 12: printf("out: %d\n",data[*p21-1]); break;
		
	}
}

void chuansong( int* p21, int* p22, int* p3, int data[], int ku[])
{
	if(*p22==0)
	data[*p21-1]=*p3;
	else if(*p21<=4&&*p22>4)
	data[*p21-1]=ku[data[*p22-1]-16384];
	else if(*p21>4&&*p22<=4)
	ku[data[*p21-1]-16384]=data[*p22-1];
}

void suanshu1( int* p21, int* p22, int* p3, int data[], int ku[])
{
	if(*p22==0)
	data[*p21-1]+=*p3;
	else if(*p21<=4&&*p22>4)
	data[*p21-1]+=ku[data[*p22-1]-16384];
}

void suanshu2( int* p21, int* p22, int* p3, int data[], int ku[])
{
	if(*p22==0)
	data[*p21-1]-=*p3;
	else if(*p21<=4&&*p22>4)
	data[*p21-1]-=ku[data[*p22-1]-16384];
}

void suanshu3( int* p21, int* p22, int* p3, int data[], int ku[])
{
	if(*p22==0)
	data[*p21-1]*=*p3;
	else if(*p21<=4&&*p22>4)
	data[*p21-1]*=ku[data[*p22-1]-16384];
}

void suanshu4( int* p21, int* p22, int* p3, int data[], int ku[])
{
	if(*p22==0)
	data[*p21-1]/=*p3;
	else if(*p21<=4&&*p22>4)
	data[*p21-1]/=ku[data[*p22-1]-16384];
}

void luoji1( int* p21, int* p22, int* p3, int data[], int ku[])
{
	if(*p22==0)
	data[*p21-1]=data[*p21-1]&&*p3;
	else if(*p21<=4&&*p22>4)
	data[*p21-1]=data[*p21-1]&&ku[data[*p22-1]-16384];
}

void luoji2( int* p21, int* p22, int* p3, int data[], int ku[])
{
	if(*p22==0)
	data[*p21-1]=data[*p21-1]||*p3;
	else if(*p21<=4&&*p22>4)
	data[*p21-1]=data[*p21-1]||ku[data[*p22-1]-16384];
}

void luoji3( int* p21, int* p22, int data[], int ku[])
{
	if(*p22==0)
	{
		if(data[*p21-1]!=0)
		data[*p21-1]=1;
		else data[*p21-1]=0;
	}
	if(*p21==0)
	{
		if(ku[data[*p22-1]-16384]!=0)
		ku[data[*p22-1]-16384]=1;
		else ku[data[*p22-1]-16384]=0;
	}
}

void bijiao( int* p21, int* p22, int* p3, int data[], int ku[])
{
	if(*p22==0)
	{
		if(data[*p21-1]==*p3)
		flag=0;
		else if(data[*p21-1]>*p3)
		flag=1;
		else if(data[*p21-1]<*p3)
		flag=-1;
	}
	if(*p21<=4&&*p22>4)
	{
		if(data[*p21-1]==ku[data[*p22-1]-16384])
		flag=0;
		else if(data[*p21-1]>ku[data[*p22-1]-16384])
		flag=1;
		else if(data[*p21-1]>ku[data[*p22-1]-16384])
		flag=-1;
	}
}

void shuru(int* p21, int data[])
{
	printf("in:\n");
	
	scanf("%d",&data[*p21-1]);
	printf("\n");
}

void zhuangtai(int* p1, int* p21, int* p22, int data[])
{
	int x,i=0;
	x=*p1*256+*p21*16+*p22;
	printf("ip = %d\nflag = %d\n ir = %d\n",ip,flag,x);
	for( ;i<8;i++)
	{
		printf("ax%d = %d ",i+1,data[i]);
		if((i+1)%4==0)
		{
			printf("\n");
		} 
	}
}

void shuchu(char a[][33], int ku[])
{
	char b[128];
	int i,j;
	for(i=0;i<ip/4;i++)
	{
		for(j=0;j<32;j++)
		{
			b[i]=a[i][j]+b[i]*2;
		}
	}
	printf("\ncodeSegment :\n");
	for(i=0;i<ip/4;i++)
	{
		printf("%d ",b[i]);
		if((i+1)%8==0)
		printf("\n");
	}
	for( ;i<128;i++)
	{
		printf("0 ");
		if((i+1)%8==0)
		printf("\n");
	}
	
	printf("\ndataSegment :\n");
	j=0;
	while(j<256)
	{
		printf("%d ",ku[j]);
		j++;
		if((j+1)%16==0)
		printf("\n");
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