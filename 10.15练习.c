#include<stdio.h>
int main(void)
{

   char letter;
   printf("plesae input a char:");
   scanf("%c",&letter);
   if(letter>='a'&&letter<='z')
   printf("this is a ...letter");
   else
   if(letter>='A'&&letter<='Z')
   printf("This is A....letter");
   else
   {
       if(letter>='0'&&letter<='9');
       printf("00000");
   }
   
   return 0;
}