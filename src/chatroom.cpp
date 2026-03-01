#include "../include/chatroom.h"
#include <fstream>
chatroom::chatroom(string r){
    roomname = r;
}

bool chatroom::roomExists(){
    ifstream infile("./data/chats/" +roomname + ".txt");
    return infile.good();
}

void chatroom::createRoom(){
    if(!roomExists()){
        ofstream outfile ("./data/chats/" + roomname + ".txt");
        outfile.close();
    }

}

void chatroom::addMessage(string formattedMessage){
    ofstream outfile("./data/chats/"+roomname+".txt", ios::app);
    outfile << formattedMessage << endl;
}

void chatroom::displayMessages(){
    ifstream infile("./data/chats/" + roomname + ".txt");
    string message;
    while(getline(infile, message)){
        cout << message << endl;
    }
}
