#include "RequestManager.h"

using namespace std;

const string RequestManager::mainOptions[]= { "/Login/" , "/Register/", "/UserScreen/"};
const int RequestManager::mainAmount = 3;
const string RequestManager::secOptions[] = {"AddSocket/" , "RemoveSocket/" , "RemoveFM/", "TurnOnOff/" , "SetAdmin/", "SetTimer/" , "SetCritical/", "HomeInfo/"};
const int RequestManager::secAmount = 8;



bool RequestManager::parseOneParam(string stringToParse, string param, string &var){
    if (stringToParse.find(param + "=") != 0)
        return false;
    var = stringToParse.substr(param.length() + 1);
    return true;
};

bool  RequestManager::parseTwoParam(string stringToParse, string param1, string param2, string &var1, string &var2){
    if (stringToParse.find(param1 + "=") != 0) return false;

    int delimIndex = stringToParse.find("&");
    if (delimIndex == -1) return false;

    var1 = stringToParse.substr(param1.length() + 1, delimIndex - (param1.length() +1));
    var2 = stringToParse.substr(delimIndex + param2.length() +2);
    return true;
};

bool RequestManager::parseThreeParam(string stringToParse,
                                     string param1, string param2, string param3,
                                     string &var1, string &var2, string &var3){
    if (stringToParse.find(param1+"=") != 0) return false;
    int delimIndex = stringToParse.find("&");
    if (delimIndex == -1) return false;
    var1 = stringToParse.substr(param1.length() + 1, delimIndex - (param1.length() +1));
    stringToParse = stringToParse.substr(param1.length() + var1.length() + 2);

    delimIndex = stringToParse.find("&");
    if (delimIndex == -1) return false;
    var2 = stringToParse.substr(param2.length() + 1 , delimIndex - (param2.length()+1));
    var3 = stringToParse.substr(delimIndex +  param3.length() + 2);
    return true;
}

void RequestManager::parse(const char* stringToParse){
    string  parsedString(stringToParse),
            uid,
            sid,
            hid,
            userName,
            password,
            status,
            critical,
            socketName,
            date,
            lastUser,
            day,
            hour,
            timer,
            adminId, /////ADDEDInva
            defaultResponse = "{\"status\":\"failure\",\"message\":\"Invalid request\"}"; //Default
    Database db;

    int option;
    bool found = false;
    for (int i = 0; i < RequestManager::mainAmount; i++){
        option = i;
        int index = parsedString.find(RequestManager::mainOptions[i]); //look for the string in the uri sent from main
        if (index == 0){ parsedString = parsedString.substr(RequestManager::mainOptions[i].length());found= true; break; }
    }

    if (!found) {
        cout<< defaultResponse;
        return;
    }


    switch (option){
        case LOGIN: {
            if (parseTwoParam(parsedString, "uid", "password", uid, password)) {
                db.login(uid, password);
            } else cout << defaultResponse;
            break;
        }
        case REGISTER: {
            if (parseThreeParam(parsedString, "uid", "hid", "password", uid, hid, password))
                db.newUser(uid, password, hid);
            else cout << defaultResponse;
            break;
        }
        case USERSCREEN: {
            int subOpt = 0;
            bool subFound = false;
            for (int i = 0; i < RequestManager::secAmount; i++) {
                subOpt = i;
                int index = parsedString.find(RequestManager::secOptions[i]);
                if (index == 0) {
                    subFound = true;
                    parsedString = parsedString.substr(RequestManager::secOptions[i].length());
                    break;
                }
            }

            if (!subFound) {
                cout << defaultResponse;
                return;
            }
            switch (subOpt) {
                case ADD_S: {

                    if (parseThreeParam(parsedString, "uid", "hid","socketName", uid,hid,socketName)) {
                        db.newSocket(uid,hid,socketName);
                    } else {
                        cout << defaultResponse;
                    }
                    break;

                }
                case RM_S: {

                    if (parseTwoParam(parsedString, "sid","hid", sid, hid)) {

                        db.removeSocket(sid,hid); //
                    } else
                        cout << defaultResponse;
                    break;
                }
                case T_ONOFF: {
                    if (parseThreeParam(parsedString, "sid", "status", "uid", sid, status, uid))
                        db.changeSocketStatus(sid, status, uid);
                    else
                        cout << defaultResponse;
                    break;
                }

                case RM_FM:
                {
                    if (parseTwoParam(parsedString, "uid","admin", uid, adminId)) {

                        db.removeUser(uid,adminId);
                    } else
                        cout << defaultResponse;

                    break;
                }
                case SET_TIMER: {

                    if (parseThreeParam(parsedString, "uid", "sid", "timer", uid, sid, timer)){
                        //cout << "{\"a\":\"b\"}";
                        db.setTimer(uid,sid,timer);
                    }
                    else
                        cout<< defaultResponse;
                    break;
                }
                case SET_CRITICAL:
                {
                    if(parseThreeParam(parsedString,"sid","uid","critical",sid,uid,critical)){
                        db.setCritical(sid,uid,critical);
                    }
                    else cout << defaultResponse;
                    break;
                }
                case HI: {
                    if (parseOneParam(parsedString, "hid", hid)) {
                        db.getOverAll(hid);
                    } else
                        cout << defaultResponse;
                    break;
                }
                
                default: {
                    cout << defaultResponse;
                    break;
                }
                
            } // END OF SECOND SWITCH
            break;
        }
        default: {
            cout << defaultResponse;
            break;
        }
    }//END FIRST switch


}
