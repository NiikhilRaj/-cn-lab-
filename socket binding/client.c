#include<stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main()
{
    int cid, cbs;
    struct sockaddr_in cadd;
    cid = socket(AF_INET, SOCK_DGRAM, 0);
    if(cid==-1)
    {
        printf("\n No socket for server application is not created successfully.");
        exit(0);
    }
    printf("\n A Socket for server application is created sussessflly.");
    cadd.sin_family=AF_INET;
    cadd.sin_port=htons(1026);
    cadd.sin_addr.s_addr=htonl(INADDR_ANY);
    memset(&(cadd.sin_zero), '\0', 8);
    cbs=bind(cid, (struct sockaddr *) &cadd, sizeof(cadd));
    if (cbs==-1)
    {
        printf("\nBinding Failure - Client Side");
        exit(0);
    }
    printf("\nBinding Successful - Client Side");
    close(cid);
    return 0;
}