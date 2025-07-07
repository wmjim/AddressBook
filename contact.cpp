#include "contact.h"

void Contact::display() const {
    std::cout << "姓名：" << name << "\t"
              << "电话：" << phone << "\t"
              << "地址：" << address << "\t"
              << "邮箱：" << email << std::endl;
}


