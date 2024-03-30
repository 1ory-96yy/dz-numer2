#include "oop.h"
#include <Windows.h>
#include <fstream>
#include <iostream>
using namespace std;
int main() {
    SetConsoleCP(1251); 
    SetConsoleOutputCP(1251);

    
        PhoneBook phoneBook;

        while (true) {
            cout << "Меню:" << endl;
            cout << "1. Додати контакт" << endl;
            cout << "2. Видалити контакт" << endl;
            cout << "3. Показати всі контакти" << endl;
            cout << "4. Вийти з програми" << endl;

            int choice;
            cout << "Виберіть опцію: ";
            cin >> choice;

            switch (choice) {
            case 1: {
                string name, home, work, mobile, additional;
                cout << "Введіть ім'я: ";
                cin.ignore();
                getline(cin, name);
                cout << "Введіть домашній телефон: ";
                getline(cin, home);
                cout << "Введіть робочий телефон: ";
                getline(cin, work);
                cout << "Введіть мобільний телефон: ";
                getline(cin, mobile);
                cout << "Введіть додаткову інформацію: ";
                getline(cin, additional);
                phoneBook.addContact(name, home, work, mobile, additional);
                break;
            }
            case 2: {
                string nameToDelete;
                cout << "Введіть ім'я контакта для видалення: ";
                cin.ignore();
                getline(cin, nameToDelete);
                phoneBook.removeContact(nameToDelete);
                break;
            }
            case 3:
                cout << "Всі контакти:" << endl;
                phoneBook.printAllContacts();
                cout << endl;
                break;
            case 4:
                cout << "Завершення програми." << endl;
                return 0;
            default:
                cout << "Невірний вибір. Спробуйте ще раз." << endl;
            }
        }

        return 0;
    }
