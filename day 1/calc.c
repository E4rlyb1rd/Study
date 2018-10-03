#include <stdio.h>

int main() {
    int a,b = 0;

    printf("Plz input the value\n");
    scanf("%d %d",&a,&b);

    printf("%d+%d=%d\n",a,b,a+b);
    printf("%d-%d=%d\n",a,b,a-b);
    printf("%d*%d=%d\n",a,b,a*b);
    printf("%d/%d=%d\n",a,b,a/b);

    return 0;
}