#include <iostream>
#include <string>
#ifndef CHATROOM_H
#define CHATROOM_H

using namespace std;
class chatroom
{
private:
    string roomname;

public:
    chatroom(string roomname);
    void createRoom();
    bool roomExists();
    void addMessage(string message);
    void displayMessages();
};


#endif