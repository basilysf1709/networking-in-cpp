#ifndef __TCPServerController__
#define __TCPServerController__

#include <cstdint>
#include <iostream>
#include <string>

using namespace std;
class TCPNewConnectionAcceptor;
class TCPClientDbManager;
class TCPClientServiceManager;

class TCPServerController {
  private:
    TCPNewConnectionAcceptor* tcp_new_connection_acceptor;
    TCPClientDbManager* tcp_client_db_manager;
    TCPClientServiceManager* tcp_client_service_manager;
    
  public:
    uint32_t ip_address;
    uint16_t port_number;
    string name;
    TCPServerController(string ip_address, uint16_t port_number, string name);
    ~TCPServerController();
    void Start();
    void Stop();
};

#endif