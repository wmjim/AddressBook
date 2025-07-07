#ifndef CONTACT_H
#define CONTACT_H

#include <string>
#include <iostream>

class Contact {
public:
    std::string name;
    std::string phone;
    std::string address;
    std::string email;

    void display() const;
};

#endif
