#include <iostream>

#include <boost/asio.hpp>
#include <boost/asio/ts/buffer.hpp>
#include <boost/asio/ts/internet.hpp>
#include <boost/system/error_code.hpp>

using namespace boost::asio;
using namespace std;

int main() {
    boost::system::error_code ec;
    io_context context;
    ip::tcp::endpoint endpoint(ip::make_address("127.0.0.1", ec), 80);
    ip::tcp::socket socket(context);
    socket.connect(endpoint, ec);

    if (!ec) {
       cout<< "Connected!!" <<endl;
    } else {
       cout << "Failed to connect to address!\nError: " << ec.message() <<endl;
    }

    cin.get();
    return 0;
}


