//
// Created by ran on 6/7/18.
//

#ifndef LINUX_PROJECT_MASTER_NEWDATABASE_H
#define LINUX_PROJECT_MASTER_NEWDATABASE_H

#include <sqlite3.h>
#include <stdlib.h>
#include <cctype>
#include <ctime>
#include "User.h"
#include "Socket.h"
#include "Home.h"


using namespace std;
class Database {

    private:
        const char* FILENAME = "/home/tamir/smarthome/DB/smarthome.db"; // need to change the path here to your path.
        sqlite3* dbFile;
        char* errMsg = 0;
        int rc;
        const char* data;
        User currentUser;


    public:
        static int counter;
        static int selectCounter;

        Database();
        ~Database();
        static int countCallback(void *data, int argc, char **argv,char** columns);
        static int socketsCallback(void *data, int argc, char **argv, char **socketCols);
        static int uidCallback(void *data, int argc, char **argv, char **uidCol);
        static int usersCallback(void *data, int argc, char **argv, char **userCol);
        static int homeCallBack(void *data, int argc, char **argv, char **homeCol);
        void newUser(string username,string password,string homeId);
        void login(string UID,string password);
        void newSocket(string uid, string hid, string socketName);
        void setAdmin(string uid,string hid);
        void homeSocketsInfo(string hid);
        void usersInfo(string hid);
        void homeInfo(string hid);
        void getOverAll(string hid);
        void removeSocket(string sid,string hid);
        void changeSocketStatus(string sid,string status,string uid);
        void removeUser(string uid,string adminId);
        void setCritical(string sid,string uid,string critical);
        void setTimer(string uid,string sid,string timer);
        string generateSID();
};









#endif //LINUX_PROJECT_MASTER_NEWDATABASE_H
