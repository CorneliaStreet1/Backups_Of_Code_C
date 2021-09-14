#include <stdio.h>
typedef struct
{
    char id[16]  ;//学生账号 
    int total ;    //综合成绩 
    int ce ;    //机试成绩 
    int ws ;    //加权成绩 
}STUDENT;
void Sort(STUDENT a[],int size) ; 
void Swap(STUDENT * s1,STUDENT * s2) ;
int  Comp(STUDENT * s1,STUDENT * s2) ;
int main()
{
    STUDENT stu[100] ;
    int i , n;
    scanf("%d",&n) ;
    for(i=0;i<n;i++)
    {
        scanf("%s%d%d",stu[i].id,&stu[i].ce,&stu[i].ws) ;
        stu[i].total = stu[i].ce+stu[i].ws ;
    }
    Sort(stu,n) ;
    for(i=0;i<n;i++)
    printf("%s %d %d %d\n",stu[i].id,stu[i].total,stu[i].ce,stu[i].ws) ;
    return 0;    
}
void Swap(STUDENT * s1,STUDENT * s2)
{
    int a = s1 -> total;
    int b = s1 -> ce;
    int c = s1 -> ws;
    s1 -> total = s2 -> total;
    s1 -> ce = s2 -> ce;
    s1 -> ws = s2 -> ws;
    s2 -> ws = c;
    s2 -> ce = b;
    s2 -> total = a;
    char temp[16];
    for(int i = 0 ; i < 16 ; i ++){
        temp[i] = (s1 -> id[i]);
    }
    for(int l = 0 ; l < 16 ; l ++){
        (s1 -> id[l]) = (s2 -> id[l]);
    }
    for(int k = 0 ; k < 16 ; k++){
        (s2 -> id[k]) = temp[k];
    }
}
int Comp(STUDENT * s1,STUDENT * s2)
{
    int is = 0;
    if(s1 -> total > s2 -> total){
        is = 1;
    }
    else if((s1 -> total == s2 -> total) && (s1 -> ce > s2 -> ce)){
        is = 1;
    }
    else
    {
        is = 0;
    }
    return is;
}
void Sort(STUDENT a[],int size)
{
    for(int i = 0 ;i < size ; i++){
        for(int j = 0 ; j < size - 1 - i ; j ++){
            int p = Comp( &a[j], &a[j + 1]);
            if(p == 0)
            Swap(&a[j] ,&a [j + 1]);
        }
    }
}