#include <stdio.h>

int sum(int num);

void main(){
	int n;
	int result =0;

	scanf("%d",&n);

	result = sum(n);

	printf("%d",result);

}
int sum(int num){

	if(num==1)
		return 1;

	else
		return num + sum(num-1)
	
}