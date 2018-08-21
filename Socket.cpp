#include "Socket.h"


Socket::Socket(string _id, string _name, string _critical, string _status,string _date, string _homeId, string _lastUser)
{
    sid = _id;
    name = _name;
    critical = _critical;
    status = _status;
    date = _date;
    homeId = _homeId;
    lastUser = _lastUser;
}

Socket::~Socket(){}

void Socket::setCritical(Socket socket)
{
    socket.critical = "1";
    cout << socket.name + ":" " Critical mode is now ON" << endl;
}

void Socket::resetCritical(Socket socket)
{
    socket.critical = "0";
    cout << socket.name + ":" " Critical mode is now OFF" << endl;
}

void Socket::setStatus(Socket socket)
{
    socket.status = "1";
    cout << socket.name + " status: ON" << endl;
}

void Socket::resetStatus(Socket socket)
{
    socket.status = "0";
    cout << socket.name + " status: OFF" << endl;
}

string Socket::toJSON()const{
    return "{\n\t\t\"sid\":\"" + sid + "\",\n\t\t\"name\":\"" + name + "\",\n\t\t\"critical\":\"" + critical + "\",\n\t\t\"status\":\"" + status
           + "\",\n\t\t\"timer\":\"" + date + "\",\n\t\t\"home id\":\"" + homeId +  "\",\n\t\t\"Last user\":\"" + lastUser + "\"\n\t}";
}