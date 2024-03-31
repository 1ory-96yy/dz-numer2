#include "oop.h"
#include <iostream>
#include <fstream>


Contact::Contact(const char* name, const char* home, const char* work, const char* mobile, const char* additional) {
    fullName = new char[strlen(name) + 1];
    std::copy(name, name + strlen(name) + 1, fullName);
    homePhone = new char[strlen(home) + 1];
    std::copy(home, home + strlen(home) + 1, homePhone);
    workPhone = new char[strlen(work) + 1];
    std::copy(work, work + strlen(work) + 1, workPhone);
    mobilePhone = new char[strlen(mobile) + 1];
    std::copy(mobile, mobile + strlen(mobile) + 1, mobilePhone);
    additionalInfo = new char[strlen(additional) + 1];
    std::copy(additional, additional + strlen(additional) + 1, additionalInfo);
}

Contact::~Contact() {
    delete[] fullName;
    delete[] homePhone;
    delete[] workPhone;
    delete[] mobilePhone;
    delete[] additionalInfo;
}

const char* Contact::getName() const {
    return fullName;
}

void Contact::print() const {
    std::cout << "ПІБ: " << fullName << std::endl;
    std::cout << "Домашній телефон: " << homePhone << std::endl;
    std::cout << "Робочий телефон: " << workPhone << std::endl;
    std::cout << "Мобільний телефон: " << mobilePhone << std::endl;
    std::cout << "Додаткова інформація: " << additionalInfo << std::endl;
}

PhoneBook::PhoneBook() {
    size = 0;
    capacity = 10;
    contacts = new Contact * [capacity];
}

void PhoneBook::addContact(const char* name, const char* home, const char* work, const char* mobile, const char* additional) {
    if (size == capacity) {
        capacity *= 2;
        Contact** newContacts = new Contact * [capacity];
        for (int i = 0; i < size; ++i) {
            newContacts[i] = contacts[i];
        }
        delete[] contacts;
        contacts = newContacts;
    }
    contacts[size++] = new Contact(name, home, work, mobile, additional);
}

void PhoneBook::removeContact(const char* name) {
    for (int i = 0; i < size; ++i) {
        if (std::strcmp(contacts[i]->getName(), name) == 0) {
            delete contacts[i];
            for (int j = i; j < size - 1; ++j) {
                contacts[j] = contacts[j + 1];
            }
            size--;
            break;
        }
    }
}

Contact* PhoneBook::findContact(const char* name) const {
    for (int i = 0; i < size; ++i) {
        if (std::strcmp(contacts[i]->getName(), name) == 0) {
            return contacts[i];
        }
    }
    return nullptr;
}

void PhoneBook::printAllContacts() const {
    for (int i = 0; i < size; ++i) {
        contacts[i]->print();
        std::cout << std::endl;
    }
}

void PhoneBook::saveToFile(const char* filename) const {
    std::ofstream outFile(filename);
    if (outFile.is_open()) {
        for (int i = 0; i < size; ++i) {
            outFile << contacts[i]->getName() << ";" << contacts[i]->getName() << ";" << contacts[i]->getName() << ";" << contacts[i]->getName() << ";" << contacts[i]->getName() << std::endl;
        }
        outFile.close();
        std::cout << "Інформація збережена у файлі " << filename << std::endl;
    }
    else {
        std::cout << "Помилка при відкритті файлу для запису" << std::endl;
    }
}

void PhoneBook::loadFromFile(const char* filename) {
    for (int i = 0; i < size; ++i) {
        delete contacts[i];
    }
    size = 0;
    std::ifstream inFile(filename);
    if (inFile.is_open()) {
        char line[256];
        while (inFile.getline(line, sizeof(line))) {
            char name[256], home[256], work[256], mobile[256], additional[256];
            sscanf_s(line, "%255[^;];%255[^;];%255[^;];%255[^;];%255[^;]", name, sizeof(name), home, sizeof(home), work, sizeof(work), mobile, sizeof(mobile), additional, sizeof(additional));
            addContact(name, home, work, mobile, additional);
        }
        inFile.close();
        std::cout << "Інформація завантажена з файлу " << filename << std::endl;
    }
    else {
        std::cout << "Помилка при відкритті файлу для читання" << std::endl;
    }
}



PhoneBook::~PhoneBook() {
    for (int i = 0; i < size; ++i) {
        delete contacts[i];
    }
    delete[] contacts;
}
