#include <stdio.h>
#include <stdlib.h>
int main(){
    int n,i,*p,big;
    printf("n: ");
    scanf("%d",&n);
    p=(int*)malloc(n*sizeof(int));
    if(p==0){
        printf("no mem\n");
        return 1;
    }
    printf("val: ");
    for(i=0;i<n;i++)
        scanf("%d",&p[i]);
    big=p[0];
    for(i=1;i<n;i++){
        if(p[i]>big) big=p[i];
    }
    printf("big is %d\n",big);
    free(p);
    return 0;
}
