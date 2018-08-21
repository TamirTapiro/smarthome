//
// Created by ran on 6/7/18.
//
#include "Database.h"
#include <iostream>
int Database::counter = 0;
int Database::selectCounter = 0;
Database::Database()
{
    rc = sqlite3_open(FILENAME, &dbFile);

    if (rc)
    {
        cout << "Can't open database: " << sqlite3_errmsg(dbFile) << endl;
    }
}
Database::~Database()
{

    sqlite3_close(dbFile);
}

int Database::countCallback(void *data, int argc, char **argv,char** columns)
{
    //for (int i = 0 ; i < argc ; i++) cout << argv[i] << endl; // If you want to display output for testing purposes
    if (argv[0])
        counter++;
    return 0;
}



void Database::newUser(string username,string password,string homeID) {
    counter = selectCounter = 0;
    string query = "SELECT uid FROM user WHERE uid='" + username + "';";
    rc = sqlite3_exec(dbFile, query.c_str(), countCallback, (void *) data, &errMsg);
    if (rc != SQLITE_OK) {
        sqlite3_free(errMsg);
        return;
    }
    if (!counter) //If user does not exist
    {
        int adminCheck=0;
        counter = 0;
        //Check if this is the first user that is registering to a home - if he is, he will be assigned as admin
        query = "SELECT * FROM user WHERE HOMEID = '" + homeID + "';";
        rc = sqlite3_exec(dbFile, query.c_str(), countCallback, (void *) data, &errMsg);
        if (rc != SQLITE_OK) {
            sqlite3_free(errMsg);
            return;
        }
        adminCheck=counter;
        counter = selectCounter = 0;

        query = "INSERT INTO USER VALUES('";
        query += username;
        query += "','";
        query += "user" + username;
        query += "','";
        query += password;
        query += "','";
        query += homeID;
        query += "');";
        rc = sqlite3_exec(dbFile, query.c_str(), usersCallback, 0, &errMsg);

        if (rc == SQLITE_OK)
        {
            cout << "{\"status\":\"success\",\"message\":\"User has been created successfully!\"}";
            if(!adminCheck)
            {
                 setAdmin(username, homeID);                
            }
        }
        else
            sqlite3_free(errMsg);

    }
    else
        cout << "{\"status\":\"failure\",\"message\":\"User already exists!\"}";

}



void Database::login(string UID,string password) {

    counter = selectCounter = 0;
    string query = "SELECT * FROM USER WHERE UID = '" + UID + "' AND PASSWORD = '" + password + "';";
    //Check that there is an existing user in the database
    rc = sqlite3_exec(dbFile, query.c_str(), countCallback, (void *) data, &errMsg);
    if (counter != 0){
        currentUser.id = UID;

        rc = sqlite3_exec(dbFile, query.c_str(), usersCallback, (void *) data, &errMsg);
        if (rc != SQLITE_OK)
            sqlite3_free(errMsg);    }
    else{
        cout << "{\"status\":\"failure\",\"message\":\"User does not exist!\"}";
    }
    if (rc != SQLITE_OK)
        sqlite3_free(errMsg);
}

void Database::newSocket(string uid, string hid, string socketName){
//addSocket(uid hid socketName)
    counter = selectCounter = 0;
    string query = "INSERT INTO socket VALUES('";
    query += generateSID();
    query += "','";
    query += socketName;
    query += "','";
    query += "0";
    query += "','";
    query += "0";
    query += "','";
    query += "0";
    query += "','";
    query += hid;
    query += "','";
    query += uid;
    query += "');";
    rc = sqlite3_exec(dbFile, query.c_str(), countCallback, (void *)data, &errMsg);
    if(rc != SQLITE_OK)
    {
        sqlite3_free(errMsg);
        cout << "{\"status\":\"failure\",\"message\":\"Failed to add socket! " +to_string(rc)+"\"}" << endl;
    }
    else{
        cout << "{\"status\":\"success\",\"message\":\"The socket has successfully been added!\"}";
    }
}

long FourDigitRandom()
   {
   return (long) rand() % (9999 + 1); 
   }

string Database::generateSID()
{
    //Get new Socket ID according to the last socket ID that was given
    Database::counter = Database::selectCounter = 0;
    //Select the last SID value
    string query = "SELECT * from socket;";
    rc = sqlite3_exec(dbFile, query.c_str(), countCallback, (void *)data, &errMsg);
    if(rc != SQLITE_OK)
        sqlite3_free(errMsg);
    //cout << "{\"counter\":\"" << to_string(counter) << "\"}";
    long l = FourDigitRandom() + (FourDigitRandom() * 10000);
    return to_string(Database::counter + l);

}

int Database::socketsCallback(void *data, int argc, char **argv, char **socketCols)
{
    
    string
            sid = argv[0],
            name = argv[1],
            critical = argv[2],
            status = argv[3],
            date = argv[4],
            homeId = argv[5],
            lastUser = argv[6];
    Socket socket(sid,name,critical,status,date,homeId,lastUser);
    cout << socket.toJSON();
    
    
    return 0;
};

