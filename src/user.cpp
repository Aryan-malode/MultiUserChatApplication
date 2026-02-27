#include "../include/user.h"
#include <fstream>
#include <iostream>

user::user(string u, string p, string r)
{
    username = u;
    password = p;
    role = r;
}

string user::getUsername()
{
    return username;
}

string user::getRole()
{
    return role;
}

bool user::checkPassword(string p)
{
    return password == p;
}

bool user::registeruser(string username, string password)
{
    ifstream infile("data/users.txt");
    string u, p, r;

    while (infile >> u >> p >> r)
    {
        if (u == username)
        {
            cout << "Username already exists!" << endl;
            return false;
        }
    }
    infile.close();

    ofstream outfile("data/users.txt", ios::app);
    outfile << username << " " << password << " user" << endl;
    outfile.close();

    cout << "Registration successfull!" << endl;
    return true;
}

user *user::login(string username, string password)
{
    ifstream infile("data/users.txt");
    string u, p, r;

    while (infile >> u >> p >> r)
    {
        if (u == username && p == password)
        {
            infile.close();
            return new user(u, p, r);
        }
    }
    infile.close();
    cout << "Invalid username or password!" << endl;
    return nullptr;
}