#pragma once

#include "Socket.hpp"
#include <functional> 

typedef std::function<void (const std::string&,std::string* resp)> Handler;

class Server
{
  public:
    Server()
    {
      assert(_sock.Socket());
    }

    bool Start(const std::string& ip,uint16_t port,Handler handler)
    {
      bool ret = _sock.Bind(ip,port);
      if(!ret){
        return false;
      }
      for(;;)
      {
        std::string req;
        std::string remote_ip;
        uint16_t remote_port = 0;
        bool ret = _sock.Recv(&req,&remote_ip,&remote_port);
        if(!ret){
           continue;
        }
        std::string resp;
        handle(req,&resp);
        _sock.Send(resp,remote_ip,remote_port);
      }
      _sock.Close();
      return true;
    }
  private:
    UdpSocket _sock;
};
