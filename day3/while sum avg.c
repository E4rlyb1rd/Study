#include <stdio.h>

int main(void){

	int i=1,j=0,k=0;
	
	while(i<=100 && i>=0){
	
	scanf("%d",&i);
		if((i<=100 && i>=0)){
			k=k+i;
			j++;

		}
	}
	printf("sum : %d\n",k);
	printf("avg : %1.1f\n",(float)k/j);
	return 0;
}