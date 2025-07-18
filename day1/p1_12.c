#include <stdio.h>
struct p{
    char a;
    char b[2];
    char c;
};
int main(){
    int n;
    struct p x;
    printf("4num: ");
    scanf("%d",&n);
    x.a=(n/1000)%10+'0';
    x.b[0]=(n/100)%10+'0';
    x.b[1]=(n/10)%10+'0';
    x.c=n%10+'0';
    printf("a:%c b0:%c b1:%c c:%c\n",x.a,x.b[0],x.b[1],x.c);
    int r=(x.a-'0')*1000+(x.b[0]-'0')*100+(x.b[1]-'0')*10+(x.c-'0');
    printf("r:%d\n",r);
    return 0;
}
