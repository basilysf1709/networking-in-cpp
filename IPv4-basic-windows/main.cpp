#include <iostream>
#ifdef _WIN32
#include <Winsock2.h>
#endif

int main() {
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        std::cerr << "Failed to initialize Winsock" << std::endl;
        return 1;
    }

    SOCKET serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == INVALID_SOCKET) {
        std::cerr << "Failed to create socket" << std::endl;
        WSACleanup();
        return 1;
    }

    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(8080);
    serverAddress.sin_addr.s_addr = INADDR_ANY;

    if (bind(serverSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) == SOCKET_ERROR) {
        std::cerr << "Failed to bind the socket" << std::endl;
        closesocket(serverSocket);
        WSACleanup();
        return 1;
    }

    if (listen(serverSocket, SOMAXCONN) == SOCKET_ERROR) {
        std::cerr << "Failed to listen on the socket" << std::endl;
        closesocket(serverSocket);
        WSACleanup();
        return 1;
    }

    std::cout << "Server is listening for connections..." << std::endl;

    sockaddr_in clientAddress;
    int clientAddrSize = sizeof(clientAddress);
    SOCKET clientSocket = accept(serverSocket, (struct sockaddr*)&clientAddress, &clientAddrSize);

    if (clientSocket == INVALID_SOCKET) {
        std::cerr << "Failed to accept connection" << std::endl;
        closesocket(serverSocket);
        WSACleanup();
        return 1;
    }

    char clientAddrStr[INET_ADDRSTRLEN];
    inet_ntop(AF_INET, &clientAddress.sin_addr, clientAddrStr, INET_ADDRSTRLEN);
    std::cout << "Connection established with client at: " << clientAddrStr << std::endl;

    char buffer[4096];
    int bytesRead = recv(clientSocket, buffer, sizeof(buffer), 0);

    if (bytesRead == SOCKET_ERROR) {
        std::cerr << "Error receiving data" << std::endl;
        closesocket(clientSocket);
        closesocket(serverSocket);
        WSACleanup();
        return 1;
    }

    std::cout << "Received: " << buffer << std::endl;

    const char* response = "Hello from server!";
    int bytesSent = send(clientSocket, response, strlen(response), 0);

    if (bytesSent == SOCKET_ERROR) {
        std::cerr << "Error sending data" << std::endl;
    }

    closesocket(clientSocket);
    closesocket(serverSocket);
    WSACleanup();

    return 0;
}
