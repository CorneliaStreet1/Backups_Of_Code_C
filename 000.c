#include<stdio.h>
int  main(void)
{
  int n;
  scanf("%d",&n);
  int a[n];
  int max;
  for(int i = 0; i < n ; i ++){
    scanf("%d", &a[i]);
  }
  for(int j = 0 ; j < n ; j ++){
    max = a[0];
    if(max < a[j]){
      max = a[j];
    }
  }
  int max_[10] ={0},m = 0;
  for(int l = 0 ; l < n ; l ++){
    if(a[l] == max){
      max_[m] = l;
      m ++;
    }
  }
  int min =max_[0];
  for (int k = 0; k < 10; k ++)
  {
    if(min > max_[k] && max_[k] != 0){
      min = max_[k];
    }
  }
  printf("%d",min);
  return 0;
}