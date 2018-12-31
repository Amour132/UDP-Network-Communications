#include "Server.hpp"
#include <iostream>
#include <unordered_map>

std::unordered_map<std::string,std::string> _dict;

void Translate(const std::string& req,std::string* resp)
{
  auto it = _dict.find(req);
  if(it == _dict.end())
  {
    *resp = "null";
    return;
  }
  *resp = it->second;
}

int main(int argc,char* argv[])
{
  if(argc != 3)
  {
    std::cout << "Usage ./server [ip][port]" << std::endl;
    return 1;
  }
  _dict.insert(std::make_pair("hello","你好"));
  _dict.insert(std::make_pair("world","世界"));
  _dict.insert(std::make_pair("djh","董嘉豪"));
  Server myserver;
  myserver.Start(argv[1],atoi(argv[2]),Translate);
  return 0;
}
