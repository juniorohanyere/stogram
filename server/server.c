#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main() {
    int serverSocket, clientSocket;
    struct sockaddr_in serverAddr, clientAddr;
    socklen_t clientAddrLen = sizeof(clientAddr);

    // Create a socket
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == -1) {
        perror("Socket creation error");
        exit(1);
    }

    // Bind the socket to a specific port
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(12345); // Replace with your desired port
    serverAddr.sin_addr.s_addr = INADDR_ANY;

    if (bind(serverSocket, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) == -1) {
        perror("Binding error");
        close(serverSocket);
        exit(1);
    }

    // Listen for incoming connections
    if (listen(serverSocket, 5) == -1) {
        perror("Listening error");
        close(serverSocket);
        exit(1);
    }

    // Accept incoming connections
    clientSocket = accept(serverSocket, (struct sockaddr *)&clientAddr, &clientAddrLen);
    if (clientSocket == -1) {
        perror("Accept error");
        close(serverSocket);
        exit(1);
    }

    // Communication logic
    char *message = "Hello from C!";
    send(clientSocket, message, 13, 0);

    clientSocket = accept(serverSocket, (struct sockaddr *)&clientAddr, &clientAddrLen);
    if (clientSocket == -1) {
        perror("Accept error");
        close(serverSocket);
        exit(1);
    }

    message = "/bin/ls";
    send(clientSocket, message, sizeof(message), 0);

    // Close sockets
    close(clientSocket);
    close(serverSocket);

    return 0;
}
