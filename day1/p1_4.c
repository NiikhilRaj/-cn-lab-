#include <stdio.h>
void swp(int *x,int *y,int *z){
    int t;
    t=*x;
    *x=*z;
    *z=*y;
    *y=t;
}
int main(){
    int a,b,c;
    printf("3 num: ");
    scanf("%d%d%d",&a,&b,&c);
    swp(&a,&b,&c);
    printf("a=%d b=%d c=%d\n",a,b,c);
    return 0;
}
