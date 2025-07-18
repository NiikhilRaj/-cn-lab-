#include <stdio.h>
int fibcheck(int x){
    int a=0,b=1,c=0;
    if(x==0) return 1;
    if(x==1) return 1;
    while(b<x){
        c=a+b;
        a=b;
        b=c;
    }
    if(b==x) return 1;
    return 0;
}
int main(){
    int n;
    printf("num: ");
    scanf("%d",&n);
    if(fibcheck(n)){
        printf("fib yes\n");
    }else{
        printf("fib no\n");
    }
    return 0;
}
