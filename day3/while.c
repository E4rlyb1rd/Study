#include <stdio.h>

int main(void){

	int i=0;
	int j=0;
	int t=0;

	

	while(i<100){
		scanf("%d",&i);
		j++;
		t=t+i;
	}
	printf("%d\n",t);
	printf("%1.1f",(float)t/j);
}
