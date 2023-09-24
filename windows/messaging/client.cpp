#include <iostream>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

int main() {
    // Create socket
    int clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket == -1) {
        std::cerr << "Error creating socket\n";
        return -1;
    }

    sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(8080); // Use the same port as the server
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1"); // Use inet_addr directly

    // Connect to server
    if (connect(clientSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) == -1) {
        std::cerr << "Error connecting to server\n";
        close(clientSocket);
        return -1;
    }

    char message[1024] = {0};
    bool flag = true;
    while (flag) {
        std::cout << "Enter a message: ";
        std::cin.getline(message, sizeof(message));

        if (strcmp(message, "End") == 0 || strcmp(message, "Stop") == 0) {
          flag = false;
        }

        send(clientSocket, message, strlen(message), 0);

        char buffer[1024] = {0};
        int valread = read(clientSocket, buffer, sizeof(buffer));
        if (valread <= 0)
            break;

        std::cout << "Server response: " << buffer << std::endl;
    }

    close(clientSocket);

    return 0;
}
