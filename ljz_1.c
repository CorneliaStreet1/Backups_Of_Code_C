#include <stdio.h>
int main()
{
    char a[100];
    gets(a);
    int i;
    int n;
    for(i=0;i<100;i++)
    {
        if(a[i]=='(')
            {
                for(n=i+1;n<100;n++)
            {
                if(a[n]==')')
                   {
                       n++;
                       i=n;
                       break;
                   }
                else continue;
            }
    }
    printf("%c",a[i]);
    }
    return 0;
}