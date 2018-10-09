#include <stdio.h>

int main(void){

	int a=0;

	printf("Number? ");
	scanf("%d",&a);

	if(a==1){
		printf("dog");
	}else if(a==2){
		printf("cat");

	}else if(a==3){
		printf("chick");
	}else{
		printf("I don't know.");
	}
}