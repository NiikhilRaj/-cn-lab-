#include <stdio.h>
#include <string.h>
int cntwrd(char *a,char *b){
    int c=0,i=0,j,l;
    l=strlen(b);
    while(a[i]){
        for(j=0;j<l&&a[i+j]==b[j];j++);
        if(j==l&&(a[i+j]==' '||a[i+j]==0)) c++;
        while(a[i]&&a[i]!=' ') i++;
        while(a[i]==' ') i++;
    }
    return c;
}
int main(){
    char s[200],w[50];
    printf("sent: ");
    gets(s);
    printf("wrd: ");
    gets(w);
    printf("%s %d\n",w,cntwrd(s,w));
    return 0;
}
