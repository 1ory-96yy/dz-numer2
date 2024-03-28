#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

class Contact {
private:
    std::string* fullName;
    std::string homePhone;
    std::string workPhone;
    std::string mobilePhone;
    std::string additionalInfo;

public:
    Contact(const std::string& name, const std::string& home, const std::string& work, const std::string& mobile, const std::string& additional);
    ~Contact();
    std::string getName() const;
    void print() const;
};

class PhoneBook {
private:
    std::vector<Contact*> contacts;

public:
    void addContact(const std::string& name, const std::string& home, const std::string& work, const std::string& mobile, const std::string& additional);
    void removeContact(const std::string& name);
    Contact* findContact(const std::string& name) const;
    void printAllContacts() const;
    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);
    ~PhoneBook();
};

#endif
