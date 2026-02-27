#ifndef USER_H
#define USER_H

#include <string>
using namespace std;

class user
{
private:
    string username;
    string password;
    string role;

public:
    user(string u, string p, string r);
    string getUsername();
    string getRole();
    bool checkPassword(string p);

    static bool registeruser(string username, string password);
    static user* login(string username, string password);
};

#endif