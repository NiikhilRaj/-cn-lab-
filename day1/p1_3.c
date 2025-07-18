#include <stdio.h>
int matchany(char a[],char b[]){
    int i=0,j=0,k=0;
    while(a[i]&&b[i]){
        if(a[i]!=b[i]) break;
        i++;
    }
    if(a[i]==0&&b[i]==0) return 0;
    i=0;
    while(a[i]!=0){
        j=i;k=0;
        while(a[j]==b[k]&&b[k]!=0){j++;k++;}
        if(b[k]==0) return 1;
        i++;
    }
    return -1;
}
int main(){
    char x[100],y[100];
    printf("str1: ");
    gets(x);
    printf("str2: ");
    gets(y);
    int r=matchany(x,y);
    if(r==1) printf("sub\n");
    else if(r==0) printf("eq\n");
    else printf("no\n");
    return 0;
}