void Database::setAdmin(string uid,string hid)
{
    Database::counter = Database::selectCounter = 0;
    string query = "SELECT UID FROM USER WHERE UID = '" + uid + "' AND HOMEID='" + hid + "' AND UID NOT IN (SELECT Admin from HOME );";
    rc = sqlite3_exec(dbFile, query.c_str(), countCallback, (void *)data, &errMsg);
    if(!Database::counter)
    {
        cout << "{\"status\":\"failure\",\"message\":\"User does not exist or the user is already an admin!\"}" << endl;
        if (rc != SQLITE_OK)
            sqlite3_free(errMsg);
    }
    else{
        query = "INSERT INTO HOME VALUES('";
        query += hid;
        query += "','";
        query += uid;
        query += "');";
        rc = sqlite3_exec(dbFile, query.c_str(), countCallback, (void *)data, &errMsg);
        if (rc != SQLITE_OK)
        {
            sqlite3_free(errMsg);
            cout << "{\"status\":\"failure\",\"message\":\"Failed to set user as an admin.\"}" << endl;
        }
        else{
            cout << "{\"status\":\"success\",\"message\":\"User id :" + uid + " Has been set to be an Admin successfully!\"}";
        }
    }

}

void Database::homeSocketsInfo(string hid)
{
    Database::counter = Database::selectCounter = 0;
    string query = "SELECT * FROM SOCKET WHERE HOUSE = '" + hid + "';";
    rc = sqlite3_exec(dbFile, query.c_str(), socketsCallback, (void *)data, &errMsg);
    if(rc != SQLITE_OK)
        sqlite3_free(errMsg);
}

int Database::usersCallback(void *data, int argc, char **argv, char **userCol){
    string
            uid = argv[0],
            name = argv[1],
            password = argv[2],
            homeId = argv[3];
    User user(uid,name,password,homeId);
    cout << user.toJSON();

    if (++Database::selectCounter != Database::counter)
        cout << ",";
    return 0;

}

void Database::usersInfo(string hid)
{
    Database::counter = Database::selectCounter = 0;
    string query = "SELECT * FROM USER WHERE HOUSE = '" + hid + "';";
    rc = sqlite3_exec(dbFile, query.c_str(), usersCallback, (void *) data, &errMsg);
    if(rc != SQLITE_OK)
        sqlite3_free(errMsg);
}

void Database::getOverAll(string hid)
{
    //Get all information regarding a particular home
    homeSocketsInfo(hid);
    usersInfo(hid);
    homeInfo(hid);
}

void Database::removeSocket(string sid,string hid)
{
    counter=0;
    string query="SELECT * FROM socket WHERE sid='" + sid + "' AND HOUSE='" + hid + "';";
    rc = sqlite3_exec(dbFile, query.c_str(), countCallback, (void *)data, &errMsg);
    if(rc != SQLITE_OK)
    {
        sqlite3_free(errMsg);
        cout << "{\"status\":\"failure\",\"message\":\"Failed to delete socket!\"}";
    }
    if(counter)
    {
        query = "DELETE FROM SOCKET WHERE SID='" + sid + "' AND HOUSE='" + hid + "';";
        rc = sqlite3_exec(dbFile, query.c_str(), countCallback, (void *)data, &errMsg);
        if(rc != SQLITE_OK)
        {
            sqlite3_free(errMsg);
            cout << "{\"status\":\"failure\",\"message\":\"Failed to delete socket!\"}";
        }
        else
            cout << "{\"status\":\"success\",\"message\":\"The socket has successfully been deleted!\"}";

    }

    else{
        cout << "{\"status\":\"failure\",\"message\":\"Socket doesnt exist or soednt belonge to your house!\"}";
    }
}

int Database::homeCallBack(void *data, int argc, char **argv, char **homeCol)
{
    string
            hid = argv[0],
            admin = argv[1];

    Home home(hid,admin);
    cout << home.toJSON();

    //if (++Database::selectCounter != Database::counter)
    //    cout << ",";
    return 0;
}

void Database::homeInfo(string hid)
{
    counter = selectCounter = 0;
    string query = "SELECT * FROM HOME WHERE HID = '" + hid + "';";
    rc = sqlite3_exec(dbFile, query.c_str(), homeCallBack, (void *) data, &errMsg);
    if(rc != SQLITE_OK)
        sqlite3_free(errMsg);
}

