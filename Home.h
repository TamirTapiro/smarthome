#ifndef HOME_H
#define HOME_H
#include <vector>
#include <iostream>
#include <string>
#include "User.h"

class Home
{
public:
    string id,admin;
    vector <User> users;
    Home(string, string);
    ~Home();
    void addUser(string);
    void removeUser(string);
    string toJSON()const;
};

#endif