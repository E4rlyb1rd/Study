#include <stdio.h>

void result(int num);

int main(){
    int input;
    int output = 0;

    scanf("%d",&input);

    if(input<10)
    printf("%d",input);
    
    else
    result(input);
}
int result(int num){
    if(num < 10)
    printf("%d\n",num);

    else{
        result(num / 10);
        printf("%d\n",num%10);
    }
}