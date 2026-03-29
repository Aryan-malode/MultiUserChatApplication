#include "../include/chatroom.h"
#include "../include/user.h"
#include <iostream>
#include <ctime>
#include <dirent.h>

using namespace std;

string getTime()
{
    time_t now = time(0);
    string dt = ctime(&now);
    dt.pop_back();
    return dt;
}

int main()
{
    int choice;
    string username, password;

    user *currentUser = nullptr;

    while (currentUser == nullptr)
    {
        cout << "\n1. Register\n2. Login\nChoice: ";
        cin >> choice;

        if (choice == 1)
        {
            cout << "Enter username: ";
            cin >> username;
            cout << "Enter password: ";
            cin >> password;

            user temp("", "", "");
            temp.registeruser(username, password);
        }
        else if (choice == 2)
        {
            cout << "Enter username: ";
            cin >> username;
            cout << "Enter password: ";
            cin >> password;

            currentUser = user::login(username, password);
        }
        else
        {
            cout << "Invalid choice\n";
        }
    }

    while (true)
    {
        system("cls");

        cout << "===== WELCOME TO CHAT SYSTEM =====\n";

        cout << "\nAvailable Chat Rooms:\n";

        DIR *dir;
        struct dirent *entry;

        dir = opendir("./data/chats");

        if (dir != NULL)
        {
            while ((entry = readdir(dir)) != NULL)
            {
                string name = entry->d_name;

                if (name == "." || name == "..") continue;

                if (name.size() > 4)
                    name = name.substr(0, name.size() - 4);

                cout << "- " << name << endl;
            }
            closedir(dir);
        }
        else
        {
            cout << "No chat rooms found.\n";
        }

        cout << "\n1. Join Room\n2. Create Room\n3. Exit\nChoice: ";

        int ch;
        cin >> ch;
        cin.ignore();

        string roomName;

        if (ch == 1)
        {
            cout << "Enter room name: ";
            getline(cin, roomName);
        }
        else if (ch == 2)
        {
            cout << "Enter new room name: ";
            getline(cin, roomName);

            chatroom(roomName).createRoom();
            continue;
        }
        else
        {
            cout << "Exiting...\n";
            delete currentUser;
            return 0;
        }

        chatroom room(roomName);

        char option;
        string message;

        do {
            system("cls");

            room.displayMessages();

            cout << "\n[S] Send  [R] Refresh  [Q] Quit\n";
            cout << "Choice: ";
            cin >> option;
            cin.ignore();

            if (option == 'S' || option == 's')
            {
                cout << "Enter message: ";
                getline(cin, message);

                string formatted =
                    "[" + getTime() + "] " +
                    currentUser->getUsername() + ": " +
                    message;

                room.addMessage(formatted);
            }

        } while(option != 'Q' && option != 'q');
    }

    return 0;
}