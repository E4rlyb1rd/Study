#include <stdio.h>

int main(void){

int num=0;
int i=0;

scanf("%d",&num);

for(i=1;i<=num;i++){
	if(i%2==0)
		printf("%d ",i);

}
return 0;
}