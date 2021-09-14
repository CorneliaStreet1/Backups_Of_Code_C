#include<stdio.h>
typedef struct
{
    int year;
    int month;
    int day;
} date;

typedef struct 
{
    char name[15];
    int number[15];
    date;
} phone;

int main(void)
{
    int n;
    scanf("%d", &n);
    phone phones[n];
    for(int i = 0 ; i < n ;i ++){
        scanf("%s", phones[i].name);
        scanf("%d", phones[i].number);
        scanf("%d%d%d",phones[i].date.year, phones[i].date.month , phones[i].date.day);
    }
    int m;
    scanf("%d", &m);
    for(int k = 0 ;k < m ; k ++){
        int operate,num;
        scanf("%d", &operate);
    }
    
}