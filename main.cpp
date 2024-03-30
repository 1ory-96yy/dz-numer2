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
            cout << "����:" << endl;
            cout << "1. ������ �������" << endl;
            cout << "2. �������� �������" << endl;
            cout << "3. �������� �� ��������" << endl;
            cout << "4. ����� � ��������" << endl;

            int choice;
            cout << "������� �����: ";
            cin >> choice;

            switch (choice) {
            case 1: {
                string name, home, work, mobile, additional;
                cout << "������ ��'�: ";
                cin.ignore();
                getline(cin, name);
                cout << "������ ������� �������: ";
                getline(cin, home);
                cout << "������ ������� �������: ";
                getline(cin, work);
                cout << "������ �������� �������: ";
                getline(cin, mobile);
                cout << "������ ��������� ����������: ";
                getline(cin, additional);
                phoneBook.addContact(name, home, work, mobile, additional);
                break;
            }
            case 2: {
                string nameToDelete;
                cout << "������ ��'� �������� ��� ���������: ";
                cin.ignore();
                getline(cin, nameToDelete);
                phoneBook.removeContact(nameToDelete);
                break;
            }
            case 3:
                cout << "�� ��������:" << endl;
                phoneBook.printAllContacts();
                cout << endl;
                break;
            case 4:
                cout << "���������� ��������." << endl;
                return 0;
            default:
                cout << "������� ����. ��������� �� ���." << endl;
            }
        }

        return 0;
    }
