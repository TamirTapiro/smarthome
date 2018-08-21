#include "Home.h"

Home::Home(string _id, string _admin)
{
    id = _id;
    admin = _admin;
}

Home::~Home(){}

void Home::addUser(string _id)
{
    for(unsigned int i=0; i < users.size(); i++)
    {
        if(users[i].id == _id)
        {
            cout << "User " << _id << "is already exists." << endl;
            return;
        }
    }
    User user(_id);
    users.push_back(user);
}

void Home::removeUser(string id)
{
    bool flag = false;
    for(unsigned int i=0; i < users.size(); i++)
    {
        if(users[i].id == id) //Locate user
        {
            users.push_back(users[i]); //Push to the back of the vector
            users.pop_back(); //Pop the user out
            flag=true;
            break;
        }
    }
    if(flag)
        cout << "User " << id << " has been deleted." << endl;
    else
        cout << "User " << id << " does not exist." << endl;
}



string Home::toJSON() const {
    return "{\n\t\t\"id\":\"" + id + "\",\n\t\t\"admin\":\"" + admin + "\"\n}";
}
