#include "address_book.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>


AddressBook::AddressBook() {
    loadFromFile();
}


void AddressBook::loadFromFile() {
    contacts.clear();
    std::ifstream file(dataFile);
    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        Contact c;
        std::getline(ss, c.name, '|');
        std::getline(ss, c.phone, '|');
        std::getline(ss, c.address, '|');
        std::getline(ss, c.email);
        contacts.push_back(c);
    }
}


void AddressBook::saveToFile() {
    std::ofstream file(dataFile);
    for (const auto &c : contacts) {
        file << c.name << "|" << c.phone << "|" << c.address << "|" << c.email << "\n";
    }
}


void AddressBook::addContact() {
    Contact c;
    std::cout << "请输入姓名："; std::cin >> c.name;
    std::cout << "请输入电话："; std::cin >> c.phone;
    std::cout << "请输入地址："; std::cin >> c.address;
    std::cout << "请输入邮箱："; std::cin >> c.email;
    contacts.push_back(c);
    std::cout << "添加成功！\n";
}


void AddressBook::showAllContacts() {
    if (contacts.empty()) {
        std::cout << "通讯录为空！\n";
    }
    for (const auto& c : contacts) {
        c.display();
    }
}


void AddressBook::findContact() {
    std::string keyword;
    std::cout << "请输入要查找的姓名或电话：";
    std::cin >> keyword;
    bool found = false;
    for (const auto& c : contacts) {
        if (c.name == keyword || c.phone == keyword) {
            c.display();
            found = true;
        }
    }
    if (!found) std::cout << "未找到联系人。\n";
}


void AddressBook::deleteContact() {
    std::string name;
    std::cout << "请输入要删除的联系人姓名：";
    std::cin >> name;
    // std::remove_if 会将不满足条件的元素移动到容器前部，返回指向新的逻辑末尾的迭代器
    // 这里的条件是联系人姓名 == 用户输入的姓名

    auto it = std::remove_if(contacts.begin(), contacts.end(), [&](const Contact& c) {return c.name == name;});
    if (it != contacts.end()) {
        // 如果有元素被移除，使用 erase 方法删除从 it 到容器末尾的元素
        contacts.erase(it, contacts.end());
        std::cout << "删除成功\n";
    } else {
        std::cout << "未找到联系人。\n";
    }
}


void AddressBook::modifyContact() {
    std::string name;
    std::cout << "请输入要修改的联系人姓名：";
    std::cin >> name;
    for (auto& c : contacts) {
        if (c.name == name) {
            std::cout << "修改电话："; std::cin >> c.phone;
            std::cout << "修改地址："; std::cin >> c.address;
            std::cout << "修改邮箱："; std::cin >> c.email;
            std::cout << "修改成功\n";
            return;
        }
    }
    std::cout << "未找到联系人。\n";
}


void AddressBook::clearContacts() {
    contacts.clear();
    std::cout << "通讯录已清空。\n";
}
