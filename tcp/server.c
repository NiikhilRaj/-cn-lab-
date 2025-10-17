// server.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
    int server_fd, new_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);
    char buffer[BUFFER_SIZE] = {0};

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }
    printf("✅ Server Socket created successfully.\n");

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY; 
    server_addr.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("Bind failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }
    printf("Bind successful to port %d.\n", PORT);

    if (listen(server_fd, 5) == -1) {
        perror("Listen failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }
    printf("Server listening for connections...\n");

  
    new_socket = accept(server_fd, (struct sockaddr *)&client_addr, &addr_len);
    if (new_socket == -1) {
        perror("Accept failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }
    printf("Connection accepted from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));


    ssize_t bytes_received = recv(new_socket, buffer, BUFFER_SIZE, 0); 
    if (bytes_received == -1) {
        perror("Receive failed");
    } else if (bytes_received == 0) {
        printf("Client closed the connection.\n"); 
    } else {
        printf("Client says: %s\n", buffer);

        if (send(new_socket, buffer, bytes_received, 0) == -1) {
            perror("Send failed");
        } else {
            printf("Echo sent back to client.\n");
        }
    }

    close(new_socket);
    close(server_fd);
    printf("Sockets closed. Server shutting down.\n");

    return 0;
}