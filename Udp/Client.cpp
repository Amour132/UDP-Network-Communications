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
    std::string word;
    std::cout << "请输入要查询得单词" << std::endl;
    std::cin >> word;
    if(word.size() != 0)
    {
      myclient.Send(word);
      std::string message; 
      myclient.Recv(&message);
      std::cout << word << ":" << message << std::endl;
    }
    else 
    {
      break; 
    }
  }
  return 0;
}
