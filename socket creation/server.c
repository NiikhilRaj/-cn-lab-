#include<stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main()
{
    int sid;
    sid = socket(AF_INET, SOCK_DGRAM, 0);
    if(sid=-1)
    {
        printf("\n No socket for server application is created successfully.");
        exit(0);
    }
    printf("\n A Socket for server application is created sussessflly.");
    close(sid);
    return 0;
}