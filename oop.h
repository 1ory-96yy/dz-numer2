// phonebook.h
#ifndef PHONEBOOK_H
#define PHONEBOOK_H

class Contact {
private:
    char* fullName;
    char* homePhone;
    char* workPhone;
    char* mobilePhone;
    char* additionalInfo;

public:
    Contact(const char* name, const char* home, const char* work, const char* mobile, const char* additional);
    ~Contact();
    const char* getName() const;
    void print() const;
};

class PhoneBook {
private:
    Contact** contacts;
    int size;
    int capacity;

public:
    PhoneBook();
    void addContact(const char* name, const char* home, const char* work, const char* mobile, const char* additional);
    void removeContact(const char* name);
    Contact* findContact(const char* name) const;
    void printAllContacts() const;
    void saveToFile(const char* filename) const;
    void loadFromFile(const char* filename);
    ~PhoneBook();
};

#endif
