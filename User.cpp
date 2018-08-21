#include "User.h"


User::User(string _id, string _name, string _password,string _homeID)
{
    id = _id;
    name = _name;
    password = _password;
    homeId = _homeID;
}

User::User(string _id)
{
    id = _id;
}

User::User(){}
User::~User(){}

string User::toJSON()
{
    return "{\n\t\t\"id\":\"" + id + "\",\n\t\t\"name\":\"" + name + "\",\n\t\t\"password\":\"" + password + "\",\n\t\t\"HomeID\":\"" + homeId + "\"\n}";
}