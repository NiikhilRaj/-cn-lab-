#include <stdio.h>
int main(){
    unsigned int n;
    char a,b,c,d;
    printf("num: ");
    scanf("%u",&n);
    a=n&0xFF;
    b=(n>>8)&0xFF;
    c=(n>>16)&0xFF;
    d=(n>>24)&0xFF;
    printf("%d %d %d %d\n",a,b,c,d);
    return 0;
}
