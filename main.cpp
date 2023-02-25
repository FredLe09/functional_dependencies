#include <iostream>
#include "./class/relation.h"
#include "./func/func.h"

int main()
{
    Relation r;
    r.input();
    system("cls");
    r.process();
    r.output();

    std::cout << "How to find keys of this relation: " << std::endl;
    r.howToFindKeys();
    std::cout << "The keys of this relation are: ";
    for (auto &it : r.getKeys())
        std::cout << "\"" << it << "\",";
    std::cout << "\b " << std::endl;

    std::string first_Attr, second_Attr;
    std::cout << "Please input the first attribute dependency: ";
    std::cin >> first_Attr;
    std::cout << "Please input the second attribute dependency: ";
    std::cin >> second_Attr;

    std::cout << r.checkFDInCoverFDs(first_Attr, second_Attr) << std::endl;

    system("pause");
    return 0;
}