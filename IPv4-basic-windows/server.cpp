#include <iostream>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>


/* Here's an explanation of each part:

sockaddr_in is a structure that holds information about the address and port to which the socket will be bound.

serverAddr.sin_family = AF_INET; sets the address family to IPv4.

serverAddr.sin_port = htons(8080); specifies the port number (8080 in this case) to which the socket will be bound. htons function is used to convert the port number to network byte order (big-endian) as required by the network stack.

serverAddr.sin_addr.s_addr = INADDR_ANY; sets the IP address to INADDR_ANY, which means the socket will be bound to all available network interfaces on the local machine. This allows the server to accept connections on any of the machine's IP addresses.

The bind function is used to associate the serverSocket with the address and port specified in the serverAddr structure. If the binding is successful, bind returns 0. If there's an error, it returns -1.

If bind returns an error (-1), the code prints an error message and closes the server socket.

Binding the socket in this way ensures that the server is listening for incoming connections on the specified IP address and port. Clients can then connect to this address and port to establish a network connection with the server.

In summary, binding a socket is a necessary step in setting up a server to listen for incoming network connections. It specifies the local address and port that the server will use for communication.*/

int main() {
    // Create socket
    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == -1) {
        std::cerr << "Error creating socket\n";
        return -1;
    }

    // Bind socket
    sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(8080); // Use any available port
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    if (bind(serverSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) == -1) {
        std::cerr << "Error binding socket\n";
        close(serverSocket);
        return -1;
    }

    // Listen for incoming connections
    if (listen(serverSocket, 5) == -1) {
        std::cerr << "Error listening for connections\n";
        close(serverSocket);
        return -1;
    }

    std::cout << "Server is listening for connections...\n";

    // Accept incoming connection
    sockaddr_in clientAddr;
    unsigned int clientAddrSize = sizeof(clientAddr);
    int clientSocket = accept(serverSocket, (struct sockaddr*)&clientAddr, (unsigned int*)&clientAddrSize);
    if (clientSocket == -1) {
        std::cerr << "Error accepting connection\n";
        close(serverSocket);
        return -1;
    }

    char buffer[1024] = {0};
    read(clientSocket, buffer, sizeof(buffer));
    std::cout << "Received message from client: " << buffer << std::endl;

    close(clientSocket);
    close(serverSocket);

    return 0;
}
