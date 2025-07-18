#include <stdio.h>

int evenadd(int x){
    int s=0;
    int d;
    if(x<0){
        x=-x;
    }
    while(x>0){
        d=x%10;
        if(d%2==0){
            s=s+d;
        }
        x=x/10;
    }
    return s;
}

int main(){
    int a;
    printf("give num: ");
    scanf("%d",&a);
    printf("sum even dig is %d\n",evenadd(a));
    return 0;
}