#include <stdio.h>
#include <string.h>
struct d{
    int d,m,y;
};
struct s{
    int r;
    char n[50];
    float c;
    struct d a;
};
void pv(struct s x){
    printf("v: %d %s %.2f %d-%d-%d\n",x.r,x.n,x.c,x.a.d,x.a.m,x.a.y);
}
void pa(struct s *x){
    printf("a: %d %s %.2f %d-%d-%d\n",x->r,x->n,x->c,x->a.d,x->a.m,x->a.y);
}
int main(){
    struct s x;
    printf("roll: ");
    scanf("%d",&x.r);
    printf("nam: ");
    scanf("%s",x.n);
    printf("cg: ");
    scanf("%f",&x.c);
    printf("dob: ");
    scanf("%d%d%d",&x.a.d,&x.a.m,&x.a.y);
    pv(x);
    pa(&x);
    return 0;
}
