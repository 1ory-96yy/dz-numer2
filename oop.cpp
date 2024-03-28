#include "oop.h"

Contact::Contact(const std::string& name, const std::string& home, const std::string& work, const std::string& mobile, const std::string& additional)
    : homePhone(home), workPhone(work), mobilePhone(mobile), additionalInfo(additional) {
    fullName = new std::string(name);
}

Contact::~Contact() {
    delete fullName;
}

std::string Contact::getName() const {
    return *fullName;
}

void Contact::print() const {
    std::cout << "ПІБ: " << *fullName << std::endl;
    std::cout << "Домашній телефон: " << homePhone << std::endl;
    std::cout << "Робочий телефон: " << workPhone << std::endl;
    std::cout << "Мобільний телефон: " << mobilePhone << std::endl;
    std::cout << "Додаткова інформація: " << additionalInfo << std::endl;
}

void PhoneBook::addContact(const std::string& name, const std::string& home, const std::string& work, const std::string& mobile, const std::string& additional) {
    contacts.push_back(new Contact(name, home, work, mobile, additional));
}

void PhoneBook::removeContact(const std::string& name) {
    for (auto it = contacts.begin(); it != contacts.end(); ++it) {
        if ((*it)->getName() == name) {
            delete* it;
            contacts.erase(it);
            break;
        }
    }
}

Contact* PhoneBook::findContact(const std::string& name) const {
    for (auto contact : contacts) {
        if (contact->getName() == name) {
            return contact;
        }
    }
    return nullptr;
}

void PhoneBook::printAllContacts() const {
    for (auto contact : contacts) {
        contact->print();
        std::cout << std::endl;
    }
}

void PhoneBook::saveToFile(const std::string& filename) const {
    std::ofstream outFile(filename);
    if (outFile.is_open()) {
        for (auto contact : contacts) {
            outFile << contact->getName() << ";" << contact->getName() << ";" << contact->getName() << ";" << contact->getName() << ";" << contact->getName() << std::endl;
        }
        outFile.close();
        std::cout << "Інформація збережена у файлі " << filename << std::endl;
    }
    else {
        std::cout << "Помилка при відкритті файлу для запису" << std::endl;
    }
}

void PhoneBook::loadFromFile(const std::string& filename) {
    contacts.clear();
    std::ifstream inFile(filename);
    if (inFile.is_open()) {
        std::string line;
        while (getline(inFile, line)) {
            std::string name, home, work, mobile, additional;
            size_t pos = 0;
            pos = line.find(";");
            name = line.substr(0, pos);
            line.erase(0, pos + 1);
            pos = line.find(";");
            home = line.substr(0, pos);
            line.erase(0, pos + 1);
            pos = line.find(";");
            work = line.substr(0, pos);
            line.erase(0, pos + 1);
            pos = line.find(";");
            mobile = line.substr(0, pos);
            line.erase(0, pos + 1);
            additional = line;
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
    for (auto contact : contacts) {
        delete contact;
    }
}
