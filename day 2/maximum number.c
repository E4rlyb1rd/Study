#include <stdio.h>

int maxValue(int n,int *input);

int main(){
    int n;
    int input[20];
    int i=0;
    int result =0;

    scanf("%d",&n);

    for(i=0;i<n;i++){
        scanf("%d",&input[i]);

    }
    result = maxValue(n-1,input);
    printf("%d",result);

}
int maxValue(int n,int *input){
    int m;
    if(n==0)
    return input[0];

    m=maxValue(n-1,input);
   
    if(m <input[n])
         return input[n];
    else 
        return m;
}