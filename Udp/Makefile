.PHONY:all
all:server client

server:Server.cpp 
	g++ -o $@ $^ -std=c++11
client:Client.cpp
	g++ -o $@ $^ -std=c++11
.PHONY:clean
clean:
	rm -f server client 
