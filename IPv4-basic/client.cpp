#include <iostream>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

int main() {
    /* This line creates a socket. AF_INET specifies that this is an IPv4 socket, 
        and SOCK_STREAM indicates that this socket will be used for TCP/IP communication. */
    int clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket == -1) {
        std::cerr << "Error creating socket" << std::endl;
        return -1;
    }

    // Setting up Server Address
    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(12345); // Port number
    inet_pton(AF_INET, "127.0.0.1", &serverAddress.sin_addr); // IP address of the server

    // Connecting the socket
    if (connect(clientSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) == -1) {
        std::cerr << "Error connecting to server" << std::endl;
        return -1;
    }

    // Sending Data to Server
    const char* message = "Hello, server!";
    send(clientSocket, message, strlen(message), 0);

    close(clientSocket);

    return 0;
}
