#include <iostream>
#include "../include/user.h"

int main(){
    int choice;
    string username, password;

    cout<<"1. Register\n2. Login\nEnter choice: ";
    cin>>choice;

    if(choice == 1){
        cout<<"Enter username: ";
        cin>>username;
        cout<<"Enter password: ";
        cin>>password;

        user::registeruser(username, password);
    }
    else if(choice == 2){
        cout<<"Enter username: ";
        cin>>username;
        cout<<"Enter password: ";
        cin>>password;

        user* User = user::login(username, password);
        if(User != nullptr){
            cout<<"Welcome, " << User->getUsername() << "!" << endl;
        }
    }
    else{
        cout<<"Invalid choice!" << endl;
    }

    return 0;
}