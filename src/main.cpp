#include "../include/chatroom.h"
#include "../include/user.h"
#include <iostream>
#include <ctime>

using namespace std;


string getTime(){
    time_t now = time(0);
    string dt = ctime(&now);
    dt.pop_back();
    return dt;
}

int main()
{
    int choice;
    string username, password;

    user* currentUser = nullptr;

    // LOGIN / REGISTER
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

    int ch;
    string roomName, message;
    chatroom room("default");

    while (true)
    {
        cout << "\n===== CHAT SYSTEM =====\n";
        cout << "1. Create Room\n";
        cout << "2. Join Room\n";
        cout << "3. Send Message\n";
        cout << "4. View Messages\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> ch;
        cin.ignore();

        switch (ch)
        {
            case 1:
                cout << "Enter room name: ";
                getline(cin, roomName);
                room = chatroom(roomName);
                room.createRoom();
                break;

            case 2:
                cout << "Enter room name: ";
                getline(cin, roomName);
                room = chatroom(roomName);

                if (room.roomExists())
                    cout << "Joined successfully\n";
                else
                    cout << "Room does not exist\n";
                break;

            case 3:
                cout << "Enter message: ";
                getline(cin, message);

                {
                    string formatted =
                        "[" + getTime() + "] " +
                        currentUser->getUsername() + ": " +
                        message;

                    room.addMessage(formatted);
                }
                break;

            case 4:
                cout << "\n--- Chat History ---\n";
                room.displayMessages();
                break;

            case 5:
                cout << "Exiting...\n";
                delete currentUser;
                return 0;

            default:
                cout << "Invalid choice\n";
        }
    }

    return 0;
}