#include <iostream>
#include <boost/asio.hpp>

using namespace boost::asio;


// set it up on wsl
int main() {
    io_service io;
    ip::tcp::acceptor acceptor(io, ip::tcp::endpoint(ip::tcp::v4(), 12345));

    while (true) {
        ip::tcp::socket socket(io);
        acceptor.accept(socket);

        std::string message = "Hello, client!";
        boost::system::error_code error;
        write(socket, buffer(message), error);

        if (!error) {
            char data[1024];
            size_t length = socket.read_some(buffer(data), error);
            if (!error)
                write(socket, buffer(data, length), error);
        }
    }

    return 0;
}
