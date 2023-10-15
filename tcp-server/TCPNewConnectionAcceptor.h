#ifndef __TCPNewConnectionAcceptor__
#define __TCPNewConnectionAcceptor__

#include <cstdint>
#include <iostream>
#include <string>

using namespace std;

class TCPServerController;

class TCPNewConnectionAcceptor {
  private:

  public:
    TCPServerController *tcp_controller;
    TCPNewConnectionAcceptor(TCPServerController *);
    ~TCPNewConnectionAcceptor();
  
};

#endif