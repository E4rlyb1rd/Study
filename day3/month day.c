#include <stdio.h>

int main(void){

	int i=0;

	scanf("%d",&i);

	if(i ==2){
		printf("28");
	}
	else if((i==1)||(i==3)||(i==5)||(i==7)||(i==8)||(i==10)||(i==12)){
		printf("31");
	}else{
		printf("30");
	}

}
