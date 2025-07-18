#include <stdio.h>
int swp(int *a,int *b){
    int t=*a;
    *a=*b;
    *b=t;
    return 0;
}
int main(int c,char *v[]){
    if(c!=3){
        printf("use: %s n1 n2\n",v[0]);
        return 1;
    }
    int x=atoi(v[1]);
    int y=atoi(v[2]);
    swp(&x,&y);
    printf("x=%d y=%d\n",x,y);
    return 0;
}
