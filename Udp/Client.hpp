#pragma once 

#include "Socket.hpp"

class Client
{
  public:
    Client(const std::string &ip,uint16_t port):_ip(ip),_port(port)
    {
      assert(_sock.Socket());
    }

    bool Recv(std::string* buf)
    {
      return _sock.Recv(buf);
    }

    bool Send(const std::string& buf)
    {
      return _sock.Send(buf,_ip,_port);
    }


    ~Client()
    {
      _sock.Close();
    }
  private:
   UdpSocket _sock;
    std::string _ip;
    uint16_t _port;

};
