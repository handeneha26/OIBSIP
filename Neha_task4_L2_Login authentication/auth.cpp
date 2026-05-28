#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Function to register a user
void registerUser() {
    string username, password;

    cout << "\n===== REGISTER =====\n";
    cout << "Enter Username: ";
    cin >> username;

    cout << "Enter Password: ";
    cin >> password;

    ofstream file("users.txt", ios::app);

    if(file.is_open()) {
        file << username << " " << password << endl;
        file.close();

        cout << "\nRegistration Successful!\n";
    }
    else {
        cout << "Error opening file.\n";
    }
}

// Function to login
bool loginUser() {
    string username, password;
    string storedUser, storedPass;

    cout << "\n===== LOGIN =====\n";

    cout << "Enter Username: ";
    cin >> username;

    cout << "Enter Password: ";
    cin >> password;

    ifstream file("users.txt");

    if(file.is_open()) {

        while(file >> storedUser >> storedPass) {

            if(username == storedUser &&
               password == storedPass) {

                file.close();
                return true;
            }
        }

        file.close();
    }

    return false;
}

// Secured page
void securedPage() {
    cout << "\n==============================";
    cout << "\nWelcome to Secure Dashboard!";
    cout << "\nAccess Granted Successfully.";
    cout << "\n==============================\n";
}

int main() {

    int choice;

    do {
        cout << "\n====== AUTHENTICATION SYSTEM ======\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";

        cout << "Enter Choice: ";
        cin >> choice;

        switch(choice) {

            case 1:
                registerUser();
                break;

            case 2:
                if(loginUser()) {
                    cout << "\nLogin Successful!\n";
                    securedPage();
                }
                else {
                    cout << "\nInvalid Username or Password!\n";
                }
                break;

            case 3:
                cout << "\nProgram Ended.\n";
                break;

            default:
                cout << "\nInvalid Choice!\n";
        }

    } while(choice != 3);

    return 0;
}