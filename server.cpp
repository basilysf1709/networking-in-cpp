#include <iostream>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

int main() {
    /* This line creates a socket. AF_INET specifies that this is an IPv4 socket, 
        and SOCK_STREAM indicates that this socket will be used for TCP/IP communication. */
    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    
    if (serverSocket == -1) {
        std::cerr << "Error creating socket" << std::endl;
        return -1;
    }

    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(12345); // Port number
    serverAddress.sin_addr.s_addr = INADDR_ANY; // Listen on all available interfaces

    if (bind(serverSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) == -1) {
        std::cerr << "Error binding socket" << std::endl;
        return -1;
    }

    if (listen(serverSocket, 5) == -1) {
        std::cerr << "Error listening on socket" << std::endl;
        return -1;
    }

    std::cout << "Server is listening for connections..." << std::endl;

    sockaddr_in clientAddress;
    socklen_t clientAddrSize = sizeof(clientAddress);

    int clientSocket = accept(serverSocket, (struct sockaddr*)&clientAddress, &clientAddrSize);
    if (clientSocket == -1) {
        std::cerr << "Error accepting connection" << std::endl;
        return -1;
    }

    char buffer[1024] = {0};
    recv(clientSocket, buffer, sizeof(buffer), 0);
    std::cout << "Received: " << buffer << std::endl;

    close(clientSocket);
    close(serverSocket);

    return 0;
}
