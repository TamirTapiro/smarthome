#ifndef REQUESTMANAGER_H
#define REQUESTMANAGER_H
#include <string>
#include <iostream>
#include "Database.h"

using namespace std;

class RequestManager
{
private:
    //User usr;
    enum OPT {LOGIN,REGISTER,USERSCREEN};
    enum SUBOPT {ADD_S,RM_S,RM_FM,T_ONOFF,SET_ADMIN,SET_TIMER,SET_CRITICAL,HI};
    static const string mainOptions[]; //{"Login" , "Register", "UserScreen"};
    static const int mainAmount;
    static const string secOptions[];
    static const int secAmount;


    //Parser
    static bool  parseOneParam(string , string , string&);
    static bool  parseTwoParam(string , string , string , string&, string&);
    static bool  parseThreeParam(string , string , string ,string,string&, string&, string&);

public:
    //RequestManager(User &user);
    static void parse(const char*);
};

#endif
