#include <iostream>
#include "address_book.h"


void showMenu() {
    std::cout << "\n===== 通讯录管理系统 =====\n";
    std::cout << "1. 添加联系人\n";
    std::cout << "2. 显示所有联系人\n";
    std::cout << "3. 查找联系人\n";
    std::cout << "4. 修改联系人\n";
    std::cout << "5. 删除联系人\n";
    std::cout << "6. 清空通讯录\n";
    std::cout << "7. 保存到文件\n";
    std::cout << "0. 退出系统\n";
    std::cout << "请输入操作编号：";
}


int main() {
    AddressBook ab;
    int choice;
    while (true) {
        showMenu();
        std::cin >> choice;
        switch (choice) {
            case 1: ab.addContact(); break;
            case 2: ab.showAllContacts(); break;
            case 3: ab.findContact(); break;
            case 4: ab.deleteContact(); break;
            case 5: ab.modifyContact(); break;
            case 6: ab.clearContacts(); break;
            case 7: ab.saveToFile(); break;
            case 0:
                ab.saveToFile();
                std::cout << "数据已保存，退出系统。\n"; 
                return 0;
            default: std::cout << "无效的操作编号！请重试。\n";
        }
    }
}