void Database::changeSocketStatus(string sid,string status,string uid) // FINISHED
{
    Database::counter = 0;
    //Check that the socket belongs to the user's house
    string query = "SELECT * FROM SOCKET WHERE HOUSE=(SELECT homeId FROM USER WHERE UID='" + uid + "');";
    rc = sqlite3_exec(dbFile, query.c_str(), countCallback, (void *)data, &errMsg);
    if(rc != SQLITE_OK)
        sqlite3_free(errMsg);
    if(counter != 0) {

        if (status == "0") {
            string query = "UPDATE Socket SET STATUS = '0', USER='" + uid + "' WHERE SID='" + sid + "';";
            rc = sqlite3_exec(dbFile, query.c_str(), countCallback, (void *) data, &errMsg);
            if (rc != SQLITE_OK) {
                sqlite3_free(errMsg);
                cout << "{\"status\":\"failure\",\"message\":\"Failed to turn off the socket!\"}" << endl;
            }
            else cout << "{\"status\":\"success\",\"message\":\"The socket has successfully deactivated!\"}" << endl;

        }
        if (status == "1") {
            string query = "UPDATE Socket SET STATUS = '1', USER='" + uid + "' WHERE SID='" + sid + "';";
            rc = sqlite3_exec(dbFile, query.c_str(), countCallback, (void *) data, &errMsg);
            if (rc != SQLITE_OK) {
                cout << "{\"status\":\"failure\",\"message\":\"Failed to turn on the socket!\"}" << endl;
                sqlite3_free(errMsg);
            }
            else cout << "{\"status\":\"success\",\"message\":\"The socket has successfully been activated!\"}" << endl;
        }
    }
    else {
        cout << "{\"status\":\"failure\",\"message\":\"No socket found at this home!\"}" << endl;
    }

}

void Database::removeUser(string uid,string adminId)
{
    counter = 0;
    string query = "DELETE FROM USER WHERE UID='" + uid + "'";
    string query2 = "SELECT uid FROM user WHERE homeid= (SELECT hid FROM home WHERE admin='" + adminId + "') AND uid='" + uid + "';"; //Check that the the admin and user are from the same home



    rc = sqlite3_exec(dbFile, query2.c_str(), countCallback, (void *)data, &errMsg);
    if(rc != SQLITE_OK)
    {
        sqlite3_free(errMsg);
        cout << "{\"status\":\"failure\",\"message\":\"Failed to delete user!\"}" << endl;
    }
    else{
        if(counter)
        {
            rc = sqlite3_exec(dbFile, query.c_str(), countCallback, (void *)data, &errMsg);
            if(rc != SQLITE_OK)
            {
                sqlite3_free(errMsg);
                cout << "{\"status\":\"failure\",\"message\":\"Failed to delete user!\"}" << endl;
            }
            else
                cout << "{\"status\":\"success\",\"message\":\"The user has successfully been deleted!\"}" << endl;

        }
        else cout << "{\"status\":\"failure\",\"message\":\"Failed to delete user! (Not an admin?)\"}" << endl;
    }
}

void Database::setCritical(string sid,string uid,string critical) {
    Database::counter = 0;
    string query =
            "SELECT * FROM user WHERE uid='" + uid + "' AND HOMEID in (SELECT HOUSE from socket WHERE sid ='" + sid +
            "');";
    rc = sqlite3_exec(dbFile, query.c_str(), countCallback, (void *) data, &errMsg);
    if (rc != SQLITE_OK)
        sqlite3_free(errMsg);
    if (counter != 0) {

        if (critical == "0") {
            string query = "UPDATE Socket SET CRITICAL='0' WHERE SID='" + sid + "';";
            rc = sqlite3_exec(dbFile, query.c_str(), countCallback, (void *) data, &errMsg);
            if (rc != SQLITE_OK) {
                sqlite3_free(errMsg);
                cout << "{\"status\":\"failure\",\"message\":\"Failed to turn non-critical!\"}" << endl;
            } else cout << "{\"status\":\"success\",\"message\":\"The socket defined as non-Critical!\"}" << endl;

        }
        if (critical == "1") {
            string query = "UPDATE Socket SET CRITICAL='1' WHERE SID='" + sid + "';";
            rc = sqlite3_exec(dbFile, query.c_str(), countCallback, (void *) data, &errMsg);
            if (rc != SQLITE_OK) {
                sqlite3_free(errMsg);
                cout << "{\"status\":\"failure\",\"message\":\"Failed to turn critical!\"}" << endl;
            } else cout << "{\"status\":\"success\",\"message\":\"The socket defined as Critical!\"}" << endl;

        } 

    }
    else cout << "{\"status\":\"failure\",\"message\":\"Socket does not found!\"}";
}

void Database::setTimer(string uid,string sid,string timer)
{
    counter=0;
    if(stoi(timer) > 60 || stoi(timer) < 1 )
        cout << "{\"status\":\"failure\",\"message\":\"Invalid timer inputed!\"}";
    
    else{
        //string query = "UPDATE socket SET timer='" + timer + "' WHERE sid IN (SELECT sid FROM socket WHERE sid='" + sid +"' AND HOUSE IN(SELECT homeid FROM user WHERE uid='" + uid +"'));";
        string query = "UPDATE socket SET timer='" + timer + "' WHERE sid ='" + sid + "';";

        rc = sqlite3_exec(dbFile, query.c_str(), countCallback, (void *) data, &errMsg);
        if (rc != SQLITE_OK) {
            sqlite3_free(errMsg);
            cout << "{\"status\":\"failure\",\"message\":\"Failed to set timer for socket!\"}";
        }
        else
        {
            cout << "{\"status\":\"success\",\"message\":\"Timer has been set!\"}";
        }

    }

}