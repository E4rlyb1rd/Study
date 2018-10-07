#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void read_input(char *buf,size_t size){ // read_input void형 함수, 인자로 buf 포인터와, size를 받는다.
	int ret ; // int형 ret 라는 변수를 선언함
    ret = read(0,buf,size); // read함수로 0번 fd에 인자로 전달된 buf에 인자로 전달된 size만큼 입력받고, 그 리턴값을 ret변수에 넣음 
    if(ret <=0){ // ret 라는 변수가 0보다 작거나 같을떄
        puts("Error"); //문자열 Error 화면에 출력
        _exit(-1); //프로그램 비정상 종료 
    }	
}

struct heap {  //heap라는 구조체 
	size_t size ;  //양수인 size 변수;
	char *content ; // 문자형 포인터 변수 content
};

struct heap *heaparray[10]; //구조체 배열 크기가 10인 포인터 

void menu(){ //void (return값없는) menu 함수  
	puts("--------------------------------"); //----------
	puts("          Heap Creator          "); //heap creator 
	puts("--------------------------------"); //-------
	puts(" 1. Create a Heap               "); //출력 
	puts(" 2. Edit a Heap                 ");
	puts(" 3. Show a Heap                 ");
	puts(" 4. Delete a Heap               ");
	puts(" 5. Exit                        ");
	puts("--------------------------------");
	printf("Your choice :"); //your choice : 화면에출력
}

void create_heap(){  //void형 create_heap함수  
	int i ;    //정수형  변수 i;
	char buf[8]; //문자형 buf크기가 8인 배열 ;
	size_t size = 0; // size 0으로 초기화 
	for(i = 0 ; i < 10 ; i++){ //변수 i 0에서부터 9까지 올라가는 반복문 
		if(!heaparray[i]){ //heaparray[i]가 없을때
			heaparray[i] = (struct heap *)malloc(sizeof(struct heap));//구조체 heap*에 (struct heap)크기만큼 메모미할당 그후에 heaparray[i]저장
			if(!heaparray[i]){ //heaparray[i]가 없을떼 
				puts("Allocate Error"); //allocate error 출력 
				exit(1);//에러시 강제종료 
			}
			printf("Size of Heap : "); //출력
			read(0,buf,8); //read함수로 0번 fd에 인자로 buf에 인자로 전달된 8만큼 입력
			size = atoi(buf); //atoi(buf) size에 저장?
			heaparray[i]->content = (char *)malloc(size); //char *에 size의 크기만큼 메모리할당 그후에 heaparray[i]->content에 저자ㅇh
			if(!heaparray[i]->content){//heaparray[i]가 content를 가르키지않을떄?
				puts("Allocate Error");//출력 //
				exit(2);//2리턴하면서 종료 
			}
			heaparray[i]->size = size ; //heaparray[i]가 가르키는 size = size?
			printf("Content of heap:");//content of heap출력 
			read_input(heaparray[i]->content,size);
			puts("SuccessFul");//출력 
			break ; //멈춤 
		}
	}
}

void edit_heap(){
	int idx ; //정수형 변수idx
	char buf[4]; //  크기가 4인 buf 문자형 배열  
	printf("Index :");//출력
	read(0,buf,4); //read함수로 0번 fd에 인자로 buf에 인자로 전달된 4만큼 입력
	idx = atoi(buf); //atoi(buf) idx에 저장
	if(idx < 0 || idx >= 10){ //idx가 0q보다 작을떄 또는 10보다 크거나 같을떄 
		puts("Out of bound!"); //out of bound 출력 
		_exit(0); //종료
	}
	if(heaparray[idx]){ //heaparray[idx]있을떄
		printf("Content of heap : "); //content of heap:출력 
		read_input(heaparray[idx]->content,heaparray[idx]->size+1);
		puts("Done !"); //출력 done
	}else{ //이외 
		puts("No such heap !"); //출력 
	}
}

void show_heap(){
	int idx ;//''
	char buf[4];//''
	printf("Index :");//''
	read(0,buf,4);//함수로 0번 fd에 인자로 buf에 인자로 전달된 4만큼 입력
	idx = atoi(buf);
	if(idx < 0 || idx >= 10){ //idx가 0보다 작을 때 또는 idx가 10보다 같거나 작을때
		puts("Out of bound!"); //out of bound 출력
		_exit(0); //정상종료 
	}
	if(heaparray[idx]){ //jeaparray[idx]있을떄 
		printf("Size : %ld\nContent : %s\n",heaparray[idx]->size,heaparray[idx]->content);//heaparray[idx]->size,heaparray[idx]->content 화면에 출력 
		puts("Done !"); //done화면에 출력
	}else{ //이외 //no such heap 출력
		puts("No such heap !");
	}

}

void delete_heap(){
	int idx ; //정수형 idx변수
	char buf[4]; //크기가 4인 문자형 buf배열 
	printf("Index :"); //출력 index;
	read(0,buf,4);//read함수로 0번 fd에 인자로 전달된 buf에 인자로 전달된 4만큼 입력한다.
	idx = atoi(buf); //
	if(idx < 0 || idx >= 10){ //idx 0보다 작을때 , idx 가 10보다 작거나 같을때
		puts("Out of bound!");//출력 out of bound
		_exit(0); //정상 종료 
	}
	if(heaparray[idx]){ //heaparray[idx]가 있을때
		free(heaparray[idx]->content);// content를 가르키는 heaparray[idx] 메모리해제
		free(heaparray[idx]); //heaparray[idx]메모리 해제.
		heaparray[idx] = NULL ; //heaparray[idx]에 null저장;
		puts("Done !");	//done출력 
	}else{ //이외의 다른것들 
		puts("No such heap !");//화면에 no such heap! 출력
	}

}


int main(){
	char buf[4]; // 문자형 buf 배열크기 4
	setvbuf(stdout,0,2,0); //버퍼링 제어
	setvbuf(stdin,0,2,0);  
	while(1){ //참(1)일때 반복되는 반복문 while
		menu(); //함수 menu 출력;
		read(0,buf,4); //read로 0번 fd에 인자로 전달된 buf에 인자로 전달된 4만큼 입력.
		switch(atoi(buf)){
			case 1 : //1번을 누를떄 
				create_heap(); //create_heap() 출력;
				break ; //멈춤
			case 2 : //2 번 누를떄
				edit_heap();//edit_heap란 함수 출력;
				break ;//멈춤 
			case 3 :  //3 ""	
				show_heap(); //show_heap 함수 출력
				break ;
			case 4 :
				delete_heap(); //delete_heap함수 출력
				break ;
			case 5 :
				exit(0);    //정상종료
				break ;
			default :   //이외 다른 것들
				puts("Invalid Choice"); //invalid choice 화면에 출력 
				break;
		}

	}
	return 0 ; //에러 없을 때 정상종료

}




