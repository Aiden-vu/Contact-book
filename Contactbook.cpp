#include <iostream>
#include <fstream>
using namespace std;

string name, surname, number;

void addcontact() {
    ofstream contacts("contacts.txt", ios::app);

    cout << "Enter a first name: ";
    cin >> name;

    cout << "\n" << "Enter a last name: ";
    cin >> surname;

    cout << "\n" << "Enter a phone number: ";
    cin >> number;

    if (contacts.is_open()) {
        contacts << name << " " << surname << " " << number << "\n";

        cout << "\n" << "Contact saved!" << "\n";
    }

    contacts.close();
}

void searchcontact() {
    ifstream contacts("contacts.txt");
    string answer;
    cout << "Enter a contact: ";
    cin >> answer;
    while (contacts >> name >> surname >> number) {
        if (name == answer || surname == answer) {
            cout << "Name is: " << name << "\n";
            cout << "Last name is: " << surname << "\n";
            cout << "Phone number is: " << number << "\n";
            break;
        }
    }
    contacts.close();
}

int main() {
    int choice;
    bool active = true;
    
    while (active == true) {
        cout << "Welcome to the contact book!" << "\n" << "1. Add contact" << "\n" << "2. Search contact" << "\n" << "3. Help" << "\n" << "4. Exit" << "\n";
        cin >> choice;

        switch (choice) {
            case 1:
            addcontact();
            break;
            case 2:

            searchcontact();
            break;
            case 3:

            break;
            case 4:
            cout << "\n" << "See you later!" << "\n";
            active = false;
            break;

            default:
            cout << "Invalid Input!";
            break;
        }
    }

    return 0;
}