#ifndef SOCKET_H
#define SOCKET_H
#include <string>
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
class Socket
{
public:
    string
        sid,name,critical,status,date,homeId,lastUser;
    Socket(string,string,string,string,string,string,string);
    ~Socket();
    void setStatus(Socket socket);
    void resetStatus(Socket socket);
    void setCritical(Socket socket);
    void resetCritical(Socket socket);
    string toJSON() const;
};

#endif