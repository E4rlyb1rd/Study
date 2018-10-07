#include <stdio.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

char *memo[10];


void printDate(){

	char* yoil[]={"일","월","화","수","목","금","토"};

	time_t now =time(NULL);
	struct tm* lt =localtime(&now);

	printf("%4d년 %2d월 %2d일 %s요일\n",lt->tm_year+1900,
				lt->tm_mon+1,lt->tm_mday,yoil[lt->tm_wday]);
	printf("%4d시 %2d분 %2d초\n",
				lt->tm_hour,lt->tm_min,lt->tm_sec);
	
}


int memo_func() {

	int i;
	int idx;
	unsigned int size;

	printf("1. Select memo page: ");
	scanf("%d",&idx);

	if(memo[idx]) { 
		printf("already has memo\n");
		return 0;
	}

	 
	printf("2. Memo size: ");
	scanf("%d",&size);

	if(size < 0 || size > 128) {
		printf("Nope\n");
		return 0;
	}



	memo[idx] = malloc(size);

	read(0, memo[idx], size-1);

	// scanf("%60s",memo[idx]);

	//read(fd, buf, size);
	// fd = file descriptor, buf <- size
	printf("Memo: %s",memo[idx]);

	free(memo[idx]);
	memo[idx] = 0; 

}

int main(void){
	int num =0;
	
	while(1){
	printf("1.현제 날짜와 시간\n");
	printf("2.memo\n");
	printf("3.exit\n");
	
	scanf("%d",&num);

	if(num ==1)
		printDate();
	
	if(num ==2)
		memo_func();
	
	if(num ==3)
		break;

	}
	return 0;
}



