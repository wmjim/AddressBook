#ifndef ADDRESS_BOOK_H
#define ADDRESS_BOOK_H

#include <vector>
#include <string>
#include "contact.h"

class AddressBook {
public:
    AddressBook();

    void loadFromFile();
    void saveToFile();

    void addContact();
    void showAllContacts();
    void findContact();
    void deleteContact();
    void modifyContact();
    void clearContacts();

private:
    std::vector<Contact> contacts;
    std::string dataFile = "contacts.txt";
};

#endif