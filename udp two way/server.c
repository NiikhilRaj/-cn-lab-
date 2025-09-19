#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
int main()
{
    int sid, sbs, sbyte;
    char sstr[100];
    struct sockaddr_in sadd, sender;
    socklen_t addsize;
    sid = socket(AF_INET, SOCK_DGRAM, 0);
    if(sid==-1)
    {
        printf("\n No socket for server application is not created successfully.");
        exit(0);
    }
    printf("\n A Socket for server application is created sussessflly.");
    sadd.sin_family=AF_INET;
    sadd.sin_port=htons(1025);
    sadd.sin_addr.s_addr=htonl(INADDR_ANY);
    memset(&(sadd.sin_zero), '\0', 8);
    sbs=bind(sid, (struct sockaddr *) &sadd, sizeof(sadd));
    if (sbs==-1)
    {
        printf("\nBinding Failure - Server Side");
        exit(0);
    }
    printf("\nBinding Failure Server Side");
    addsize = sizeof(sender);
    sbyte=recvfrom(sid, sstr, 100, 0, (struct sockaddr *) &sender, &addsize);
    if (sbyte==-1)
    {
        printf("\n In Server Side No message received");
        exit(0);
    }
    sstr[sbyte] = '\0';
    printf("\nServer received: %s", sstr);
    printf("\n%d bytes received", sbyte);
    printf("\nServer wants to send: ");
    scanf("%s", sstr);
    sbyte=sendto(sid, sstr, sizeof(cstr), 0, (struct sockaddr *) &sender, sizeof(sender));
    if (scbyte==-1)
    {
        printf("\nFrom Server Side No message sent");
        exit(0);
    }
    sstr[sbyte] = '\0';
    printf("\nServer sent: %s", sstr);
    printf("\n%d bytes sent", sbyte);
    close(sid);
    return 0;
}