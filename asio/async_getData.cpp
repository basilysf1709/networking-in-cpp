// Asynchronous programming
// A C++ program that gets data from an IP Address by creating a TCP connection and asynchronously reading it

#include <iostream>
#include <thread>

#include <boost/asio.hpp>
#include <boost/asio/ts/buffer.hpp>
#include <boost/asio/ts/internet.hpp>
#include <boost/system/error_code.hpp>

using namespace boost;
using namespace boost::asio;
using namespace std;

vector<char> vBuffer( 1 * 1024);


// Read data in Real Time
// Every time you receive data, it prints in the terminal in real time
void getData(asio::ip::tcp::socket &socket) {
   socket.async_read_some(asio::buffer(vBuffer.data(), vBuffer.size()),
      [&](boost::system::error_code ec, size_t length) {
         if(!ec) {
            cout << "\n\nRead: " << length << " bytes\n\n";

            for (int i = 0; i < length; i++) {
               cout << vBuffer[i];
            }
            getData(socket);
         }
      }
   );
}

int main() {
   boost::system::error_code ec;

   // Create the context - space where asio can do its work
   asio::io_context context;

   // Start the context as its own thread
   thread thrContext = thread([&]() {
      context.run(); 
   });

   // Give some fake tasks to asio so the context doesn't finish
   asio::io_context::work idleWork(context);

   // example connection!
   asio::ip::tcp::endpoint endpoint(ip::make_address("93.184.216.34", ec), 80);
   asio::ip::tcp::socket socket(context);
   socket.connect(endpoint, ec);

   if (!ec) {
      cout<< "Connected!!" <<endl;
   } else {
      cout << "Failed to connect to address!\nError: " << ec.message() <<endl;
   }
   

   // Check if the socket is open
   if (socket.is_open()) {

      getData(socket);

      string request = 
         "GET /index.html HTTP/1.1\r\n"
         "Host: example.com\r\n"
         "Connection: close\r\n\r\n";
      
      // Write something to the server
      socket.write_some(asio::buffer(request.data(), request.size()), ec);

      getData(socket);

      using namespace std::chrono_literals;
      this_thread::sleep_for(2000ms);

      context.stop();
      if (thrContext.joinable()) thrContext.join();
     
   }

   cin.get();
   return 0;
}


