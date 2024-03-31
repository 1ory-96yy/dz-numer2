#include "oop.h"
#include <Windows.h>
#include <iostream>
using namespace std;
int main() {
    SetConsoleCP(1251); 
    SetConsoleOutputCP(1251);

        PhoneBook phoneBook;

        while (true) {
            std::cout << "Меню:" << std::endl;
            std::cout << "1. Додати контакт" << std::endl;
            std::cout << "2. Видалити контакт" << std::endl;
            std::cout << "3. Показати всі контакти" << std::endl;
            std::cout << "4. Зберегти у файл" << std::endl;
            std::cout << "5. Завантажити з файлу" << std::endl;
            std::cout << "6. Вийти з програми" << std::endl;

            int choice;
            std::cout << "Виберіть опцію: ";
            std::cin >> choice;

            switch (choice) {
            case 1: {
                char name[256], home[256], work[256], mobile[256], additional[256];
                std::cout << "Введіть ім'я: ";
                std::cin.ignore();
                std::cin.getline(name, 256);
                std::cout << "Введіть домашній телефон: ";
                std::cin.getline(home, 256);
                std::cout << "Введіть робочий телефон: ";
                std::cin.getline(work, 256);
                std::cout << "Введіть мобільний телефон: ";
                std::cin.getline(mobile, 256);
                std::cout << "Введіть додаткову інформацію: ";
                std::cin.getline(additional, 256);
                phoneBook.addContact(name, home, work, mobile, additional);
                break;
            }
            case 2: {
                char nameToDelete[256];
                std::cout << "Введіть ім'я контакта для видалення: ";
                std::cin.ignore();
                std::cin.getline(nameToDelete, 256);
                phoneBook.removeContact(nameToDelete);
                break;
            }
            case 3:
                std::cout << "Всі контакти:" << std::endl;
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
                std::cout << "Завершення програми." << std::endl;
                return 0;
            default:
                std::cout << "Невірний вибір. Спробуйте ще раз." << std::endl;
            }
        }

        return 0;
    }
