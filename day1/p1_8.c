#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct emp{
    char n[50];
    char g[10];
    char d[30];
    char dep[30];
    float b;
    float gr;
};
int main(){
    int n,i;
    printf("emp: ");
    scanf("%d",&n);
    struct emp *e=(struct emp*)malloc(n*sizeof(struct emp));
    for(i=0;i<n;i++){
        printf("nam: ");
        scanf("%s",e[i].n);
        printf("gen: ");
        scanf("%s",e[i].g);
        printf("des: ");
        scanf("%s",e[i].d);
        printf("dep: ");
        scanf("%s",e[i].dep);
        printf("pay: ");
        scanf("%f",&e[i].b);
        float h=0.25*e[i].b;
        float da=0.75*e[i].b;
        e[i].gr=e[i].b+h+da;
    }
    printf("\ndata\n");
    for(i=0;i<n;i++){
        printf("n:%s g:%s d:%s dep:%s gr:%.2f\n",e[i].n,e[i].g,e[i].d,e[i].dep,e[i].gr);
    }
    free(e);
    return 0;
}
