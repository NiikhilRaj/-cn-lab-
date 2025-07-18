#include <stdio.h>
#include <string.h>
struct stu{
    int r;
    char n[50];
    char g[10];
    int m[5];
    int t;
};
int main(){
    int n,i,j,su;
    printf("stud: ");
    scanf("%d",&n);
    struct stu s[n];
    for(i=0;i<n;i++){
        printf("roll: ");
        scanf("%d",&s[i].r);
        printf("nam: ");
        scanf("%s",s[i].n);
        printf("gen: ");
        scanf("%s",s[i].g);
        printf("5m: ");
        s[i].t=0;
        for(j=0;j<5;j++){
            scanf("%d",&s[i].m[j]);
            s[i].t+=s[i].m[j];
        }
    }
    printf("\ndata\n");
    for(i=0;i<n;i++){
        printf("r:%d n:%s g:%s t:%d\n",s[i].r,s[i].n,s[i].g,s[i].t);
    }
    printf("sub(1-5): ");
    scanf("%d",&su);
    printf("fail in %d\n",su);
    for(i=0;i<n;i++){
        if(s[i].m[su-1]<40)
            printf("r:%d n:%s\n",s[i].r,s[i].n);
    }
    return 0;
}
