#include <iostream>
#include<fstream>
#include<string>

using namespace std;

bool isLoggedIn() {
    string username, password;
    string un, pw;// comparison string

    cout << "Enter a username: ";
    cin >> username;
    cout << "Enter a password: ";
    cin >> password;

    ifstream read(username + ".txt");// ifstream reads a file
    getline(read, un);//reads the username
    getline(read, pw);//reads the password

    if (un == username && pw == password)
        return true;
    else
        return false;
}

int main()
{
    system("Color 6");

    int choice;
    cout << endl;
    cout << "Main Menu: " << endl;
    cout << "-----------------------------\n";
    cout << "1. Register" << endl;
    cout << "2. Login" << endl;
    cout << endl;
    cout << "Your choice: ";
    cin >> choice;

    //checks choice
    if (choice == 1) {
        string username, password;

        cout << "Registration: " << endl;
        cout << endl;
        cout << "Select a username: ";
        cin >> username;
        cout << "Select a password: ";
        cin >> password;

        ofstream file;//ofstream creates a file
        file.open(username + ".txt");
        file << username << endl << password;
        file.close();
        cout << "Welcome " << username << "!" << endl;
    }
    else if (choice == 2) {
        bool status = isLoggedIn();

        if (!status) {
            system("cls");
            cout << endl;
            cout << "Invalid login!" << endl << "Try Again!\n";
            main();
            return 0;
        }
        else {
            cout << "Successfully logged in!" << endl;
            cout << endl;

            int choiceTwo;

            //display dashboard
            cout << "Welcome back!" << endl;
            cout << endl;
            cout << "DASHBOARD" << endl;
            cout << "No new messages.\n";
            cout << endl;
            cout << "1. Sign Out" << endl;
            cout << "2. Back to main menu\n";
            cout << "Your choice: " << endl;
            cin >> choiceTwo;

            if (choiceTwo == 1) system("exit");
            else if (choiceTwo == 2) main();
            else cout << "Not Valid Input! \n Try again!";
        }
    }
    else cout << "Not Valid Input!  \n Try again!";

    

}
