#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define SERVER_IP "127.0.0.1" 
#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
    int sock_fd;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE] = {0};
    const char *message = "Aloo parathe";

    sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }
    printf(" Client Socket created successfully.\n");

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);

    if (inet_pton(AF_INET, SERVER_IP, &server_addr.sin_addr) <= 0) {
        perror("Invalid address/ Address not supported");
        close(sock_fd);
        exit(EXIT_FAILURE);
    }
    
    if (connect(sock_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("Connection failed");
        close(sock_fd);
        exit(EXIT_FAILURE);
    }
    printf("Connected to the server.\n");

    if (send(sock_fd, message, strlen(message), 0) == -1) {
        perror("Send failed");
        close(sock_fd);
        exit(EXIT_FAILURE);
    }
    printf("Message sent to server: %s\n", message);


    ssize_t bytes_received = recv(sock_fd, buffer, BUFFER_SIZE, 0);
    if (bytes_received == -1) {
        perror("Receive failed");
    } else if (bytes_received == 0) {
        printf("Server closed the connection.\n");
    } else {
        printf("Server echoed: %s\n", buffer);
    }

    close(sock_fd);
    printf("Socket closed. Client shutting down.\n");

    return 0;
}