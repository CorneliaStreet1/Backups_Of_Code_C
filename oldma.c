#include<stdio.h>
int main(void)
{ 
  int counter=0;
  char ch,ch_1,ch_2;//默认ch1是更小的那个
  scanf("%c %c",&ch_1,&ch_2);
  ch=ch_1;
  while(ch>=ch_1&&ch<ch_2){
    ch++;
    printf("%c ",ch);
    counter++;
    if(counter %10 == 0){
      printf("\n");
    }
  }
  return 0;
}