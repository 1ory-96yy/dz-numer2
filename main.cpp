#include "oop.h"
#include <Windows.h>
#include <limits> 
#include <fstream>
#include <vector>
#include <string>
#include <iostream>
using namespace std;
int main() {
    SetConsoleCP(1251); 
    SetConsoleOutputCP(1251);
    PhoneBook phoneBook;
    string command;

    while (true) {
        cout << "Введіть команду (add - додати контакт, remove - видалити контакт, print - вивести всі контакти, exit - вийти): ";
        cin >> command;

        if (command == "add") {
            string name, home, work, mobile, additional;
            cout << "Введіть ПІБ: ";
            cin >> name;
            cout << "Введіть домашній телефон: ";
            cin >> home;
            cout << "Введіть робочий телефон: ";
            cin >> work;
            cout << "Введіть мобільний телефон: ";
            cin >> mobile;
            cout << "Введіть додаткову інформацію: ";
            cin >> additional;
            phoneBook.addContact(name, home, work, mobile, additional);
            cout << "Контакт додано." << endl;
        }
        else if (command == "remove") {
            string name;
            cout << "Введіть ПІБ контакта, якого потрібно видалити: ";
            cin >> name;
            phoneBook.removeContact(name);
            cout << "Контакт видалено." << endl;
        }
        else if (command == "print") {
            phoneBook.printAllContacts();
        }
        else if (command == "exit") {
            break;
        }
        else {
            cout << "Невідома команда. Будь ласка, спробуйте ще раз." << endl;
        }
    }

    return 0;
}