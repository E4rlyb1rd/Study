#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int c(int month,int day){
  if(day < 1){
    return 0;
  }
  switch(month)
{
  case 1: case 3: case 5: case 7: case 8: case 10: 

  case 12:
  return day <= 31 ? 1:0;
  
  case 2:
 
  return day <= 29 ? 1:0;
 
  default:
  return day <= 30 ? 1:0;
  }
}
int main(void){
  int month,day;

  scanf("%d %d",&month,&day);
  if(c(month,day)==0){
    printf("BAD!");
  }
  else{
    printf("OK!");
  }
}