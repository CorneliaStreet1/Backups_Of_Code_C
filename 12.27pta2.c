#include<stdio.h>
//字符串转换函数，将source按规则转换后保存在target中
void    getCounts(char source[] , char target[] ) ;
int main()
{
    char    source[100000] , target[100];
    scanf( "%s" , source ) ;
    getCounts( source , target ) ;
    printf( "%s\n" , target ) ;
    return 0 ;
}
void    getCounts(char source[] , char target[] )
{
    int a = 0 ,b = 0 ,c = 0 ,d = 0 ,e = 0 ,j = 0 ,f = 0 ,g = 0,h = 0,p = 0;
    target[100] = { target[0] = '0' ,target[2] = '1' , target[4] = '2',target[6] = '3' ,tagret[8] = '4' ,target[10] = '5' ,target[12] = '6' ,target[] = '7',target[14] = '8',targer[16] = '9',target[18] = '\0'};
    for(int i = 0 ;i < 100000 ; i ++){
        if(source[i] == '0'){
            a ++;
        }
        if(source[i] == '1'){
            b ++;
        }
        if(source[i] == '2'){
            c ++;
        }
        if(source[i] == '3'){
            d ++;
        }
        if(source[i] == '4'){
            e ++;
        }
        if(source[i] == '5'){
            f ++;
        }
        if(source[i] == '6'){
            g ++;
        }
        if(source[i] == '7'){
            h ++;
        }
        if(source[i] == '8'){
            p ++;
        }
        if(source[i] == '9'){
            j ++;
        }
    }
    
}