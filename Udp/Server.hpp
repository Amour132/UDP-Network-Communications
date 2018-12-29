#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string>
#include <cassert>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

typedef struct sockaddr sockaddr;
typedef struct sockaddr_in sockaddr_in;


class Sock
{
  public:
    Sock()
    {}
    SockInit()
    {
    
    }
    Recv();
    Send();
    ~Sock();
  private:
    Sock _sock;
};

