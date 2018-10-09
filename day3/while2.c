#include <stdio.h>

int main(void){

	int i=0,j=0;

	while(j==0){
		printf("1. Korea\n2. USA\n3. Japan\n4. China\n");

		printf("number? ");
		puts("");
		scanf("%d",&i);

		if(i==1){
			printf("Seoul\n");
		}else if(i==2){
			printf("Washington\n");
		}else if(i==3){
			printf("Tokyo\n");
		}else if(i==4){
			printf("Beijing\n");
		}else{
			printf("none\n");
			j=1;
		}
		printf("\n");
	}
}

