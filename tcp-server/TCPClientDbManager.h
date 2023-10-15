#ifndef __TCPClientDbManager__
#define __TCPClientDbManager__

#include <cstdint>
#include <iostream>
#include <string>
#include <list>


using namespace std;

class TCPServerController;
class TCPClient;

class TCPClientDbManager {
  private:
    list<TCPClient *> tcp_client_db;

  public:
    TCPServerController *tcp_controller;
    TCPClientDbManager(TCPServerController *);
    ~TCPClientDbManager();
};

#endif