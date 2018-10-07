#include <stdio.h>
#include <time.h>

int main(void){
//현제 시간 코딩

	char* yoil[]={"일","월","화","수","목","금","토"};

	time_t now =time(NULL);
	struct tm* lt =localtime(&now);

	
	printf("%4d년 %2d월 %2d일 %s요일\n",lt->tm_year+1900,
				lt->tm_mon+1,lt->tm_mday,yoil[lt->tm_wday]);
	printf("%4d시 %2d분 %2d초\n",lt->tm_hour,lt->tm_min,lt->sec);

	return 0;
}

