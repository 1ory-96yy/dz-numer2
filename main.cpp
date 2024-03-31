#include "oop.h"
#include <Windows.h>
#include <iostream>
using namespace std;
int main() {
    SetConsoleCP(1251); 
    SetConsoleOutputCP(1251);

        PhoneBook phoneBook;

        while (true) {
            std::cout << "����:" << std::endl;
            std::cout << "1. ������ �������" << std::endl;
            std::cout << "2. �������� �������" << std::endl;
            std::cout << "3. �������� �� ��������" << std::endl;
            std::cout << "4. �������� � ����" << std::endl;
            std::cout << "5. ����������� � �����" << std::endl;
            std::cout << "6. ����� � ��������" << std::endl;

            int choice;
            std::cout << "������� �����: ";
            std::cin >> choice;

            switch (choice) {
            case 1: {
                char name[256], home[256], work[256], mobile[256], additional[256];
                std::cout << "������ ��'�: ";
                std::cin.ignore();
                std::cin.getline(name, 256);
                std::cout << "������ ������� �������: ";
                std::cin.getline(home, 256);
                std::cout << "������ ������� �������: ";
                std::cin.getline(work, 256);
                std::cout << "������ �������� �������: ";
                std::cin.getline(mobile, 256);
                std::cout << "������ ��������� ����������: ";
                std::cin.getline(additional, 256);
                phoneBook.addContact(name, home, work, mobile, additional);
                break;
            }
            case 2: {
                char nameToDelete[256];
                std::cout << "������ ��'� �������� ��� ���������: ";
                std::cin.ignore();
                std::cin.getline(nameToDelete, 256);
                phoneBook.removeContact(nameToDelete);
                break;
            }
            case 3:
                std::cout << "�� ��������:" << std::endl;
                phoneBook.printAllContacts();
                std::cout << std::endl;
                break;
            case 4:
                phoneBook.saveToFile("phonebook.txt");
                break;
            case 5:
                phoneBook.loadFromFile("phonebook.txt");
                break;
            case 6:
                std::cout << "���������� ��������." << std::endl;
                return 0;
            default:
                std::cout << "������� ����. ��������� �� ���." << std::endl;
            }
        }

        return 0;
    }
