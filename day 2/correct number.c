#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand((int)time(NULL));
    sangkwon:
   
    int ran;

    int have[6];

    while(1){
        for(int i=0;i<6;i++){
            have[i] =rand() % 10;
        }
     
        if(que[0] ! =0) 
            break;
    }

    int shift[6];

    for(int i=0;i<6;i++){
        shift[i] = rand() 6;

    }

    int prob[6];

    for(int index = 0; index < 6; index++){    
    }

    for(int index =0; index <3;index++){
        //rand number
        int a =shift[index],b=shift[5-index];

        ran= have[a];
        have[a]=have[b];
        have[b]=ran;
    }
    
    printf("correct number game.\n");

    int a,b,esc;

    while(1){
        int ans =0;
        
        for(int i=0;i<6;i++){
            printf("%d",prob[i]);

        }
        printf("    make it like\n\n");
        
        for(int i=0;i<6;i++){
            printf("%d",have[i]); 

        }
        printf("write down two numbers to move from your number now)\n\n");

        scanf_s("%d%d",&a,&b);
        ran = have[a-1];

        have[a-1]=have[b-1];
        have[b-1]=ran;
        for(int index =0;index<6;index++){
            if(have[index]==prov[index]){
                ans++; //맞은 숫자 개수
            }
        }
        if(ans==6)
            break;

    }
    printf("wow! make it  return 1, exit 0 \n\n");
    scanf_s("%d",&exit);
    
    if(exit ==1)
    {
        goto sangkwon;
    }

}