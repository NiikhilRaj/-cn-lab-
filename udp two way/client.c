#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main()
{
    int cid, cbs, cbyte;
    char cstr[100];
    struct sockaddr_in cadd, receiver;
    socklen_t addsize;
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
    receiver.sin_family=AF_INET;
    receiver.sin_port=htons(1025);
    receiver.sin_addr.s_addr=htonl(INADDR_ANY);
    memset(&(receiver.sin_zero), '\0', 8);
    printf("\nEnter a message:");
    fgets(cstr, 100, stdin);
    cstr[strcspn(cstr, "\n")] = 0;
    cbyte=sendto(cid, cstr, strlen(cstr), 0, (struct sockaddr *) &receiver, sizeof(receiver));
    if (cbyte==-1)
    {
        printf("\nFrom Client Side - No message sent");
        exit(0);
    }
    cstr[cbyte] = '\0';
    printf("\nClient sent: %s", cstr);
    printf("\n%d bytes sent", cbyte);
    addsize = sizeof(receiver);
    cbyte=recvfrom(cid, cstr, 100, 0, (struct sockaddr *) &receiver, &addsize);
    if (cbyte==-1)
    {
        printf("\n In Client Side No message received");
        exit(0);
    }
    cstr[cbyte] = '\0';
    printf("\nClient received: %s", cstr);
    printf("\n%d bytes received", cbyte);
    close(cid);
    return 0;
}