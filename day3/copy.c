#include <stdio.h>

struct point(int x,int y);
struct circle{
    struct point* p;
    int r;

};

int main(void){
    struct point p ={1,2};
    struct circle c1={&p,3};
    struct circle c2,c3;

    c2=c1;

    c3=c1;
   
    c3.p=(struct point*)malloc(sizeof(struct point));
   
    *c3.p=*c1.p;

    printf
}