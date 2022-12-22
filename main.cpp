#include <iostream>
#include "./class/relation.h"
#include "./func/func.h"

int main()
{
    Relation r;
    r.Input();
    system("cls");
    r.Output();

    r.HowToFindKeys();
    std::cout << "The keys of this relation are: ";
    for (auto &it : r.getKeys())
        std::cout << it << " ";
    return 0;
}