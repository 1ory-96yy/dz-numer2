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
        cout << "������ ������� (add - ������ �������, remove - �������� �������, print - ������� �� ��������, exit - �����): ";
        cin >> command;

        if (command == "add") {
            string name, home, work, mobile, additional;
            cout << "������ ϲ�: ";
            cin >> name;
            cout << "������ ������� �������: ";
            cin >> home;
            cout << "������ ������� �������: ";
            cin >> work;
            cout << "������ �������� �������: ";
            cin >> mobile;
            cout << "������ ��������� ����������: ";
            cin >> additional;
            phoneBook.addContact(name, home, work, mobile, additional);
            cout << "������� ������." << endl;
        }
        else if (command == "remove") {
            string name;
            cout << "������ ϲ� ��������, ����� ������� ��������: ";
            cin >> name;
            phoneBook.removeContact(name);
            cout << "������� ��������." << endl;
        }
        else if (command == "print") {
            phoneBook.printAllContacts();
        }
        else if (command == "exit") {
            break;
        }
        else {
            cout << "������� �������. ���� �����, ��������� �� ���." << endl;
        }
    }

    return 0;
}