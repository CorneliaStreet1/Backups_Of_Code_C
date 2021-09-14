#include <stdio.h>
char *locatesubstr(char *str1,char *str2);
int main()
{
    char str1[505],str2[505];
    char *p;
    gets(str1);
    gets(str2);
    p=locatesubstr(str1,str2);

    if(p==NULL)    printf("NULL!\n");
    else    puts(p);

    return 0;
}
char *locatesubstr(char *str1,char *str2)
{
    char *p = NULL;
    

}