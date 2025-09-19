#include<stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main()
{
    int cid;
    cid = socket(AF_INET, SOCK_DGRAM, 0);
    if(cid=-1)
    {
        printf("\n No socket for client application is created successfully.");
        exit(0);
    }
    printf("\n A Socket for client application is created sussessflly.");
    close(cid);
    return 0;
}