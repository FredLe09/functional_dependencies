#include <iostream>
#include "./class/relation.h"
#include "./func/func.h"

int main()
{
    Relation r;
    r.Input();
    system("cls");
    r.Output();

    std::cout << "How to find keys of this relation: " << std::endl;
    r.HowToFindKeys();
    std::cout << "The keys of this relation are: ";
    for (auto &it : r.getKeys())
        std::cout << "\"" << it << "\",";
    std::cout << "\b " << std::endl;
    system("pause");
    return 0;
}