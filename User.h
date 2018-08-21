#ifndef USER_H
#define USER_H
#include <iostream>
#include <string>
using namespace std;

class User
{
public:
    string id,name,password,homeId;
    User(string,string,string,string);
    User(string);
    User();
    ~User();
    string toJSON();
};


#endif