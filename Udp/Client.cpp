#include "Client.hpp"
#include <iostream>

int main(int argc,char* argv[])
{
  if(argc != 3)
  {
    std::cout << "Usage./clinet[ip] [port]" << std::endl;
    return 1;
  }
  Client myclient(argv[1],atoi(argv[2]));
  for(;;)
  {
    std::string buf;
    std::cin >> buf;
    if(buf)
    {
      myclient.Send(buf);
      std::cout << buf << std::endl;
      std::string message; 
      myclient.Recv(&message);
      std::cout << "Server recv#" << message << std::endl;
    }
  }
  return 0;
}
