#include<stdio.h>
void display(char , int , int  );
int main(void)
{
    int ch;
    int rows, cols;
    printf("Enter a character and two integers\n");
    while((ch = getchar()) != '\n'){
        scanf("%d%d",&rows,&cols);
        getchar();
        display(ch,rows,cols);
        printf("Enter another character and two intgegers;\n");
        printf("Enter a new line to quit.\n");
    }
    printf("Bye.\n");
    return 0;
}
void display(char ch , int lines  , int width )
{
    int row ,col;
    for(int row = 1; row <= lines ;row ++){
        for(int col = 1 ; col <= width;col ++){
            putchar(ch);
        }
        putchar('\n');
    }
}